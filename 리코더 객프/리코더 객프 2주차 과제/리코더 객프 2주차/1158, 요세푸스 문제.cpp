#include <iostream>
using namespace std;

int main() {
	int N, k, r=0;

	cin >> N;
	cin >> k;

	int* arr = new int[N+1];
	int* result = new int[N];

	//배열 초기화
	for (int i = 0; i < N; i++) 
		arr[i] = i + 1;
	arr[N] = 0;

	int i = 1, index=0, n = N;
	while (1) {
		if (index == n)
			index = 0;

		if (i == k) {
			result[r] = arr[index];
			r++;
			for (int j = index; arr[j] != 0; j++)
				arr[j] = arr[j + 1];
			
			i = 0, n--, index--;
		}
		if (n == 0)
			break;

		i++, index++;
	}

	//출력
	cout << '<';
	for (int i = 0; i < N - 1; i++)
		cout << result[i] << ", ";
	cout << result[N-1] << '>';

	delete[] arr;
	delete[] result;
	return 0;
}