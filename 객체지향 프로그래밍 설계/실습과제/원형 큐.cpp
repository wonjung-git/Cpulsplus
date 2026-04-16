#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
    int arr[20];
    int capacity;
    int front;
    int rear;

public:
    CircularQueue() {
        capacity = 20;
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        if (front == rear) return 1;
        else return 0;
    }

    bool isFull() {
        if ((rear + 1)%capacity == front) return 1;
        else return 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << arr[front] << "\n";
        front = (front + 1) % capacity;
    }

    int getfront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i != rear; i++)
            cout << arr[i] << " ";

        cout << "\n";
    }
};

int main() {
    CircularQueue q;

    int n;
    cin >> n;

    string cmd;

    while (n--) {
        cin >> cmd;

        if (cmd == "enqueue") { // enqueue
            int x;
            cin >> x;
            q.enqueue(x);
        }
        else if (cmd == "dequeue") { // dequeue
            q.dequeue();
        }
        else if (cmd == "front") { // front
            int f = q.getfront();
            if (f != -1)
                cout << f << "\n";
        }
        else if (cmd == "print") { // print
            q.printQueue();
        }
    }

    return 0;
}
