#include <iostream>
using namespace std;

int main() {
	int size, *max = new int, *min = new int;

	while (1) {
		cout << "5~20사이의 배열 사이즈를 입력하세요. : ";
		cin >> size;
		if (size < 5 || 20 < size)
			cout << "사이즈의 범위를 다시 입력하세요." << endl;
		else break;
	}
	int* arr = new int[size];
	*max = -1, * min = 101;

	// 랜덤 시드
	srand(time(0));
	// 0~100 사이의 랜덤 숫자
	cout << "Random Number : ";
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 101;
		cout << arr[i] << ' ';
		if (*max < arr[i])
			max = &arr[i];
		if (*min > arr[i])
			min = &arr[i];
	}
	cout << endl;

	cout << "Maximum value: " << *max << "    , Address: " << max << endl;
	cout << "Mminimum value: " << *min << "    , Address: " << min << endl;


	delete arr;

	return 0;
}