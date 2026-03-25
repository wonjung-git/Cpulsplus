#include <iostream>
using namespace std;

int pow(int a, int b) {
	int sum = 1;
	for (int i = 0; i < b; i++)
		sum = sum * a;
	return sum;
}

void Octal(char* binary, int len) {
	int n = len / 3, re = len % 3, t = 0;

	int sum = 0;
	for (int i = 0; i < re; i++) {
		if (binary[len - re + i] == '1') sum = sum + pow(2, i);
	}
	if (sum != 0) cout << sum;

	for (int i = n; i > 0; i--) {
		sum = 0;
		for (int j = 0; j < 3; j++) {
			if (binary[t++] == '1') sum = sum + pow(2, j);
		}
		cout << sum << endl;
	}
}

void Hex(char* binary, int len) {
	int n = len / 4, re = len % 4, t = 0;

	int sum = 0;
	for (int i = 0; i < re; i++) {
		if (binary[len - re + i] == '1') sum = sum + pow(2, i);
	}
	if (sum != 0) {
		switch (sum) {
		case 10: cout << 'A';
			break;
		case 11: cout << 'B';
			break;
		case 12: cout << 'C';
			break;
		case 13: cout << 'D';
			break;
		case 14: cout << 'E';
			break;
		case 15: cout << 'F';
			break;
		default: cout << sum;
		}
	}

	for (int i = n; i > 0; i--) {
		sum = 0;
		for (int j = 0; j < 4; j++) {
			if (binary[t++] == '1') sum = sum + pow(2, j);
		}
		switch (sum) {
		case 10: cout << 'A';
			break;
		case 11: cout << 'B';
			break;
		case 12: cout << 'C';
			break;
		case 13: cout << 'D';
			break;
		case 14: cout << 'E';
			break;
		case 15: cout << 'F';
			break;
		default: cout << sum;
		}
	}
}

int main() {
	char temp[11];
	cin >> temp;
	int len = 0;
	while (1) {
		if (temp[len] == '\0')
			break;
		len++;
	}
	char* binary = new char[len];
	for (int i = len - 1, j = 0; i >= 0; i--, j++)
		binary[j] = temp[i];

	Octal(binary, len);
	Hex(binary, len);

	return 0;
}