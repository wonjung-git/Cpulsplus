#include <iostream>
using namespace std;

int main() {
	unsigned long long int n;
	int a, even=0, odd=0;

	cin >> n;

	while (n > 0) {
		a = n % 10;
		if (a % 2 == 0)
			even += a;
		else
			odd += a;
		n /= 10;
	}
	cout << "sum of even : " << even << endl;
	cout << "sum of odd : " << odd;

	return 0;
}