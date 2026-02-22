#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	char s[1000001], boom[37];
	cin >> s;
	cin >> boom;
	int s_len = strlen(s), b_len = strlen(boom), r_len=0;
	char* result = new char[s_len+1];


	for (int i = 0; i < s_len; i++) {
		result[r_len] = s[i];
		r_len++;
		if (result[r_len-1] == boom[b_len - 1] && r_len >= b_len) {
			int flag = 1;
			for (int j = b_len - 2, k=r_len-2; j >= 0 && k>=0; j--, k--) {
				if (result[k] != boom[j]) {
					flag = 0;
				}
			}
			if (flag == 1) {
				r_len -= b_len;
			}
		}
	}
	result[r_len] = '\0';
	
	if (!strcmp(result, ""))
		cout << "FRULA";
	else
		cout << result;

	return 0;
}
