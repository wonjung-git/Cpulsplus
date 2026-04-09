#include <iostream>
#include <string>

using namespace std;

class Package {
protected:
    string trackingCode;
    int weight;
    string zone;

public:

    virtual void Dispatch() {
        
    }
};

class Express : public Package {
public:
    virtual void Dispatch() {
        cout << "[Express] " << trackingCode << " {Weight: " << weight << "}, Zone: " << zone << " -> Loaded for priority delivery";
    }
    Express(string t, int w, string z) {
        trackingCode = t;
        weight = w;
        zone = z;
    }
};

class Fragile : public Package {
public:
    virtual void Dispatch() {
        cout << "[Fragile] " << trackingCode << " {Weight: " << weight << "}, Zone: " << zone << " -> Handled with care";
    }
    Fragile(string t, int w, string z) {
        trackingCode = t;
        weight = w;
        zone = z;
    }
};

bool strcmp(string a, string b) {
    for (int i = 0; ; i++) {
        if (a[i] == '\0' && b[i] == '\0') return 0;
        else if (a[i] != b[i]) return 1;
    }
}

class PackageQueue {
private:
    Package* queue[100];
    int front;
    int rear;

public:
    PackageQueue() : front(0), rear(0) {}

    bool isEmpty() const {
        return front == rear;
    }

    bool isFull() const {
        return rear >= 100;
    }

    void enqueue(Package* p) {
        if(!isFull()) queue[rear++] = p;
    }

    Package* dequeue() {
        if (!isEmpty()) return queue[front++];
        else return NULL;
    }

    void clear() {
        for(int i=0; i<rear; i++)
            delete queue[i];
    }

    ~PackageQueue() {
        clear();
    }
};

int main() {
    int n, weight;
    cin >> n;
    string type, code, zone;
    PackageQueue queue;
    for (int i = 0; i < n; i++) {
        cin >> type >> code >> weight >> zone;
        
        Package* p = NULL;
        if (!strcmp(type, "Express")) {
            p = new Express(code, weight, zone);
        }
        else if (!strcmp(type, "Fragile")) {
            p = new Fragile(code, weight, zone);
        }

        queue.enqueue(p);
    }
    cin >> type;


    if (!strcmp(type, "GO")) {
        for (int i = 0; i < n; i++) {
            if (i != 0) cout << endl;
            Package* p = queue.dequeue();
            p->Dispatch();
        }
    }

    return 0;
}
