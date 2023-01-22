#include <iostream>
#include <stdio.h>
#include "/all labs/lab4/bestcheck/top.h"
int main() {
    char inputValidation[100];
    long double sum = 0;
    long double mult = 1;
    int numRowCol;
    std::cout << "In this task, the user enters the number of rows in a square matrix, after which the sum and product of the left and right triangles enclosed between the diagonals are calculated\n";
    std::cout << "Made by Yaroslav Yastremskiy, variant 14\n";
    while (true) {
        sum = 0;
        mult = 1;
        std::cout << "Enter the num of rows in massive: ";
	std::cin >> inputValidation;
	while (isInt(inputValidation) == 0 || atoi(inputValidation) <= 1 || stringLength(inputValidation) > 4 || atoi(inputValidation) > 30000) {
		std::cout << "Wrong input. Try again.\n";
		std::cin >> inputValidation;
	}
	numRowCol = atoi(inputValidation);
	rewind(stdin);
	long double** array = new long double* [numRowCol];
	for (int count = 0; count < numRowCol; count++) {
		array[count] = new long double[numRowCol];
	}
	for (int i = 0; i < numRowCol; i++) {
		for (int j = 0; j < numRowCol; j++) {
			std::cout << "Enter the (" << i + 1 << "x" << j + 1 << ") element \n";
			std::cin >> inputValidation;
			while (isFloat(inputValidation) != 1 || stringLength(inputValidation) > 15 || atof(inputValidation) > 1e12) {
				std::cout << "Wrong input. Try again.\n";
				std::cin >> inputValidation;
			}
			array[i][j] = atof(inputValidation);
		}
	}
	int leftSize = numRowCol / 2;
	if (numRowCol % 2 == 1) {
		sum += array[leftSize][leftSize];
		mult *= array[leftSize][leftSize];
	}
	for (int j = 0; j < leftSize; j++) {
		for (int i = 0 + j; i < numRowCol - j; i++) {
			sum += array[i][j];
			mult *= array[i][j];
		}
	}
	for (int j = numRowCol - 1, k = 0; j > numRowCol - leftSize - 1; j--, k++) {
		for (int i = 0 + k; i < numRowCol - k; i++) {
			sum += array[i][j];
			mult *= array[i][j];
		}
	}

	std::cout << "Summary = " << sum;
	std::cout << "\nMultiplication = " << mult;

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

