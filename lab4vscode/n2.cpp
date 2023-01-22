#include <iostream>
#include "D:\all labs\lab4\bestcheck\top.h"
#define colst2 5
#define rowst2 5

int main() {
	char inputValidation[200000];
	std::cout << "In this task user can enter all elements of matrix 5x5 and computer will multiply all elements in odd columns";
	std::cout << "\nCreated by Yaroslav Yastremskiy, variant 14\n\n\n";
	while (true) {
		long double arr[rowst2][colst2], totalProduct = 1;
	for (int i = 0; i < rowst2; i++) {
		for (int q = 0; q < colst2; q++) {
			std::cout << "Enter the (" << i + 1 << "x" << q + 1 << ") element" << '\n';
			std::cin >> inputValidation;
			while (isInt(inputValidation) != 1 || stringLength(inputValidation) > 11) {
				std::cout << "Wrong input. Try again.\n";
				std::cin >> inputValidation;
			}
			arr[i][q] = atoi(inputValidation);
			rewind(stdin);
		}
	}
	for (int i = 0; i < rowst2; i++) {
		if ((i + 1) % 2 == 1) {
			for (int q = 0; q < colst2; q++) {
				totalProduct *= arr[q][i];
			}
		}
	}
	std::cout << "Total multiplication = " << totalProduct;
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