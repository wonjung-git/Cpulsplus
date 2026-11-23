#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec(5);

	for (int i = 0; i < 5; i++)
		vec[i] = i * i;

	vector<int>::iterator itr;
	vector<int>::reverse_iterator ritr;

	for (itr = vec.begin(); itr != vec.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	for (ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
		cout << *ritr << " ";

	return 0;	
	}