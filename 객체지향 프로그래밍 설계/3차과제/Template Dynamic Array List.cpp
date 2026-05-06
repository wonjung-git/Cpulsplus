#include <iostream>
#include <string>
using namespace std;

template <typename T>
class TemplateList {
private:
    T* arr;
    int sz;
    int cap;

    void grow() {
        // TODO:
        // double the capacity
        // allocate new array
        // copy existing elements
        // delete old array
        cap *= 2;
        T* new_arr = new T[cap];
        for (int i = 0; i < sz; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }

public:
    TemplateList(int initialCapacity) : sz(0), cap(initialCapacity) {
        // TODO:
        // if initialCapacity <= 0, throw exception
        // allocate dynamic array
        if (cap <= 0) throw 1;
        arr = new T[cap];
    }

    ~TemplateList() {
        delete[] arr;
    }

    void pushBack(const T& value) {
        // TODO
        if (sz == cap) grow();
        
        arr[sz++] = value;
    }

    T popBack() {
        // TODO:
        // if empty, throw exception
        // remove and return last element
        if (sz == 0)
            throw 1;

        T result = arr[sz - 1];
        sz--;
        return result;

        throw 1;
    }

    void insert(int idx, const T& value) {
        // TODO:
        // if idx invalid, throw exception
        // grow if needed
        // shift right
        // insert value
        if (idx < 0 || sz < idx) throw 1;
        if (sz == cap) grow();
        for (int i = sz-1; i >= idx; i--) {
            arr[i + 1] = arr[i];
        }
        arr[idx] = value;
        sz++;
    }

    T erase(int idx) {
        // TODO:
        // if idx invalid, throw exception
        // remove and return arr[idx]
        // shift left
        if (idx < 0 || sz <= idx) throw 1;
        T result = arr[idx];
        for (int i = idx; i < sz-1; i++) {
            arr[i] = arr[i + 1];
        }

        sz--;
        return result;
        throw 1;
    }

    T get(int idx) const {
        // TODO:
        // if idx invalid, throw exception
        // return arr[idx]
        if (idx < 0 || sz <= idx) throw 1;

        return arr[idx];

        throw 1;
    }

    void set(int idx, const T& value) {
        // TODO:
        // if idx invalid, throw exception
        // assign new value
        if (idx < 0 || sz <= idx) throw 1;

        arr[idx] = value;
    }

    int find(const T& value) const {
        // TODO:
        // return first index if found, else -1
        for (int i = 0; i < sz; i++) {
            if (arr[i] == value) return i;
        }

        return -1;
    }

    int size() const {
        return sz;
    }

    int capacity() const {
        return cap;
    }

    void clear() {
        // TODO:
        // remove all elements but keep capacity unchanged

        //사실 sz만 0으로 바꾸면 되긴 하지만, 그래도 비운다 라는걸 표현하기 위해..
        for (int i = 0; i < sz; i++)
            arr[i] = T{};

        sz = 0;
    }

    void print() const {
        // TODO:
        // print EMPTY if list is empty
        // otherwise print elements separated by one space
        if (sz == 0) cout << "EMPTY";
        else {
            for(int i=0; i<sz-1; i++)
                cout << arr[i] << " ";
            cout << arr[sz-1];
        }
    }
};

template <typename T>
void runCommands(int Q, int initialCapacity) {
    TemplateList<T> lst(initialCapacity);

    int i;
    for (i = 0; i < Q; ++i) {
        string cmd;
        cin >> cmd;

        try {
            if (cmd == "PUSH") {
                T x;
                cin >> x;
                lst.pushBack(x);
            }
            else if (cmd == "POP") {
                cout << lst.popBack() << "\n";
            }
            else if (cmd == "INSERT") {
                int idx;
                T x;
                cin >> idx >> x;
                lst.insert(idx, x);
            }
            else if (cmd == "ERASE") {
                int idx;
                cin >> idx;
                cout << lst.erase(idx) << "\n";
            }
            else if (cmd == "GET") {
                int idx;
                cin >> idx;
                cout << lst.get(idx) << "\n";
            }
            else if (cmd == "SET") {
                int idx;
                T x;
                cin >> idx >> x;
                lst.set(idx, x);
            }
            else if (cmd == "FIND") {
                T x;
                cin >> x;
                cout << lst.find(x) << "\n";
            }
            else if (cmd == "SIZE") {
                cout << lst.size() << "\n";
            }
            else if (cmd == "CAPACITY") {
                cout << lst.capacity() << "\n";
            }
            else if (cmd == "CLEAR") {
                lst.clear();
            }
            else if (cmd == "PRINT") {
                lst.print();
                cout << "\n";
            }
            else {
                throw 1;
            }
        }
        catch (...) {
            cout << "ERROR\n";
        }
    }
}

int main() {
    string type;
    int Q, initialCapacity;
    cin >> type >> Q >> initialCapacity;

    if (type == "INT") {
        runCommands<int>(Q, initialCapacity);
    }
    else if (type == "STRING") {
        runCommands<string>(Q, initialCapacity);
    }
    else {
        cout << "ERROR\n";
    }

    return 0;
}
