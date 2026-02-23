#include <iostream>
using namespace std;

int main() {
	int N, n, sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> n;
		if (n == 1) sum--;

		int index = 0;
		for (int j = 2; j < n; j++) {
			if (n % j == 0)
				index = 1;
		}
		if (index == 0)
			sum++;
	}
	cout << sum;

	return 0;
}