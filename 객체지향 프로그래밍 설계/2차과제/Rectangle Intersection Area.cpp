#include <iostream>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
};

int myMin(int a, int b) {
    if (a > b) return b;
    else return a;
}

int myMax(int a, int b) {
    if (a > b) return a;
    else return b;
}

int getOverlapWidth(const Rectangle& a, const Rectangle& b) {
    return myMin(a.x2, b.x2) - myMax(a.x1, b.x1);
}

int getOverlapHeight(const Rectangle& a, const Rectangle& b) {
    return myMin(a.y2, b.y2) - myMax(a.y1, b.y1);
}

bool isOverlapping(const Rectangle& a, const Rectangle& b) {
    if (getOverlapHeight(a, b) > 0 && getOverlapWidth(a, b) > 0) return 1;
    else return 0;
}

int getOverlapArea(const Rectangle& a, const Rectangle& b) {
    return getOverlapHeight(a, b) * getOverlapWidth(a, b);
}

int main() {
    int N, count=0, **result = NULL;
    cin >> N;
    result = new int* [N * (N - 1) / 2];
    for(int i=0; i< N * (N - 1) / 2; i++)
        result[i] = new int[3];

    Rectangle rects[100];

    for (int i = 0; i < N; i++) {
        cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (isOverlapping(rects[i], rects[j])) {
                count++;
                result[count-1][0] = i+1;
                result[count - 1][1] = j+1;
                result[count-1][2] = getOverlapArea(rects[i], rects[j]);
            }
        }
    }

    cout << count << endl;
    for (int i = 0; i < count; i++) {
        if (i != 0) cout << endl;
        cout << result[i][0] << ' ' << result[i][1] << ' ' << result[i][2];
    }

    for (int i = 0; i < N * (N - 1) / 2; i++)
        delete[] result[i];
    delete[] result;

    return 0;
}