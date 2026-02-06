#include <iostream>
using namespace std;

float score(int n, int max) {
	float a = (float)n / max * 100;
	return a;
}

int main() {
	int n, max=-1;
	float sum=0;
	cin >> n;

	int* s = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (max < s[i])
			max = s[i];
	}

	for (int i = 0; i < n; i++) {
		sum += score(s[i], max);
	}

	float new_mean = sum / n;
	cout << new_mean;
}