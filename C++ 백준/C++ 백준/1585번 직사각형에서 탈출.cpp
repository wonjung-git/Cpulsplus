#include <iostream>
using namespace std;

int main() {
	int x, y, w, h, n[4];
	cin >> x >> y >> w >> h;
	n[0] = x;
	n[1] = y;
	n[2] = w-x;
	n[3] = h-y;
	int min = n[0];

	for (int i = 0; i < 4; i++)
		if (min > n[i])
			min = n[i];
	cout << min;
	return 0;
}