#include <iostream>
using namespace std;

int main() {
	int m, n, sum = 0, first = 0;
	cin >> m >> n;

	for (int i = m; i <= n; i++) {

		int index = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				index = 1;
				break;
			}
		}
		if (index == 0) {
			if (i != 1) {
				sum += i;
				if (first == 0)
					first = i;
			}
		}
	}
	if (sum == 0)
		cout << -1;
	else cout << sum << endl << first;

	return 0;
}