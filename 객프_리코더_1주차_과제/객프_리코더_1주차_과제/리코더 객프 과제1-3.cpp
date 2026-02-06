#include <iostream>
using namespace std;

namespace wonjung {
	int strlen(char* s) {
		int i = 0;

		while (s[i] != '\0') {
			i++;
		}

		//마지막이 0이면 아예 개수에서 제거
		if (s[i - 1] == '0')
			i--;

		return i;
	}
}


int main() {
	char s[101];
	cin >> s;

	for (int i = wonjung::strlen(s)-1; i >= 0; i--) {
		cout << s[i];
	}

	return 0;
}