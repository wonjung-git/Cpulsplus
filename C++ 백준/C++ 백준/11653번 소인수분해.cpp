#include <iostream>
using namespace std;

int main() {
	int n, sum = 0;
	cin >> n;

	while (1) {
		if (n == 1) break;
		for (int i = 2; ; i++) {
			if (n % i == 0) {
				cout << i << endl;
				n /= i;
				break;
			}
		}
	}

	return 0;
}