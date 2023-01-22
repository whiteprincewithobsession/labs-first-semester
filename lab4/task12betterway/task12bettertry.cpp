#include <iostream>
#include <cmath>

int main() {
	long long n, centralElement, leftAngle, topAngle, nRow = 0, nCol = 0;
	std::cin >> n;
	leftAngle = pow(ceil(sqrt(n)), 2);
	topAngle = pow(trunc(sqrt(n)), 2) + 1;
	centralElement = (leftAngle + topAngle) / 2;
	if (ceil(sqrt(n)) == trunc(sqrt(n))) {
		nCol = 0;
		nRow = ceil(sqrt(n)) - 1;
		std::cout << nRow << " " << nCol;
	}
	else {
		if (n > centralElement) {
			nRow = ceil(sqrt(n)) - 1;
			for (int i = leftAngle; i != n; i--) {
				nCol++;
			}
			std::cout << nRow << " " << nCol;
		}
		else if (n < centralElement) {
			for (int i = topAngle; i != n; i++) {
				nRow++;
			}
			nCol = trunc(sqrt(n));
			std::cout << nRow << " " << nCol;

		}
		else {
			nRow = ceil(sqrt(n)) - 1;
			nCol = trunc(sqrt(n));
			std::cout << nRow << " " << nCol;

		}
	}
}