#include <iostream>
using namespace std;

int pow(int a, int b) {
	int sum = 1;
	for (int i = 0; i < b; i++) 
		sum *= a;
	
	return sum;
}

int main() {
	cout << fixed;
	cout.precision(3);

	int n, l=1, byte_sum=0;
	cin >> n;
	char str[41];
	cin >> str;

	for (int i = 0; i < n; i++) {
		if (str[i] != str[i + 1]) {
			cout << str[i] << l;
			for (int j = 0; ; j++) {
				if (pow(10, j) <= l)
					continue;
				else {
					byte_sum += 2 + j;
					break;
				}
			}
			l = 1;
		}
		else {
			l++;
		}
	}
	float compression = (n * 2)/(float)byte_sum ;
	cout << endl << compression;

	return 0;
}