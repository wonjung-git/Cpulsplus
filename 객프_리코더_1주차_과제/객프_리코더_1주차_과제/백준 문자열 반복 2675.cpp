#include <iostream>
using namespace std;

int main() {
	char S[21], P[21];
	int T, R;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> R;
		cin >> S;
		int j = 0;
		while (S[j] != '\0') {
			for (int k = 0; k < R; k++)
				cout << S[j];
			j++;
		}
		cout << '\n';
	}

	return 0;
}