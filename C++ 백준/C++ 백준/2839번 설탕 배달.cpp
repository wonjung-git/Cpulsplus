#include <iostream>
using namespace std;

int main() {
	int stack_5, stack_3 = 0, n;

	cin >> n;

	stack_5 = n / 5;
	n -= stack_5 * 5;

	while (n != 0) {
		if (n >= 3) {
			n -= 3;
			stack_3++;
		}
		else {
			if (stack_5 == 0) {
				cout << -1;
				return 0;
			}
			else {
				stack_5--;
				n += 5;
			}
		}
	}
	cout << stack_5 + stack_3;

	return 0;
}