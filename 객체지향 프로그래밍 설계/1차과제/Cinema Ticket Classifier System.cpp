#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		n = n % 3;
		if (n == 0)
			cout << "Standard" << endl;
		else if (n == 1)
			cout << "Premium" << endl;
		else if (n == 2)
			cout << "VIP" << endl;
	}

	return 0;
}