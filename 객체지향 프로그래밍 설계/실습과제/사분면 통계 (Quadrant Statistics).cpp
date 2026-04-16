#include <iostream>
using namespace std;

int main() {
	int t, x, y, q[4] = { 0, };
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		x > 0 ? (y > 0 ? q[0]++ : q[3]++) : (y > 0 ? q[1]++ : q[2]++);
	}

	for (int i = 0; i < 3; i++)
		cout << q[i] << endl;
	cout << q[3];

	return 0;
}