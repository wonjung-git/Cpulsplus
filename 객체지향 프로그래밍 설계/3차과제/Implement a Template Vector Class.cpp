#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MyVector {
private:
    T* arr;
    int currentSize;
    int capacity;

public:
    MyVector() {
        currentSize = 0;
        capacity = 1;
        arr = new T[capacity];
    }

    ~MyVector() {
        delete[] arr;
    }

    void push_back(T value) {
        if (currentSize == capacity) {
            capacity *= 2;
            T* new_arr = new T[capacity];
            for (int i = 0; i < currentSize; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;

            arr = new_arr;
        }
        
        arr[currentSize++] = value;
    }

    void pop_back() {
        if (currentSize == 0)
            throw "No element to remove.";
        else {
            currentSize--;
        }
    }

    T get(int index) {
        if (index < 0 || currentSize - 1 < index)
            throw "Index out of range.";
        else {
            return arr[index];
        }
    }

    T& operator[](int index) {
        if (index < 0 || currentSize - 1 < index)
            throw "Index out of range.";
        else {
            return arr[index];
        }
    }

    int getSize() {
        return currentSize;
    }

};

int main() {
    MyVector<int> vec;
    int N;
    cin >> N;

    string command;

    for (int i = 0; i < N; i++) {
        cin >> command;

        try {
            if (command == "push") {
                int value;
                cin >> value;
                vec.push_back(value);
            }
            else if (command == "pop") {
                vec.pop_back();
            }
            else if (command == "get") {
                int index;
                cin >> index;
                cout << vec.get(index) << "\n";
            }
            else if (command == "set") {
                int index, value;
                cin >> index >> value;
                vec[index] = value;
            }
            else if (command == "size") {
                cout << vec.getSize() << "\n";
            }
        }
        catch (const char* msg) {
            cout << msg << "\n";
        }
    }

    return 0;
}
