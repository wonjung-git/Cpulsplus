#include <iostream>
using namespace std;

class Account {
private:
    int balance;

public:
    Account(int b = 0) {
        balance = b;
    }

    Account operator+(int x) const {
        int sum = balance + x;

        return Account (sum);
    }

    Account operator-(int x) const {
        int sum = balance - x;

        return Account(sum);
    }

    int getBalance() const {
        return balance;
    }
};

int main() {
    int init;
    cin >> init;

    Account acc(init);

    while (true) {
        string cmd;
        cin >> cmd;

        if (cmd == "exit") {
            break;
        }
        else if (cmd == "deposit") {
            int x;
            cin >> x;

            if (x < 0) 
                cout << "error" << endl;
            else
                acc = acc + x;
        }
        else if (cmd == "withdraw") {
            int x;
            cin >> x;

            if (x < 0 || x > acc.getBalance())
                cout << "error" << endl;
            else
                acc = acc - x;
        }
        else if (cmd == "check") {
            cout << acc.getBalance() << endl;
        }
    }

    return 0;
}
