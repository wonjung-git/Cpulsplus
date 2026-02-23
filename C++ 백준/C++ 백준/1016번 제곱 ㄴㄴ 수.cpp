#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long int min, max, sum = 0, index;
	cin >> min;
	cin >> max;
	index = max - min + 1;
	sum = index;
	int* numbers = new int[index]();
	
	for (long long int i = 2; i <= sqrt(max); i++) {
		long long int sq = i * i;
		for (long long int j = min / sq; j * sq - min < index; j++) {
			if (min > j * sq)
				continue;
			else if (numbers[j * sq - min] == 1)
				continue;
			else
			{
				sum--;
				numbers[j * sq - min] = 1;
			}
		}
	}
	cout <<  sum;

	return 0;
}