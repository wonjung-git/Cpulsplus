#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int compare(const void* a, const void* b) {
	const char* s1 = *(const char* const*)a;
	const char* s2 = *(const char* const*)b;
	return strcmp(s1, s2);
}

bool binary_search(char **arr, int n, char *key) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		int c = strcmp(arr[mid], key);

		if (c == 0)
			return 1;
		if (c < 0)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return 0;
}

int main() {
	int n, m, r=0;
	cin >> n >> m;
	char temp[21];
	char** name = new char* [n];
	char** result = new char* [n];

	//듣도 못한 명단
	for (int i = 0; i < n; i++) {
		cin >> temp;
		name[i] = new char[strlen(temp)+1];
		strcpy(name[i], temp);
	}

	//정렬
	qsort(name, n, sizeof(char *), compare);

	//듣도못한 명단과 비교(이분탐색)
	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (binary_search(name, n, temp)) {
			result[r] = new char[strlen(temp)+1];
			strcpy(result[r++], temp);
		}
	}

	//결과 정렬
	qsort(result, r, sizeof(char*), compare);

	//출력
	cout << r;
	for (int i = 0; i < r; i++)
		cout << '\n' << result[i];


	//메모리 헤제
	for (int i = 0; i < n; i++)
		delete[] name[i];
	delete[] name;

	for (int i = 0; i < r; i++)
		delete[] result[i];
	delete[] result;

	return 0;
}