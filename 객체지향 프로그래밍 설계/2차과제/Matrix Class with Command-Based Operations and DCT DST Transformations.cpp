
#include <iostream>
using namespace std;

#define PI 3.141593

double mypow(double x, int n) {
    double result = 1;
    for (int i = 0; i < n; i++)
        result *= x;
    return result;
}

long long int myfactorial(int n) {
    if (n==0 || n == 1) return 1;
    long long int result = n;
    result *= myfactorial(n - 1);
    return result;
}

double myAbs(double x) {
    if (x < 0)
        return x * -1;
    else return x;
}

double myCos(double x) {
    while (x > 2 * PI) x -= 2 * PI;
    while (x < -2 * PI) x += 2 * PI;

    double term = 1.0;
    double sum = 1.0;
    for (int i = 1; i <= 12; i++) {
        term = term * (-1.0) * x * x / ((2 * i - 1) * (2 * i));
        sum += term;
    }
    return sum;
}

double mySin(double x) {
    while (x > 2 * PI) x -= 2 * PI;
    while (x < -2 * PI) x += 2 * PI;

    double term = x;
    double sum = x;
    for (int i = 1; i <= 12; i++) {
        term = term * (-1.0) * x * x / ((2 * i) * (2 * i + 1));
        sum += term;
    }
    return sum;
}

double mySqrt(double x) {
    if (x == 0.0) return 0.0;
    double r = x;
    for (int i = 0; i < 25; i++) {
        r = (r + x / r) / 2.0;
    }
    return r;
}

class Matrix {
private:
    int rows;
    int cols;
    double** data;

    void allocate(int r, int c) {
        data = new double* [r];
        for (int i = 0; i < r; i++)
            data[i] = new double[c];
    }

public:
    Matrix() {
        rows = 0;
        cols = 0;
        data = NULL;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

    void clear() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;

        data = NULL;
        rows = 0;
        cols = 0;
    }

    void setSize(int r, int c) {
        if (data != NULL) clear();
        allocate(r, c);
        rows = r;
        cols = c;
    }

    int getRows() {
        return rows;
    }

    int getCols() {
        return cols;
    }

    double get(int r, int c) {
        return data[r][c];
    }

    void setValue(int r, int c, double v) {
        data[r][c] = v;
    }

    void input() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    void printNumber(double x) {
        if (myAbs(x) < 0.0000005) x = 0.0;

        long long scaled;
        if (x >= 0) scaled = (long long)(x * 1000000 + 0.5);
        else scaled = (long long)(x * 1000000 - 0.5);

        long long integerPart = scaled / 1000000;
        long long fracPart = scaled % 1000000;
        if (fracPart < 0) fracPart = -fracPart;

        cout << integerPart << ".";
        long long p = 100000;
        while (p > 0) {
            cout << fracPart / p;
            fracPart %= p;
            p /= 10;
        }
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printNumber(data[i][j]);
                if (j != cols - 1) cout << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }

    void transpose() {
        Matrix result;
        int r_rows = cols, r_cols = rows;
        result.setSize(r_rows, r_cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.setValue(j, i, this->get(i, j));
        this->setSize(r_rows, r_cols);

        for (int i = 0; i < r_rows; i++)
            for (int j = 0; j < r_cols; j++)
                this->setValue(i, j, result.get(i, j));
    }

    void dct() {
        Matrix result;
        result.setSize(rows, cols);
        for (int u = 0; u < rows; u++) {
            for (int v = 0; v < cols; v++) {
                //여기부터 계산
                double sum = 0;
                for (int x = 0; x < rows; x++) {
                    for (int y = 0; y < cols; y++) {
                        sum += data[x][y] * myCos((PI * (2*x + 1) * u) / (2*rows)) * myCos((PI * (2*y + 1) * v) / (2*cols));
                    }
                }
                if (u == 0) sum = sum*mySqrt(static_cast<double>(1) / rows);
                else sum = sum * mySqrt(static_cast<double>(2) / rows);
                if (v == 0) sum = sum * mySqrt(static_cast<double>(1) / cols);
                else sum = sum * mySqrt(static_cast<double>(2) / cols);

                result.setValue(u, v, sum);
            }
        }

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                this->setValue(i, j, result.get(i, j));
    }

    void dst() {
        Matrix result;
        result.setSize(rows, cols);
        for (int u = 0; u < rows; u++) {
            for (int v = 0; v < cols; v++) {
                //여기부터 계산
                double sum = 0;
                for (int x = 0; x < rows; x++) {
                    for (int y = 0; y < cols; y++) {
                        sum += data[x][y] * mySin((PI * (x + 1) * (u + 1)) / (rows + 1)) * mySin((PI * (y + 1) * (v + 1)) / (cols + 1));
                    }
                }
                result.setValue(u, v, sum);
            }
        }
        
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                this->setValue(i, j, result.get(i, j));
    }
};

class MatrixProgram {
private:
    Matrix A;
    Matrix B;

