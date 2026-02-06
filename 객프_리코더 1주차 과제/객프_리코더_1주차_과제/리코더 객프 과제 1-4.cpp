#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	//À­ ºÎºÐ
	for (int i = 0; i < num/2 +1; i++) {
		for (int j = 0; j < num / 2 - i; j++) {
			cout << ' ';
		}
		for (int j = 0; j < i * 2 + 1; j++) {
			if (j == 0 || j == i * 2)
				cout << '*';
			else cout << ' ';
		}
		cout << endl;
	}
	//¾Æ·§ºÎºÐ
	for (int i = 0; i < num / 2; i++) {
		for (int j = 0; j < i+1; j++) {
			cout << ' ';
		}
		for (int j = num - 2*(i+1); j > 0; j--) {
			if (j == num - 2 * (i + 1) || j == 1)
				cout << '*';
			else cout << ' ';
		}
		cout << endl;
	}

	return 0;
}