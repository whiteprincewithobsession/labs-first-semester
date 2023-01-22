#include <iostream>
#include "/all labs/lab4/bestcheck/top.h"

int main() {
	while (true) {
		char inputValidation[_MAX_INT_DIG];
		void t4();
		std::cout << '\n' << "Do you want to continue? (y / n) ";
		char userChoice;
		int counter = 0;
		std::cin >> inputValidation;
		while (stringLength(inputValidation) > 1 || (inputValidation[0] != 'y' && inputValidation[0] != 'n' && inputValidation[0] != 'N' && inputValidation[0] != 'Y')) {
			std::cout << "Wrong input. Try again.\n";
			std::cout << '\n' << "Do you want to continue? (y / n) ";
			rewind(stdin);
			std::cin >> inputValidation;
		}
		userChoice = inputValidation[0];
		if (userChoice == 'n' || userChoice == 'N') return 0;
	}
}