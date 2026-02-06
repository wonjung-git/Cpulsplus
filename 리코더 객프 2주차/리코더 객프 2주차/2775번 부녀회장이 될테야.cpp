#include <iostream>
using namespace std;

void hap(int** arr, int k, int n) {
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			int hap = 0;
			for (int k = 0; k <= j; k++) {
				hap += arr[i - 1][k];
			}
			arr[i][j] = hap;
		}
	}
}

int main() {
	int k, n, t;
	cin >> t;
	int* result = new int[t];

	for (int j = 0; j < t; j++) {

		cin >> k >> n;

		int** arr = new int* [k+1];
		for (int i = 0; i <= k; i++)
			arr[i] = new int[n];

		for (int i = 0; i < n; i++)
			arr[0][i] = i + 1;

		hap(arr, k, n);

		result[j] = arr[k][n - 1];

	
		for (int i = 0; i <= k; i++)
			delete[] arr[i];
		delete[] arr;
		
	}

	for(int i=0; i<t-1; i++)
		cout << result[i] << '\n';
	cout << result[t - 1];

	

	delete[] result;
	return 0;
}