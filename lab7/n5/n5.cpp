#include <iostream>

int main() {
	long long tests;
	long long num;
	std::cin >> tests;
	while (tests > 0) {
		std::cin >> num;
		std::cout << (num + 1) / 10 << '\n';
		tests--;
	}
}