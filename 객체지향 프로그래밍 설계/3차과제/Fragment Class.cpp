#include <iostream>
#include <string>
using namespace std;

class Fragment {
private:
    string str;

public:
    Fragment(string s = "") : str(s) {}

    Fragment operator+(const Fragment& other) const {
        string temp = str + other.str;
        Fragment result(temp);

        return result;
    }

    Fragment operator-(const Fragment& other) const {
        if (other.str.size() > str.size())
            throw "error";

        string result = str;
        bool flag = 1;
        for (int i = 0, j = str.size() - other.str.size(); j < str.size(); i++, j++) {
            if (str[j] != other.str[i]) {
                flag = false;
            }
        }
        
        if (flag) {
            result.erase(str.size() - other.str.size(), str.size());
            return Fragment(result);
        }
        else
            throw "error";
    }

    bool operator==(const Fragment& other) const {
        int len = str.size();
        string a = str, b = other.str;

        if (len != b.size())
            return false;
        else {
            //전체 소문자로 변환 후 같은지 확인
            for (int i = 0; i < len; i++) {
                if (96 < a[i] && a[i] < 123)
                    a[i] -= 32;
                if (96 < b[i] && b[i] < 123)
                    b[i] -= 32;
                if (a[i] != b[i])
                    return false;
            }

            return true;
        }
        
    }

    void print() const {
        cout << str << endl;
    }
};

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string cmd, s1, s2;
        cin >> cmd >> s1 >> s2;

        Fragment f1(s1), f2(s2);

        if (cmd == "add") {
            Fragment result = f1 + f2;
            result.print();
        }
        else if (cmd == "remove") {
            try{
                Fragment result = f1 - f2;
                result.print();
            }
            catch(const char* e){
                cout << e << endl;
            }
        }
        else if (cmd == "compare") {
            if (f1 == f2)
                cout << "equal" << endl;
            else 
                cout << "not equal" << endl;
        }
    }

    return 0;
}


