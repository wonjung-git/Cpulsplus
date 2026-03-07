#include <iostream>
using namespace std;

int pow(int a, int b) {
	int sum = 1;
	for (int i = 0; i < b; i++)
		sum *= a;
	return sum;
}

int main() {
	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		//몇 자리 수인지 확인
		int d;
		for (int j = 0; ; j++) {
			if (pow(10, j) <= n)
				continue;
			else {
				d = j;
				break;
			}
		}

		//각 자리별 계산
		int result = 1;
		for (int j = d - 1; j >= 0; j--) {
			int temp = n / pow(10, j);
			result *= temp;
			n -= temp * pow(10, j);
		}
		
		cout << result << endl;
	}

	return 0;
}