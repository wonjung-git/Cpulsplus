#include <iostream>
using namespace std;

int find_num(int n, int *arr, int len) {
	int count = 1;
	for (int i = 0; i < len; i++) {
		if (arr[n] > arr[i]) count++;
	}
	for(int i=0; i<n; i++)
		if (arr[n] == arr[i]) count++;

	return count;
}

int main() {
	//초기 세팅
	int n, *arr;
	cin >> n;
	arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//메인 부분
	for (int i = 0; i < n; i++) {
		if (i != 0) cout << ' ';
		cout << find_num(i, arr, n);
	}

	delete[] arr;
	return 0;
}