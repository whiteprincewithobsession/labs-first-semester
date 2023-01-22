#include "/all labs/lab4/bestcheck/top.h"
#include <iostream>
#include <string>
#include <algorithm>

void checkIntNaturalSize9(char array[]) {
	std::cin >> array;
	while (isInt(array) != 1 || atoi(array) <= 1 || stringLength(array) > 5 || atoi(array) > 240) {
		std::cout << "Wrong input or your num is incorrect(enter from 1 to 240). Try again\n";
		std::cin >> array;
	}
}

std::string numToTernary(int a) { //O(log3(a))
	std::string num;
	while (a != 0) {
		num.push_back((a % 3) + '0');
		a /= 3;
	}
	while (num.length() != 5) {
		num.push_back('0');
	}
	std::reverse(num.begin(), num.end());
	return num;
}

int main() {
	std::cout << "Task9. Created by Yaroslav Yastremskiy\n";
	std::cout << "Algorithms works in ternary system and contains\nEach rank of ternary form means the day in which slave drunk the wine in barrel\n\n";
	char inputValidation[10000];
	int slaves[5];
	std::string barrels[241];
	int pBarrel;
	while (true) {
		std::cout << "Enter the poisoned barrel: ";
		//std::cin >> inputValidation;
		checkIntNaturalSize9(inputValidation );
		pBarrel = atoi(inputValidation);
		std::string poisoned = numToTernary(pBarrel);
		std::cout << "\nIn which day slave[i] will drunk poisoned barrel(if 0, neither of 2)\n\n";
		for (int i = 0; i < 5; i++) { //O(5)
			slaves[i] = poisoned[i] - '0';
		}
		for (int i = 0; i < 5; i++) { //O(5)
			std::cout << slaves[i] << " ";
		}
		std::cout << "\n\n";
		for (int i = 1; i <= 240; i++) { //O(240)
			barrels[i] = numToTernary(i);
			std::cout << "Code of barrel " << i << " = " << barrels[i] << '\n';
		}
		std::cout << "\n\nFirst day lasts:\n";
		for (int i = 0; i < 5; i++) { //O(5)
			if (slaves[i] == 0 || slaves[i] == 2) {
				std::cout << "Slave " << i + 1 << " alive\n";
			}
			if (slaves[i] == 1) {
				std::cout << "Slave " << i + 1 << " will die after 24 hours\n";
				slaves[i] *= 3;
			}
		}
		std::cout << "\n\nAfter second day:\n\n";
		for (int i = 0; i < 5; i++) { //O(5)
			if (slaves[i] == 3) continue;
			if (slaves[i] == 0) {
				std::cout << "Slave " << i + 1 << " will be alive\n";
			}
			if (slaves[i] == 2) {
				std::cout << "Slave " << i + 1 << " will die after 48 hours\n";
				slaves[i] *= 3;
			}
		}
		std::cout << "\n\nIn total, dead: ";
		for (int i = 0; i < 5; i++) { //O(5)
			if (slaves[i] == 3 || slaves[i] == 6) std::cout << i + 1 << " ";
		}
		std::cout << "\n\n\nIn total, alive: ";
		for (int i = 0; i < 5; i++)  {//O(5)
			if (slaves[i] == 0) std::cout << i + 1 << " ";
		}
		std::cout << "\n\nWith information of drunked barrels and deaths we can form code\n\n";
		for (int i = 0; i < 5; i++) {
			slaves[i] /= 3;
			std::cout << slaves[i];
		}
		int sum = 0;
		std::cout << "\n\nBarrel is ";
		for (int i = 4; i >= 0; i--) { //O(5)
			sum += slaves[i] * powl(3, 4 - i);
		}
		std::cout << sum << '\n';
		if (choice() == 0) return 0;
	}
}