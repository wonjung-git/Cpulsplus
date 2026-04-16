#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n = 0, x = 0;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];

	cin >> x;
	sort(num.begin(), num.end());
	
	int left = 0, right = n - 1, count = 0;

	while (left < right) {
		int sum = num[left] + num[right];

		if (sum < x) left++;
		else if (sum > x) right--;
		else {
			count++;
			int lv = num[left], rv = num[right];

			while (left < right && num[left] == lv) {
				left++;
			}
			while (left < right && num[right] == rv) {
				right--;
			}
		}
	}
	cout << count << endl;

	return 0;
}