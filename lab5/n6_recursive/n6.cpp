#include <iostream>

long long recursiveFunction(long long a) {
	if (a == 0) {
		return 0;
	}
	if (a % 10 == 0) {
		return recursiveFunction(a / 10);
	}
	if (a % 10 != 0) {
		return a % 10;
	}
}

int main() {
	long long start = 1, finish = 1, sumStart = 0, sumFinish = 0;
	while (start != -1 && finish != -1) {
		std::cin >> start >> finish;
		if (start < 0 || finish < 0) {
			return 0;
		}
		else {
			sumStart = 0; sumFinish = 0;
			for (int i = start; i <= finish; i++) {
				sumFinish += recursiveFunction(i);
			}

			std::cout << sumFinish << '\n';
		}
	}
}