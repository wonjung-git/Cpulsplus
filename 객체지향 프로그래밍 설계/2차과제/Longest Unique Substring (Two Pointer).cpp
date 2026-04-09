#include <iostream>
using namespace std;

bool check(char *s, int l, int r) {
	for (int i = l; i < r; i++) {
		if (s[r] == s[i]) return 1;
	}
	return 0;
}

int main() {
	char s[100001];
	int right = 0, left=0, len=0, max=0;
	cin >> s;
	while (s[len] != '\0') len++;

	for (right = 0; right < len; right++) {
		if (check(s, left, right)) {
			while (s[left++] != s[right]);

			if (max < right - left + 1) max = right - left + 1;
		}
		if (max < right - left + 1) max = right - left + 1;
	}
	cout << max;

	return 0;
}