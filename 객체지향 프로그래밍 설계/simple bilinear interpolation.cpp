#include <iostream>
using namespace std;

int main() {
	//초기 설정
	int m, n;
	cin >> m >> n;
	int** input = new int* [m];
	for (int i = 0; i < m; i++)
		input[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> input[i][j];

	int M = 2 * m - 1, N = 2 * n - 1;
	double** result = new double* [M];
	for (int i = 0; i < M; i++)
		result[i] = new double[N];

	//기존 숫자들 우선 배치
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			result[2 * i][2 * j] = input[i][j];

	//계산
	double temp;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (j % 2 == 1 && i % 2 == 1) {
				temp = (result[i - 1][j - 1] + result[i - 1][j + 1] + result[i + 1][j - 1] + result[i + 1][j + 1]) / 4;
				result[i][j] = temp;
			}
			else if (j % 2 == 1) {
				temp = (result[i][j - 1] + result[i][j + 1]) / 2;
				result[i][j] = temp;
			}
			else if (i % 2 == 1) {
				temp = (result[i-1][j] + result[i+1][j]) / 2;
				result[i][j] = temp;
			}
		}
	}

	//결과 출력
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (j != N - 1)
				cout << result[i][j] << ' ';
			else cout << result[i][j];
		}
		if(i != M-1)
			cout << endl;
	}

	//delete
	for (int i = 0; i < m; i++)
		delete[] input[i];
	delete[] input;
	for (int i = 0; i < M; i++)
		delete[] result[i];
	delete[] result;
	return 0;
}