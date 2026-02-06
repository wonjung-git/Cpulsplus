#include <iostream>

int main() {
	for (char i = 32; i < 127; i++) {
		std::cout << i << " ";
		if(i % 16 == 0) std::cout << "\n";
	}

	return 0;
}