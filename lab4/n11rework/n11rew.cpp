#include <iostream>
#include <stdlib.h>
#include "/all labs/lab4/bestcheck/top.h"





int main() {
    std::cout << "It's a simple field of minesweeper, where you can enter: \n1)Size of field; \n2)Num of mines;\n3)Pos for mines";
	std::cout << "\nIt was created by Yaroslav Yastremskiy, in the table my num is 14";
	std::cout << "\n\nUse the correct input, be a good user! " << "\n\n***********************\n\n";

	int n, m, countMines, minusCounter = 0;
	char inputValidation[2000000];
	char input;
    while(true){
	std::cout << "\nEnter the field height: ";
	std::cin >> inputValidation;
	while (isInt(inputValidation) == 0 || atoi(inputValidation) <= 1 || stringLength(inputValidation) > 5 || atoi(inputValidation) > 100000) {
		std::cout << "Wrong input. Try again.\n";
		std::cin >> inputValidation;
	}
	n = atoi(inputValidation);
	rewind(stdin);

	std::cout << "Enter the width of field: ";
	std::cin >> inputValidation;
	while (isInt(inputValidation) == 0 || stringLength(inputValidation) > 5 || atoi(inputValidation) <= 1 || atoi(inputValidation) > 100000) {
		std::cout << "Wrong input. Try again.\n";
		std::cin >> inputValidation;
	}
	m = atoi(inputValidation);
	rewind(stdin);
	char** field = NULL;
	field = (char**)calloc(sizeof(char) * (n + 2), '0');
	for (int i = 0; i < n + 2; i++) {
		field[i] = (char*)calloc((m + 2) * sizeof(char), '0');
	}
	std::cout << "Enter all field:\n";
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			//std::cout << "Enter the [" << i << "][" << j << "] position: ";
			std::cin >> input;
			while (input != '*' && input != '.') {
				std::cout << "Wrong input.Try again\n";
				rewind(stdin);
				std::cin >> input;
			}
			field[i][j] = input;
			//rewind(stdin);
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			countMines = 0;
			if (field[i][j] == '*') continue;
			else {
				if (field[i - 1][j - 1] == '*') countMines++;
				if (field[i - 1][j] == '*') countMines++;
				if (field[i - 1][j + 1] == '*') countMines++;
				if (field[i][j + 1] == '*') countMines++;
				if (field[i + 1][j + 1] == '*') countMines++;
				if (field[i + 1][j] == '*') countMines++;
				if (field[i + 1][j - 1] == '*') countMines++;
				if (field[i][j - 1] == '*') countMines++;
				if (countMines != 0) field[i][j] = countMines + '0';
				else field[i][j] = '.';
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			std::cout << field[i][j] << " ";
		}
		std::cout << '\n';
	}
	for (int i = 0; i < n + 2; i++)
		delete[] field[i];
    
    
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



