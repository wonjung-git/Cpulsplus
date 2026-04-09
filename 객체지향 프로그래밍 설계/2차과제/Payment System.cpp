#include <iostream>
using namespace std;

class Payment {
public:
    virtual int pay(int amount) const {
        return amount;
    }

    virtual ~Payment() {}
};

class Cash : public Payment {
public:
    int pay(int amount) const override {
        return amount;
    }
};

class Card : public Payment {
public:
    int pay(int amount) const override {
        return amount * 1.1;
    }
};

class Discount : public Payment {
public:
    int pay(int amount) const override {
        return amount * 0.8;
    }
};

int strlen(char* s) {
    int len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

int main() {
    int m;
    char type[9];
    cin >> type;
    cin >> m;
    Payment* amount = NULL;

    switch (type[strlen(type) - 1]) {
    case 'h': 
        amount = new Cash();
        break;
    case 'd':
        amount = new Card;
        break;
    case 't':
        amount = new Discount;
        break;
    default:
        cout << "Error";
    }
    
    cout << amount->pay(m);
}