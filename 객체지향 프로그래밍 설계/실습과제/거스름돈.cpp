#include <iostream>
using namespace std;

int money(int money)	{
	int coins[6] = { 500, 100, 50, 10, 5, 1 }, count=0;
	for (int i = 0; i < 6; i++) {
		count += money / coins[i];
		money %= coins[i];
	}

	return count;
 }

int main() {
	int total = 1000, N;
	cin >> N;
	total -= N;

	cout << money(total);

	return 0;
}