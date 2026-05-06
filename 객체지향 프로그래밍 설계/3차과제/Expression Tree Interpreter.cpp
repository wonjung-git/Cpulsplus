#include <iostream>
#include <string>
using namespace std;

class Expr {
public:
    virtual ~Expr() {}

    virtual int eval(const int values[], const int assigned[], int& ok) const = 0;
    virtual int count() const = 0;
    virtual int height() const = 0;
    virtual void printPrefix(int& first) const = 0;
    virtual void printPostfix(int& first) const = 0;
    virtual void printInfix() const = 0;
};

class NumberExpr : public Expr {
private:
    int value;

public:
    NumberExpr(int value) : value(value) {}

    int eval(const int values[], const int assigned[], int& ok) const {
        return value;
    }

    int count() const {
        return 1;
    }

    int height() const {
        return 1;
    }

    void printPrefix(int& first) const {
        if (!first) cout << " ";
        cout << value;
        first = 0;
    }

    void printPostfix(int& first) const {
        if (!first) cout << " ";
        cout << value;
        first = 0;
    }

    void printInfix() const {
        cout << value;
    }
};

class VariableExpr : public Expr {
private:
    char name;

public:
    VariableExpr(char name) : name(name) {}

    int eval(const int values[], const int assigned[], int& ok) const {
        int idx = name - 'a';
        if (assigned[idx])
            return values[idx];
        else ok = 0;

        return 0;
    }

    int count() const {
        return 1;
    }

    int height() const {
        return 1;
    }

    void printPrefix(int& first) const {
        if (!first) cout << " ";
        cout << name;
        first = 0;
    }

    void printPostfix(int& first) const {
        if (!first) cout << " ";
        cout << name;
        first = 0;
    }

    void printInfix() const {
        cout << name;
    }
};

class BinaryExpr : public Expr {
private:
    char op;
    Expr* left;
    Expr* right;

public:
    BinaryExpr(char op, Expr* left, Expr* right)
        : op(op), left(left), right(right) {
    }

    virtual ~BinaryExpr() {
        delete left;
        delete right;
    }

    int eval(const int values[], const int assigned[], int& ok) const {
        int result = 0;

        switch (op) {
        case '+':
            result = left->eval(values, assigned, ok) + right->eval(values, assigned, ok);
            return result;
        case '-':
            result = left->eval(values, assigned, ok) - right->eval(values, assigned, ok);
            return result;
        case '*':
            result = left->eval(values, assigned, ok) * right->eval(values, assigned, ok);
            return result;
        case '/':
            if (right->eval(values, assigned, ok) == 0) {
                ok = 0;
                return 0;
            }
            result = left->eval(values, assigned, ok) / right->eval(values, assigned, ok);
            return result;
        }

        return 0;
    }

    int count() const {
        int result = 0;
        result = left->count() + right->count() + 1;
        return result;

        return 0;
    }

    int height() const {
        if (left->height() > right->height())
            return left->height() + 1;
        else return right->height() + 1;

        return 0;
    }

    void printPrefix(int& first) const {
        if (!first) cout << " ";
        cout << op;
        first = 0;
        left->printPrefix(first);
        right->printPrefix(first);
    }

    void printPostfix(int& first) const {
        left->printPostfix(first);
        right->printPostfix(first);
        if (!first) cout << " ";
        cout << op;
    }

    void printInfix() const {
        cout << "( ";
        left->printInfix();
        cout << ' ' << op << ' ';
        right->printInfix();
        cout << " )";
    }
};

class Interpreter {
private:
    Expr* root;
    int values[26];
    int assigned[26];

    int isDigit(char c) const {
        return c >= '0' && c <= '9';
    }

    int isLower(char c) const {
        return c >= 'a' && c <= 'z';
    }

