#include <iostream>
#include <cmath>

long long recursiveSum(long long n) {
	if (n == 1) {
		return 1;
	}
	while (n != 0) {

		return recursiveSum(n / 2) + ((n + 1) / 2) * ((n + 1) / 2);
	}
}

int main() {
	long long k;
	std::cin >> k;
	long long f;
	for (int i = 1; i <= k; i++) {
		std::cin >> f;
		if (f == 0) {
			std::cout << "0";
		}
		else{
			std::cout << recursiveSum(f) << '\n';
		}
	}
}