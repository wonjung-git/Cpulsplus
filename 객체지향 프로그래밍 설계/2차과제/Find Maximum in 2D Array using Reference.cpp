#include <iostream>
using namespace std;

// TODO: implement this function
void findMax(int arr[][20], int N, int M, int& maxVal) {
	maxVal = arr[0][0];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (maxVal < arr[i][j]) maxVal = arr[i][j];
}

int main() {
	int n, m, max;
	cin >> n >> m;
	int arr[20][20];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	findMax(arr, n, m, max);

	cout << max;
	return 0;
}