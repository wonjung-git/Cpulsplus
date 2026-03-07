#include <iostream>
using namespace std;

int main() {
	int point = 30000, input, cost;

	while (cin >> input) {
		if (input == -1) break;
		else if (2 > input || input > 200) {
			cout << point;
			break;
		}
		//주요 계산
		else {
			input -= 10;
			cost = 1000;
			while (input > 0) {
				input -= 5;
				cost += 150;
			}
			if (cost > point) {
				cout << point;
				break;
			}
			else {
				point -= cost;
				cout << "Cost: " << cost << ", Remaining balance: " << point << endl;
			}
		}
	}

	return 0;
}