#include <iostream>
#include "D:\all labs\lab4\bestcheck\top.h"
#define xt1 10

int main() {
	std::cout << "\nTask 1, Variant 14\nHere you can enter the 10 elements in massive\nThen all elements, which are lesser then average sum, will be deleted\n\n";
	std::cout << "\nCreator Yaroslav Yastremskiy\nIn list my number - 14\n\n";
	while (true) {
		char inputValidation[200000];
		long long countElements = 0;
		long double averageSum = 0;
		long double arr[xt1], arr2[xt1];
		for (int i = 0; i < xt1; i++) {
			std::cout << "Enter the " << i + 1 << " element\n";
			std::cin >> inputValidation;
			while (isFloat(inputValidation) != 1 || stringLength(inputValidation) > 15) {
				std::cout << "Wrong input. Try again.\n";
				std::cin >> inputValidation;
			}
			arr[i] = atof(inputValidation);
			rewind(stdin);
		}
		for (int i = 0; i < xt1; i++) {
			averageSum += arr[i];
		}
		averageSum /= xt1;
		std::cout << '\n' << "Average sum = " << averageSum << '\n';
		for (int i = 0, q = 0; i < xt1; i++) {
			if (arr[i] >= averageSum) {
				countElements++;
				arr2[q] = arr[i];
				q++;
			}
			else {
				continue;
			}
		}
		std::cout << "Num of elements above average or equal " << countElements << '\n';
		std::cout << "Massive after transformations: \n";
		for (int i = 0; i < countElements; i++) {
			std::cout << arr2[i] << " ";
		}

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
