#include <iostream>
using namespace std;

class Range {
private:
    int start;
    int end;

public:
    Range(int s = 0, int e = 0) {
        start = s;
        end = e;
    }

    Range operator+(const Range& other) const {
        int new_start, new_end;

        if (end < other.start || other.end < start)
            return Range(1, 0);

        //start何盒
        if (other.start < start) {
            new_start = other.start;
        }
        else {
            new_start = start;
        }

        //end何盒
        if (other.end < end) {
            new_end = end;
        }
        else {
            new_end = other.end;
        }

        Range result(new_start, new_end);

        return result;
    }

    Range operator*(const Range& other) const {
        int new_start, new_end;

        //start何盒
        if (other.start < start) {
            new_start = start;
        }
        else {
            new_start = other.start;
        }

        //end何盒
        if (other.end < end) {
            new_end = other.end;
        }
        else {
            new_end = end;
        }

        Range result(new_start, new_end);

        return result;
    }

    void print() const {

        if (start == end) {
            cout << "[" << start << "]" << endl;
        }
        else {
            cout << "[" << start << ", " << end << "]" << endl;
        }
    }

    bool isValid() const { //use this function to print
        return start <= end;
    }
};

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string cmd;
        int a, b, c, d;
        cin >> cmd >> a >> b >> c >> d;

        Range r1(a, b);
        Range r2(c, d);

        if (cmd == "add") {
            Range result = r1 + r2;

            if (result.isValid()) {
                result.print();
            }
            else
                cout << "no intersection" << endl;
            
        }
        else if (cmd == "intersect") {
            Range result = r1 * r2;

            if (result.isValid()) {
                result.print();
            }
            else
                cout << "no intersection" << endl;
        }
    }

    return 0;
}
