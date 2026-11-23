#include <iostream>
using namespace std;

int main() {
	int row = 1, X, ja, mo;
	bool flag = 1;
	cin >> X;

	for (int i = 1; ; i++) {
		if (row <= X && X < row + i) {
			if (flag) {
				ja = i - (X - row);
				mo = 1 + (X - row);
			}
			else {
				mo = i - (X - row);
				ja = 1 + (X - row);
			}

			cout << ja << '/' << mo;
			break;
		}
		flag = !flag;
		row += i;
	}

	return 0;
}