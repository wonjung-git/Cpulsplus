#include <iostream>

int main() {
	int a, b;
	std::cout << "첫번째 숫자를 입력하세요:";
	std::cin >> a;
	std::cout << "두번째 숫자를 입력하세요:";
	std::cin >> b;

	std::cout << a << "+" << b << "=" << a + b << std::endl;

	return 0;
}