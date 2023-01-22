#include <iostream>
#include <cmath>

long long recursiveFunction(long long k, long long n, long long m){
	if (n % 2 == 1) {
		return (recursiveFunction((k * k) % m, n / 2, m) * k) % m;
	}
	else if (n % 2 == 0 && n != 0) {
		recursiveFunction((k * k) % m, n / 2, m);
	}
	else if (n == 0) {
		return 1;
	}
	else return 0;
}

int main() {
	long long testCounter = 1;
	long long k = 1, n = 1, t = 1, m;
	while (k != 0 && n != 0 && t != 0){
		std::cin >> k >> n >> t;
		if (k == 0 && n == 0 && t == 0) {
			return 0;
		}
		else if (k < 0 || n < 0 || t < 0) {
			return 0;
		}
		else {
			m = powl(10, t);
            if(testCounter != 1) std::cout << '\n';
            k %= m;
			std::cout << "Case #" << testCounter << ": ";
			std::cout << recursiveFunction(k, n, m);
			testCounter++;
		}
	}
}