    int isOperator(char c) const {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    int precedence(char c) const {
        if (c == '+' || c == '-')
            return 1;
        if (c == '*' || c == '/')
            return 2;
        return 0;
    }

    void deleteStackNodes(Expr** stack, int top) {
        for (int i = 0; i <= top; i++) {
            delete stack[i];
        }
    }

    int infixToPostfix(const string& expr, string postfix[], int& postfixCount) {
        char opStack[2001];
        int top = -1;
        postfixCount = 0;

        if (expr.empty()) return 0;

        int i = 0;
        int expectOperand = 1;

        while (i < (int)expr.size()) {
            char c = expr[i];

            if (isDigit(c)) {
                if (!expectOperand) return 0;

                string num = "";
                while (i < (int)expr.size() && isDigit(expr[i])) {
                    num += expr[i];
                    ++i;
                }
                postfix[postfixCount++] = num;
                expectOperand = 0;
                continue;
            }
            else if (isLower(c)) {
                if (!expectOperand)
                    return 0;
                
                postfix[postfixCount++] = c;
                i++;
                expectOperand = 0;
            }
            else if (c == '(') {
                if (!expectOperand)
                    return 0;

                opStack[++top] = c;
                i++;
                expectOperand = 1;
            }
            else if (c == ')') {
                if (expectOperand)
                    return 0;

                int flag = 0;
                while (top > -1) {
                    if (opStack[top] == '(') {
                        flag = 1;
                        top--;
                        break;
                    }

                    postfix[postfixCount++] = opStack[top];
                    top--;
                }

                if (!flag)
                    return 0;

                expectOperand = 0;
                i++;
            }
            else if (isOperator(c)) {
                if (expectOperand)
                    return 0;

                while (top > -1 && precedence(opStack[top]) >= precedence(c) && opStack[top] != '(') {
                    postfix[postfixCount++] = opStack[top--];
                }
                
                opStack[++top] = c;
                i++;
                expectOperand = 1;
            }
            else {
                return 0;
            }
        }

        if (expectOperand)
            return 0;

        while (top > -1) {
            if (opStack[top] == '(' || opStack[top] == ')') {
                return 0;
            }

            postfix[postfixCount++] = opStack[top];
            top--;
        }

        return 1;
    }

    Expr* buildTreeFromPostfix(string postfix[], int postfixCount) {
        Expr* stack[2001];
        int top = -1;

        for (int i = 0; i < postfixCount; i++) {
            string temp = postfix[i];

            if (temp.size() == 1 && isLower(temp[0])) {
                stack[++top] = new VariableExpr(temp[0]);
            }
            else if (temp.size() == 1 && isOperator(temp[0])) {
                if (top < 1) {
                    deleteStackNodes(stack, top);
                    return NULL;
                }

                Expr* right = stack[top--];
                Expr* left = stack[top--];

                stack[++top] = new BinaryExpr(temp[0], left, right);
            }
            else {
                int flag = 1;
                for (int j = 0; j < temp.size(); j++) {
                    if (!isDigit(temp[j])) {
                        flag = 0;
                        break;
                    }
                }

                if (!flag || temp.empty()) {
                    deleteStackNodes(stack, top);
                    return NULL;
                }

                stack[++top] = new NumberExpr(stoi(temp));
            }
        }
        if (top != 0) {
            deleteStackNodes(stack, top);
            return NULL;
        }

        return stack[0];
    }

public:
    Interpreter() {
        int i;
        root = NULL;
        for (i = 0; i < 26; ++i) {
            values[i] = 0;
            assigned[i] = 0;
        }
    }

    ~Interpreter() {
        delete root;
    }

    void setVariable(char var, int value) {
        int idx = var - 'a';
        values[idx] = value;
        assigned[idx] = 1;
    }

    int build(const string& expr) {
        string postfix[2001];
        int postfixCount = 0;

        if (!infixToPostfix(expr, postfix, postfixCount))
            return 0;

        Expr* temp = buildTreeFromPostfix(postfix, postfixCount);

        if (temp == NULL)
            return 0;

        delete root;
        root = temp;

        return 1;
    }

    int eval(int& result) const {
        if (root == NULL) return 0;

        int ok = 1;
        result = root->eval(values, assigned, ok);
        return ok;
    }

    int printPrefix() const {
        int first = 1;
        if (root != NULL) {
            root->printPrefix(first);
            cout << endl;
            return 1;
        }

        return 0;
    }

    int printPostfix() const {
        int first = 1;
        if (root != NULL) {
            root->printPostfix(first);
            cout << endl;
            return 1;
        }

        return 0;
    }

    int printInfix() const {
        if (root != NULL) {
            root->printInfix();
            cout << endl;
            return 1;
        }

        return 0;
    }

    int count(int& result) const {
        if (root == NULL) return 0;
        result = root->count();
        return 1;
    }

    int height(int& result) const {
        if (root == NULL) return 0;
        result = root->height();
        return 1;
    }

    void clear() {
        delete root;
        root = NULL;
    }
};

int main() {
    Interpreter interpreter;

    int Q;
    cin >> Q;

    int i;
    for (i = 0; i < Q; ++i) {
        string cmd;
        cin >> cmd;

        if (cmd == "SET") {
            string var;
            int value;
            cin >> var >> value;
            interpreter.setVariable(var[0], value);
        }
        else if (cmd == "BUILD") {
            string expr;
            getline(cin, expr);
            while (!expr.empty() && expr[0] == ' ') expr.erase(0, 1);
            if (!interpreter.build(expr)) {
                cout << "ERROR\n";
            }
        }
        else if (cmd == "EVAL") {
            int result;
            if (interpreter.eval(result)) cout << result << "\n";
            else cout << "ERROR\n";
        }
        else if (cmd == "PREFIX") {
            if (!interpreter.printPrefix()) cout << "ERROR\n";
        }
        else if (cmd == "POSTFIX") {
            if (!interpreter.printPostfix()) cout << "ERROR\n";
        }
        else if (cmd == "INFIX") {
            if (!interpreter.printInfix()) cout << "ERROR\n";
        }
        else if (cmd == "COUNT") {
            int result;
            if (interpreter.count(result)) cout << result << "\n";
            else cout << "ERROR\n";
        }
        else if (cmd == "HEIGHT") {
            int result;
            if (interpreter.height(result)) cout << result << "\n";
            else cout << "ERROR\n";
        }
        else if (cmd == "CLEAR") {
            interpreter.clear();
        }
    }

    return 0;
}
