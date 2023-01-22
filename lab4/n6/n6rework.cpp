#include <iostream>
#include <string>
int main() {
	int i, a, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0, a0 = 0, k = 0, requiredElement;
	std::string s;
	std::cin >> s;
	std::cin >> i;
	requiredElement = s[i - 1];
	//std::cout << "REQUIRED = " << requiredElement - '0' << '\n';
	for (int q = 0; q < s.length(); q++) {
		if (s[q] == '1') {
			a1 = 1;
		}
		if (s[q] == '2') {
			a2 = 1;
		}
		if (s[q] == '3') {
			a3 = 1;
		}
		if (s[q] == '4') {
			a4 = 1;
		}
		if (s[q] == '5') {
			a5 = 1;
		}
		if (s[q] == '6') {
			a6 = 1;
		}
		if (s[q] == '7') {
			a7 = 1;
		}
		if (s[q] == '8') {
			a8 = 1;
		}
		if (s[q] == '9') {
			a9 = 1;
		}
		if (s[q] == '0') {
			a0 = 1;
		}
	}
	k = a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9;
	std::cout << k << '\n';
	for (int q = s.length(); q > 0; q--) {
		if (s[q] == requiredElement) {
			std::cout << s.length() - q - 1 << " ";
		}
	}
}

