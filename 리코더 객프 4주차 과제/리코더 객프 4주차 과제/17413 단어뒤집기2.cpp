#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char s[100000];
	gets_s(s, 100000);

	int len = strlen(s);
	char* word = new char[len];
	char* new_s = new char[len+1];
	strcpy(new_s, "");
	for (int i = 0; i < len; i++) {
		if (s[i] == '<') {
			for (int j = i, start=0; ; j++, start++) {
				word[start] = s[j];
				if (s[j] != '>') {
					word[start + 1] = '\0';
					i += start;
				}
			}
			strcat(new_s, word);
			continue;
		}
	}
	cout << new_s;

	return 0;
}
