#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int arr[20];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool isEmpty() {
        if (topIndex == -1) return 1;
        else return 0;
    }

    bool isFull() {
        if (topIndex == 19) return 1;
        else return 0;
    }

    void push(int x) {
        if (!isFull()) arr[++topIndex] = x;
        else cout << "full!" << endl;
    }

    void pop() {
        if (!isEmpty()) cout << arr[topIndex--] << endl;
        else cout << "empty!" << endl;
    }

    void front() {
        if (!isEmpty()) cout << arr[topIndex] << endl;
        else cout << "empty!" << endl;
    }

    void size() {
        cout << topIndex + 1 << endl;
    }

    void empty() {
        if (!isEmpty()) cout << "not empty!" << endl;
        else cout << "empty!" << endl;
    }
};

class Queue {
private:
    int arr[20];
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool isEmpty() {
        if (count == 0) return 1;
        else return 0;
    }

    bool isFull() {
        if (rearIndex == 19) return 1;
        else return 0;
    }

    void push(int x) {
        if (!isFull()) {
            arr[++rearIndex] = x;
            count++;
        }
        else cout << "full!" << endl;
        
    }

    void pop() {
        if (!isEmpty()) {
            cout << arr[frontIndex++] << endl;
            count--;
        }
        else cout << "empty!" << endl;
    }

    void front() {
        if (!isEmpty()) cout << arr[frontIndex] << endl;
        else cout << "empty!" << endl;
    }

    void size() {
        cout << count << endl;
    }

    void empty() {
        if (!isEmpty()) cout << "not empty!" << endl;
        else cout << "empty!" << endl;
    }
};

int main() {
    string type;
    int n;

    cin >> type;
    cin >> n;

    if (type == "stack") {
        Stack s;

        for (int i = 0; i < n; i++) {
            string cmd;
            cin >> cmd;

            if (cmd == "push") {
                int x;
                cin >> x;
                s.push(x);
            }
            else if (cmd == "pop") {
                s.pop();
            }
            else if (cmd == "front") {
                s.front();
            }
            else if (cmd == "size") {
                s.size();
            }
            else if (cmd == "empty") {
                s.empty();
            }
        }
    }
    else if (type == "queue") {
        Queue q;

        for (int i = 0; i < n; i++) {
            string cmd;
            cin >> cmd;

            if (cmd == "push") {
                int x;
                cin >> x;
                q.push(x);
            }
            else if (cmd == "pop") {
                q.pop();
            }
            else if (cmd == "front") {
                q.front();
            }
            else if (cmd == "size") {
                q.size();
            }
            else if (cmd == "empty") {
                q.empty();
            }
        }
    }

    return 0;
}
