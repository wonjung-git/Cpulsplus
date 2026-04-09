#include <iostream>
using namespace std;

int main() {
	int m[5][5];

	//1차 메트릭스 입력
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++)
			cin >> m[i][j];
	
	//2차 메트릭스 합산
	int temp;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			cin >> temp;
			m[i][j] += temp;
		}

	//결과 메트릭스 출력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << m[i][j] << ' ';
		}
		if (i != 4)
			cout << m[i][4] << endl;
		else cout << m[i][4];
	}


	return 0;
}