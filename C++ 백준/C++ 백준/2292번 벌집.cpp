#include <iostream>
using namespace std;

int main() {
	int start = 1, end = 1, X;
	cin >> X;

	for (int i = 0; ; i++) {
		if (start <= X && X <= end) {
			cout << i + 1;
			break;
		}

		start = end + 1;
		end = start + 5 + i*6;
	}
	return 0;
}