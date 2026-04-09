#include <iostream>
using namespace std;

void mystrcpy(char *s, char *d) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        d[i] = s[i];
    d[i] = '\0';
}

int mystrlen(char* s) {
    int i=0;
    while (s[i] != '\0') i++;
    return i;
}

template <typename T>
class S {
private:
    T arr[10000];
    int topIdx;

public:
    S() {
        topIdx = -1;
    }

    void push(T x) {
        topIdx++;
        arr[topIdx] = x;
    }

    void pop() {
        arr[topIdx] = 0;
        topIdx--;
    }

    T top() {
        return arr[topIdx];
    }

    bool empty() {
        if (topIdx == -1) return 1;
        else return 0;
    }
};

class VariableTable {
private:
    char names[1000][50];
    int values[1000];
    int count;

    int same(char a[], char b[]) {
        int i = 0;
        while (a[i] != '\0' && a[i] != '\0') {
            if (a[i] != b[i]) return 0;
            i++;
        }
        if (a[i] != '\0' || b[i] != '\0') return 0;
        return 1;
    }

public:
    VariableTable() {
        count = 0;
    }

    int get(char name[]) {
        for (int i = 0; i < count; i++) {
            if (same(names[i], name)) return values[i];
        }
        return 0;
    }

    void set(char name[], int value) {
        int flag = 1;
        for (int i = 0; i < count; i++) {
            if (same(names[i], name)) {
                values[i] = value;
                flag = 0;
                break;
            }
        }
        if (flag) {
            mystrcpy(name, names[count]);
            values[count] = value;
            count++;
        }
    }
};

class Calculator {
private:
    VariableTable vars;

    int isDigit(char c) {
        if ('0' <= c && c <= '9') return 1;
        else return 0;
    }

    int isLower(char c) {
        if ('a' <= c && c <= 'z') return 1;
        else return 0;
    }

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        else if (op == '*' || op == '/' || op == '%') return 2;
        else if (op == '~') return 3;
        return 0;
    }

    int isRightAssociative(char op) {
        if (op == '~') return 1;
        else return 0;
    }

    void applyOp(S<int>* values, char op) {
        int a, b;
        if (op == '~') {
            b = values->top();
            values->pop();
            values->push(-1 * b);
        }
        else {
            b = values->top();
            values->pop();
            a = values->top();
            values->pop();

            switch (op) {
            case '+':
                values->push(a + b);
                break;
            case '-':
                values->push(a - b);
                break;
            case '*':
                values->push(a * b);
                break;
            case '/':
                if (b == 0)values->push(0);
                else values->push(a / b);
                break;
            case '%':
                if (b == 0)values->push(0);
                else values->push(a % b);
                break;
            }
        }
    }

    void removeSpaces(char src[], char dst[]) {
        int j = 0;
        for (int i = 0; src[i] != '\0'; i++) {
            if (src[i] != ' ' && src[i] != '\t') {
                dst[j++] = src[i];
            }
        }
        dst[j] = '\0';
    }

    int isVariableName(char s[]) {
        int i=0, len = mystrlen(s);
        while (i<len) {
            if ('a' > s[i] || 'z' < s[i]) return 0;
            i++;
        }
        return 1;
    }

    int evaluateExpression(char expr[]) {
        S<int> values;
        S<char> ops;

        int i = 0;
        int expectOperand = 1;

        while (expr[i] != '\0') {
            char ch = expr[i];

            // 숫자인가?
            if (isDigit(ch)) {
                int num = 0;
                while (isDigit(expr[i])) {
                    num = num*10 + (expr[i] - '0');
                    i++;
                }
                values.push(num);
                expectOperand = 0;
            }
            // 변수인가?
            else if (isLower(ch)) {
                char name[50];
                int idx = 0;

                while (isLower(expr[i])) {
                    name[idx] = expr[i];
                    idx++;
                    i++;
                }
                name[idx] = '\0';

                values.push(vars.get(name));
                expectOperand = 0;
            }
            // ()인가?
            else if (ch == '(') {
                ops.push('(');
                i++;
            }
            else if (ch == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    char op = ops.top();
                    ops.pop();
                    applyOp(&values, op);
                }
                if (!ops.empty()) {
                    ops.pop();
                }
                i++;
                expectOperand = 0;
            }
            // 연산자인가?
            else {
                char curOp;
                if (ch == '-' && expectOperand) curOp = '~';
                else curOp = ch;

                while (!ops.empty() && ops.top() != '(') {
                    char topOp = ops.top();
                    int pTop = precedence(topOp);
                    int pCur = precedence(curOp);

                    if (pTop > pCur || (pTop == pCur && !isRightAssociative(curOp))) {
                        applyOp(&values, topOp);
                        ops.pop();
                    }
                    else {
                        break;
                    }
                }

                ops.push(curOp);
                i++;
                expectOperand = 1;
            }
        }

        while (!ops.empty()) {
            char op = ops.top();
            ops.pop();
            applyOp(&values, op);
        }

        if (values.empty()) return 0;
        return values.top();
    }

public:
    void processLine(char line[]) {
        char expr[1000];
        removeSpaces(line, expr);

        int eq = -1;
        int depth = 0;

        // = 위치 파악
        for (int i = 0; expr[i] != '\0'; i++) {
            if (expr[i] == '(') depth++;
            else if (expr[i] == ')') depth--;
            else if (expr[i] == '=' && depth == 0) {
                eq = i;
                break;
            }
        }

        // 변수할당식
        if (eq != -1) {
            char lhs[50];
            char rhs[1000];

            // 변수
            int i = 0;
            while (i < eq) {
                lhs[i] = expr[i];
                i++;
            }
            lhs[i] = '\0';

            // 수식
            int j = 0;
            for (int k = eq + 1; expr[k] != '\0'; k++) {
                rhs[j] = expr[k];
                j++;
            }
            rhs[j] = '\0';

            if (isVariableName(lhs)) {
                int result = evaluateExpression(rhs);
                vars.set(lhs, result);
                cout << lhs << " = " << result << '\n';
            }
            else {
                cout << evaluateExpression(expr) << '\n';
            }
        }
        //일반수식
        else {
            cout << evaluateExpression(expr) << '\n';
        }
    }

    int isExit(char line[]) {
        char expr[1000];
        removeSpaces(line, expr);

        return expr[0] == 'e' &&
            expr[1] == 'x' &&
            expr[2] == 'i' &&
            expr[3] == 't' &&
            expr[4] == '\0';
    }
};

int main() {
    Calculator calc;
    char line[1000];

    while (true) {
        cin.getline(line, 1000);

        if (calc.isExit(line)) {
            break;
        }

        calc.processLine(line);
    }

    return 0;
}
