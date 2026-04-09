#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	cout << fixed;
	cout.precision(3);
	int n, credits_sum=0, credits;
	double gpa, gpa_sum = 0, gpa_mean;
	char GPA[3];

	cin >> n;
	for (int i = 0; i < n; i++) {
		//gpa 계산
		cin >> GPA;
		switch (GPA[0]) {
		case 'A':
			gpa = 4.0;
			break;
		case 'B':
			gpa = 3.0;
			break;
		case 'C':
			gpa = 2.0;
			break;
		case 'D':
			gpa = 1.0;
			break;
		default: cout << "error";
		}
		if (GPA[1] == '+') gpa += 0.5;

		//credits 계산
		cin >> credits;
		credits_sum += credits;
		gpa_sum += gpa * credits;
	}
	gpa_mean = gpa_sum / credits_sum;
	cout << gpa_mean << endl << credits_sum;

	return 0;
}