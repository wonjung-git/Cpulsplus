#include <iostream>
using namespace std;

int main() {
	int n, k, index=0;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			index++;
		if (index == k) {
			cout << i;
			break;
		}
		else if (i == n)
			cout << 0;
	}
	
	return 0;
}