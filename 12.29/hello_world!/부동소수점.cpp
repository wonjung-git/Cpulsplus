#include <iostream>
#include <iomanip>
#include <limits>

int main() {
	double a = 0.1234567890123456789;
	std::cout << a << std::endl;
	std::cout << std::setprecision(std::numeric_limits<float>::digits10 + 1) << a << std::endl;
	std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1) << a << std::endl;
	return 0;
}