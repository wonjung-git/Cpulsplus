#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char* reverse(char* word) {
	int len = strlen(word);
	char* new_word = new char[len + 1];
	for (int i = 0; i < len; i++) {
		new_word[i] = word[len - 1 - i];
	}
	new_word[len] = '\0';
	return new_word;
}

int main() {
	char s[100001];
	fgets(s, 100001, stdin);

	int len = strlen(s);
	char* word = new char[len];
	char* new_s = new char[len+1];
	strcpy(new_s, "");
	for (int i = 0; i < len; i++) {
		if (s[i] == '<') {
			for (int j = i, start=0; ; j++, start++) {
				word[start] = s[j];
				if (s[j] == '>') {
					word[start + 1] = '\0';
					i += start;
					break;
				}
			}
			strcat(new_s, word);
		}
		else if(s[i] == ' ')
			strcat(new_s, " ");
		
		else {
			for (int j = i, start = 0; ; j++, start++) {
				if (s[j] == '\n') {
					word[start] = '\0';
					i += start;
					break;
				}
				else if (s[j] == ' ' || s[j] == '\0' || s[j] == '<') {
					word[start] = '\0';
					i += start-1;
					break;
				}
				word[start] = s[j];
			}
			char* rev_word = reverse(word);
			strcat(new_s, rev_word);
		}
	}
	cout << new_s;

	return 0;
}
