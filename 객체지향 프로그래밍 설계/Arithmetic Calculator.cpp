#include <iostream>
using namespace std;

int main() {
	int a, b;
	char c;
	while (1) {
		cin >> a >> b;
		cin >> c;

		switch (c) {
		case '+' :
			cout << a + b << endl;
			break;
		case '-':
			cout << a - b << endl;
			break;
		case '*':
			cout << a * b << endl;
			break;
		case '/':
			if (b == 0) cout << "Error" << endl;
			else cout << a / b << endl;
			break;
		case '%':
			if (b == 0) cout << "Error" << endl;
			else cout << a % b << endl;
			break;
		}
		cin >> c;
		if (c == 'n')
			break;
		else if (c == 'y')
			continue;
		else return 1;
	}

	return 0;
}