#include <iostream>
using namespace std;

int main() {
	int found = 0, num=0;
	char s;

	while (1) {
		s = getchar(); //cin.get을 쓰면 똑같이 작동하지만 강의에서 배우지 않아 사용하지 않음.

		if (s == '\n')
			break;

		if (32 < s && s < 127) {
			if (found == 0) {
				num++;
				found = 1;
			}
		}
		else {
			if (found == 1) {
				found = 0;
			}
		}
	}
	cout << num;

	return 0;
}