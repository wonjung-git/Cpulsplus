#include <iostream>
using namespace std;

class Date {
private:
    int year, month, day;

public:
    void setDate(int y, int m, int d) {
        // to do : exception handling for year and month

        int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        if (isLeapYear(y)) {
            daysInMonth[1] = 29;
        }

        // to do : exception handling for day
        if (y <= 0) {
            throw "Invalid year.";
        }
        if (m < 1 || 12 < m) {
            throw "Invalid month.";
        }
        if (d < 1 || daysInMonth[m-1] < d) {
            throw "Invalid day.";
        }

        year = y;
        month = m;
        day = d;
    }

    bool isLeapYear(int y) {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
            return true;
        else return false;
    }

    int getDayOfYear() {
        int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        if (isLeapYear(year)) {
            daysInMonth[1] = 29;
        }

        int result = 0;
        for (int i = 0; i < month-1; i++) {
            for (int j = 0; j < daysInMonth[i]; j++) {
                result++;
            }
        }
        result += day;

        return result;
    }
};

int main() {
    int y, m, d;

    try {
        cin >> y >> m >> d;
        Date date;
        date.setDate(y, m, d);
        cout << date.getDayOfYear() << "\n";
    }
    catch (const char* msg) {
        cout << msg << "\n";
    }

    return 0;
}
