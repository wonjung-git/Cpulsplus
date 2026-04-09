#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class TextPiece {
private:
    char* str;

public:
    TextPiece(const char* s = "") {
        int len = strlen(s);
        str = new char[len+1];
        strcpy(str, s);
    }

    ~TextPiece() {
        delete[] str;
    }

    TextPiece& operator=(const TextPiece& other) {
        delete[] str;
        int len = strlen(other.str);
        str = new char[len + 1];
        strcpy(str, other.str);

        return *this;
    }

    TextPiece operator+(const TextPiece& other) const {
        TextPiece sum;
        char temp[101];
        strcpy(temp, str);
        strcat(temp, " ");
        strcat(temp, other.str);
        sum = TextPiece(temp);
        return sum;
    }

    bool operator==(const TextPiece& other) const {
        bool r = strcmp(str, other.str) == 0;
        return r;
    }

    friend ostream& operator<<(ostream& os, const TextPiece& s) {
        os << s.str;
        return os;
    }
};

int main() {
    char c;
    string temp;
    getline(cin, temp);
    TextPiece first = TextPiece(temp.c_str());
    getline(cin, temp);
    TextPiece second = TextPiece(temp.c_str());

    TextPiece result;

    while (1) {
        getline(cin, temp);

        switch (temp[0]) {
        case 'a':
            result = first + second;
            cout << result << endl;
            break;
        case 'c':
            if (first == second) cout << "Same" << endl; 
            else cout << "Different" << endl;
            break;
        case 'l':
            getline(cin, temp);
            result = TextPiece(temp.c_str());
            first = result;
            break;
        case 'r':
            getline(cin, temp);
            result = TextPiece(temp.c_str());
            second = result;
            break;
        case 'q':
            cout << "Finished!";
            return 0;
        default: cout << "Error";
        }
    }

    return 0;
}