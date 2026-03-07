#include <iostream>
using namespace std;

int peak(int size, int a, int b, int **m) {
	//up
	if (a > 0) {
		if (m[a - 1][b] >= m[a][b]) return 0;
	}
	//down
	if (size-1 > a) {
		if (m[a + 1][b] >= m[a][b]) return 0;
	}
	//left
	if (b > 0) {
		if (m[a][b - 1] >= m[a][b]) return 0;
	}
	//right
	if (size-1 > b) {
		if (m[a][b + 1] >= m[a][b]) return 0;
	}

	return 1;
}

int main() {
	//초기 세팅
	int size;
	cin >> size;
	int** m = new int*[size];
	for (int i = 0; i < size; i++)
		m[i] = new int [size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> m[i][j];

	//peak check
	int sum = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			if (peak(size, i, j, m)) {
				cout << '(' << i+1 << ", " << j+1 << ')' << endl;
				sum++;
			}
		}
	cout << sum;

	//delete
	for (int i = 0; i < size; i++)
		delete[] m[i];
	delete[] m;

	return 0;
}