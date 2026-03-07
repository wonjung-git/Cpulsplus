#include <iostream>
using namespace std;

//비트 알려주는 함수
char getbit(char data, char bitnum) {
	bitnum--;
	data = data & (1 << bitnum);
	data = data >> bitnum;
	return data;
}

//곱셈 규칙
char operation(int m, char Q, bool Q_1) {
	char result = 0;
	if (getbit(Q, 2)) {
		if (getbit(Q, 1)) {
			if (Q_1) {
				return 0;
			}
			else return -1*m;
		}
		else{
			if (Q_1) {
				return -1 * m;
			}
			else return -2 * m;
		}
	}
	else {
		if (getbit(Q, 1)) {
			if (Q_1) {
				return 2*m;
			}
			else return m;
		}
		else {
			if (Q_1) {
				return m;
			}
			else return 0;
		}
	}
}

//shift해주는 함수
void right_2_shift(char* A, char* Q, bool* Q_1) {
	bool temp = getbit(*Q, 2);
	if (temp) {
		*Q_1 = 1;
	}
	else *Q_1 = 0;

	*Q = *Q >> 2;

	temp = getbit(*A, 1);
	if (temp) {
		*Q = *Q | 64;
	}
	else *Q = *Q & 191;

	temp = getbit(*A, 2);
	if (temp) {
		*Q = *Q | 128;
	}
	else *Q = *Q & 127;

	*A = *A >> 2;
}

//출력 함수
void print_binary(char A, char Q, bool Q_1) {
	bool temp;
	for (int i = 8; i > 0; i--) {
		temp = getbit(A, i);
		cout << temp;
	}
	cout << ' ';

	for (int i = 8; i > 0; i--) {
		temp = getbit(Q, i);
		cout << temp;
	}
	cout << ' ';
	temp = Q_1;
	cout << temp << endl;
}

int main() {
	int m, q;
	cin >> m >> q;

	char A, Q;
	bool Q_1;
	A = 0;
	Q = q;
	Q_1 = 0;

	//초기 상태 출력
	print_binary(A, Q, Q_1);

	//계산 과정
	for (int i = 0; i < 4; i++) {
		A += operation(m, Q, Q_1);
		right_2_shift(&A, &Q, &Q_1);
		print_binary(A, Q, Q_1);
	}

	//최종 수 출력
	int sum;
	if (getbit(A, 8))
		sum = A + Q + 1;
	else sum = A + Q;

	cout << sum;

	return 0;
}