    Matrix* choose(char name) {
        if (name == 'A') return &A;
        else if (name == 'B') return &B;
        else return NULL;
    }

public:
    void run() {
        char cmd[20];   

        while (true) {
            cin >> cmd;

            if (cmd[0] == 'e' && cmd[1] == 'x' && cmd[2] == 'i' && cmd[3] == 't' && cmd[4] == '\0') {
                cout << "Program terminated!\n";
                break;
            }

            if (cmd[0] == 's' && cmd[1] == 'e' && cmd[2] == 't' && cmd[3] == 's') {
                char x;
                int r, c;
                cin >> x >> r >> c;
                Matrix* target = choose(x);
                target->setSize(r, c);
            }
            else if (cmd[0] == 's' && cmd[1] == 'e' && cmd[2] == 't' && cmd[3] == 'm') {
                char x;
                cin >> x;
                Matrix* target = choose(x);
                target->input();
            }
            else if (cmd[0] == 'a' && cmd[1] == 'd' && cmd[2] == 'd' && cmd[3] == '\0') {
                Matrix result;
                int rows = A.getRows(), cols = A.getCols();
                result.setSize(rows, cols);
                
                for (int i = 0; i < cols; i++) {
                    for (int j = 0; j < rows; j++) {
                        double sum = A.get(j, i) + B.get(j, i);
                        result.setValue(j, i, sum);
                    }
                }

                result.print();
            }
            else if (cmd[0] == 'm' && cmd[1] == 'u' && cmd[2] == 'l' && cmd[3] == '\0') {
                Matrix result;
                int A_cols = A.getCols(), A_rows = A.getRows(), B_cols = B.getCols(), B_rows = B.getRows();
                result.setSize(A_rows, B_cols);

                for (int i = 0; i < A_rows; i++) {
                    for (int j = 0; j < B_cols; j++) {
                        double temp = 0;
                        for (int k = 0; k < A_cols; k++) {
                            temp += A.get(i, k) * B.get(k, j);
                        }
                        result.setValue(i, j, temp);
                    }
                }

                result.print();
            }
            else if (cmd[0] == 't') {
                char x;
                cin >> x;
                Matrix* target = choose(x);
                target->transpose();
                target->print();
            }
            else if (cmd[0] == 's' && cmd[1] == 'e' && cmd[2] == 't' && cmd[3] == '\0') {
                char x;
                int r, c;
                double v;
                cin >> x >> r >> c >> v;
                Matrix* target = choose(x);
                target->setValue(r, c, v);
            }
            else if (cmd[0] == 'p') {
                char x;
                cin >> x;
                Matrix* target = choose(x);
                target->print();
            }
            else if (cmd[0] == 'd' && cmd[1] == 'c') {
                char x;
                cin >> x;
                Matrix* target = choose(x);
                target->dct();
                target->print();
            }
            else if (cmd[0] == 'd' && cmd[1] == 's') {
                char x;
                cin >> x;
                Matrix* target = choose(x);
                target->dst();
                target->print();
            }
        }
    }
};

int main() {
    MatrixProgram program;
    program.run();
    return 0;
}

