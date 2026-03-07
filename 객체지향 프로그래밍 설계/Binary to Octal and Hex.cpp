#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int strlen(char *temp) {
	int n = 0;
	while (temp[n] != '\0')
		n++;
	return n;
}

void strcat(char* d, char* s) {
	int a, b, n=0;
	a = strlen(d);
	b = strlen(s);

	for (int i = 0; i < b; i++)
		d[a++] = s[i];
	d[a] = '\0';

}

int pow(int a, int b) {
	int sum = 1;
	for (int i = 0; i < b; i++)
		sum *= a;
	return sum;
}

void octal(char* binary) {
	int n=0, t=0;
	for (int i = 0; i < 4; i++) {
		char temp[3];
		for (int j = 0; j < 3; j++) {
			temp[j] = binary[n++];
		}

		int sum = 0;
		//8진수로 변환후 출력
		for (int i = 0; i < 3; i++) {
			if (temp[2 - i] == '1')
				sum += 1 * pow(2, i);
		}
		if (sum == 0 && t == 0)
			continue;
		else t = 1;
		cout << sum;
	}
}

void hexadecimal(char* binary) {
	int n = 0, t=0;
	for (int i = 0; i < 3; i++) {
		char temp[4];
		for (int j = 0; j < 4; j++) {
			temp[j] = binary[n++];
		}

		int sum = 0;
		//10진수로 변환후 출력
		for (int i = 0; i < 4; i++) {
			if (temp[3 - i] == '1')
				sum += 1 * pow(2, i);
		}
		if (sum == 0 && t == 0) continue;
		else{
			t = 1;
			switch (sum) {
			case 10:
				cout << 'A';
				break;
			case 11:
				cout << 'B';
				break;
			case 12:
				cout << 'C';
				break;
			case 13:
				cout << 'D';
				break;
			case 14:
				cout << 'E';
				break;
			case 15:
				cout << 'F';
				break;
			default: cout << sum;
			}
		}
			
	}
}
int main() {
	char temp[11];
	int n=0;

	cin >> temp;
	int len = strlen(temp);

	char binary[13];

	for(int i=0; i<12; i++)
		binary[i] = '0';
	binary[12 - len] = '\0';
	strcat(binary, temp);

	octal(binary);
	cout << endl;
	hexadecimal(binary);
	return 0;
}