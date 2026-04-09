#include <iostream>
#include <cmath>
using namespace std;

class my_Vector {
private:
    int x;
    int y;

public:
    // TODO: set function
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }

    // TODO: print function
    void print() const {
        cout << x << ' ' << y << endl;
    }

    // TODO: addition
    my_Vector add(const my_Vector& v) const {
        my_Vector result;
        result.set(x + v.x, y + v.y);

        return result;
    }

    // TODO: subtraction
    my_Vector sub(const my_Vector& v) const {
        my_Vector result;
        result.set(x - v.x, y - v.y);

        return result;
    }

    // TODO: norm
    double norm() const {
        double result = sqrt(pow(x, 2) + pow(y, 2));

        return result;
    }
};

int main() {
    cout << fixed;
    cout.precision(1);
    my_Vector A, B;
    int temp_x, temp_y;
    cin >> temp_x >> temp_y;
    A.set(temp_x, temp_y);
    cin >> temp_x >> temp_y;
    B.set(temp_x, temp_y);

    my_Vector result = A.add(B);
    result.print();
    result = A.sub(B);
    result.print();
    cout << A.norm();

    return 0;
}