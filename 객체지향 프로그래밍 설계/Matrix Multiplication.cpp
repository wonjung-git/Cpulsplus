#include <iostream>
using namespace std;

int main() {
	//matrix A
	int r1, c1;
	cin >> r1 >> c1;
	int** m_a = new int* [r1];
	for (int i = 0; i < r1; i++)
		m_a[i] = new int[c1];
	for (int i = 0; i < r1; i++)
		for (int j = 0; j < c1; j++)
			cin >> m_a[i][j];

	//matrix B
	int r2, c2;
	cin >> r2 >> c2;
	if (c1 != r2) {
		cout << "ERROR";
		return 0;
	}
	int** m_b = new int* [r2];
	for (int i = 0; i < r2; i++)
		m_b[i] = new int[c2];
	for (int i = 0; i < r2; i++)
		for (int j = 0; j < c2; j++)
			cin >> m_b[i][j];

	//matrix C
	int r3, c3;
	r3 = r1, c3 = c2;
	int** m_c = new int* [r3];
	for (int i = 0; i < r3; i++)
		m_c[i] = new int[c3];

	//계산
	for (int i = 0; i < r3; i++) {
		for (int j = 0; j < c3; j++) {
			int temp = 0;
			for (int k = 0; k < c1; k++) {
				temp += m_a[i][k] * m_b[k][j];
			}
			m_c[i][j] = temp;
		}
	}

	//출력
	for (int i = 0; i < r3; i++) {
		for (int j = 0; j < c3; j++)
			if (j != c3 - 1)
				cout << m_c[i][j] << ' ';
			else cout << m_c[i][j];
		if (i != r3 - 1)
			cout << endl;
	}

	//delete
	for (int i = 0; i < r1; i++)
		delete[] m_a[i];
	delete[] m_a;
	for (int i = 0; i < r2; i++)
		delete[] m_b[i];
	delete[] m_b;
	for (int i = 0; i < r3; i++)
		delete[] m_c[i];
	delete[] m_c;

	return 0;
}