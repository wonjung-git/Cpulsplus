#include <iostream>
using namespace std;

//비트 알려주는 함수
bool getbit(int input, int n) {
	n--;
	input = input & (1 << n);
	input = input >> n;
	return input;
}

// 이진 덧셈 함수
void sumbit(bool* A, int n) {
	if (n < 8) {
		if (A[n] == 0) A[n] = 1;
		else {
			A[n] = 0;
			sumbit(A, n + 1);
		}
	}
}

// A레지스터에 M만큼 더해주는 함수
void sum_Operation(bool* A, bool* M) {
	bool r[8];
	for (int i = 0; i < 8; i++) {
		if (A[i] || M[i]) {
			if (A[i] && M[i]) {
				r[i] = 0;
				sumbit(A, i + 1);
			}
			else r[i] = 1;
		}
		else r[i] = 0;
	}
	for (int i = 0; i < 8; i++)
		A[i] = r[i];

}

//Operation 계산 함수
void Operation(bool* A, bool* M, bool* Q, bool Q_1) {
	bool temp[8];
	for (int i = 0; i < 8; i++)
		temp[i] = M[i];

	if (Q[1] == 0) {
		if (Q[0] == 0) {
			if (Q_1 == 1) sum_Operation(A, temp);
		}
		else {
			if (Q_1 == 0) sum_Operation(A, temp);

			else {
				// M에 곱하기 2 해주기
				for (int i = 6; i >= 0; i--)
					temp[i + 1] = temp[i];
				temp[0] = 0;
				sum_Operation(A, temp);
			}
		}
	}
	else {
		if (Q[0] == 0) {
			if (Q_1 == 0) {
				// M에 곱하기 2 해주기
				for (int i = 6; i >= 0; i--)
					temp[i + 1] = temp[i];
				temp[0] = 0;
				// not연산
				for (int i = 0; i < 8; i++)
					temp[i] = !temp[i];
				sumbit(temp, 0);
				sum_Operation(A, temp);
			}
			else {
				// not연산
				for (int i = 0; i < 8; i++)
					temp[i] = !temp[i];
				sumbit(temp, 0);
				sum_Operation(A, temp);
			}
		}
		else {
			if (Q_1 == 0) {
				// not연산
				for (int i = 0; i < 8; i++)
					temp[i] = !temp[i];
				sumbit(temp, 0);
				sum_Operation(A, temp);
			}
		}
	}
}

//레지스터 출력 함수
void print_binary(bool* A, bool* Q, bool Q_1) {
	for (int i = 8; i > 0; i--)
		cout << A[i - 1];
	cout << ' ';

	for (int i = 8; i > 0; i--)
		cout << Q[i - 1];
	cout << ' ';

	cout << Q_1 << endl;
}

void right_shift(bool* A, bool* Q, bool* Q_1) {
	*Q_1 = Q[1];
	for (int i = 2; i < 8; i++)
		Q[i - 2] = Q[i];
	Q[6] = A[0];
	Q[7] = A[1];

	for (int i = 2; i < 8; i++)
		A[i - 2] = A[i];
	if (A[7] == 0) {
		A[6] = 0;
		A[7] = 0;
	}
	else {
		A[6] = 1;
		A[7] = 1;
	}
}

int main() {
	bool A[8], M[8], Q[8], Q_1 = 0;
	int m, q;

	//초기셋팅
	for (int i = 0; i < 8; i++)
		A[i] = 0;
	cin >> m >> q;
	for (int i = 8; i > 0; i--)
		Q[i - 1] = getbit(q, i);
	for (int i = 8; i > 0; i--)
		M[i - 1] = getbit(m, i);
	print_binary(A, Q, Q_1);

	//Operation계산
	for (int i = 0; i < 4; i++) {
		Operation(A, M, Q, Q_1);
		right_shift(A, Q, &Q_1);
		print_binary(A, Q, Q_1);
	}

	//최종결과 출력
	short result = 0;
	int i = 0;
	for (; i < 8; i++) {
		if (Q[i]) {
			result = result | (1 << i);
		}
	}
	for (int j = 0; i < 16; i++, j++) {
		if (A[j]) {
			result = result | (1 << i);
		}
	}
	cout << result;

	return 0;
}