#define _CRT_SECURE_NO_WARNINGS
#include "/all labs/lab4/bestcheck/top.h"
void taskInfo() {
	printf("Task3. Variant 9(T2). Created by Yaroslav Yastremskiy\n\n");
	printf("For books are given : the registration of the book, author, title, year, publisher, num of pages.");
	printf("\n\nWithdraw a list of books with authors' names in alphabetical order published after given year");
	printf("\n\n\n************************************************************************************\n\n\n");
}
void checkIntSize(char array[]) {
	std::cin >> array;
	while (isInt(array) != 1 || atoi(array) < 1 || stringLength(array) > 5) {
		std::cout << "Only natural numbers(Max 999999). Try again\n";
		rewind(stdin);
		std::cin >> array;
	}
}
void checkIntStruct(char array[], int& size) {
	std::cin >> array;
	while (isInt(array) != 1 || atoi(array) < 1 || stringLength(array) > 5 || atoi(array) > size) {
		std::cout << "Wrong input or your num is incorrect(enter from " << 1 << " to " << size << "). Try again\n";
		std::cin >> array;
	}
}
void checkIntFunctions(char array[]) {
	std::cin >> array;
	while (isInt(array) != 1 || atoi(array) < 1 || stringLength(array) > 5 || atoi(array) > 8) {
		std::cout << "Choose only from 1 to 6. Try again\n";
		std::cin >> array;
	}
}

void checkIntYears(char array[]) {
	scanf_s("%s", array, 6);
	while (isInt(array) != 1 || atoi(array) < 1000 || stringLength(array) > 6 || atoi(array) > 2023) {
		std::cout << "Enter from 2012 to 2022. Try again\n";
		scanf_s("%s", array, 10);
		fflush(stdin);
	}
}
int choice1() {
	std::cout << "\nDo you want to continue? (y / n) ";
	char inputValidation[10000];
	char userChoice;
	std::cin >> inputValidation;
	while (stringLength(inputValidation) > 1 || (inputValidation[0] != 'y' && inputValidation[0] != 'n' && inputValidation[0] != 'N' && inputValidation[0] != 'Y')) {
		std::cout << "Wrong input. Try again.\n";
		std::cout << '\n' << "Do you want to continue? (y / n) ";
		rewind(stdin);
		std::cin >> inputValidation;
	}
	userChoice = inputValidation[0];
	std::cout << "\n\n";
	if (userChoice == 'n' || userChoice == 'N') return 0;
}
void checkIntNatural1(char* array) {
	std::cin >> array;
	while (isInt(array) != 1 || atoi(array) <= 0 || stringLength(array) > 5) {
		std::cout << "Wrong input or your num is incorrect(too big or 0 - 1). Try again\n";
		std::cin >> array;
	}
}
void checkIntFunctionsChoice(char array[]) {
	std::cin >> array;
	while (isInt(array) != 1 || atoi(array) < 1 || stringLength(array) > 5 || atoi(array) > 6) {
		printf("Choose only from 1 to 6. Try again\n");
		std::cin >> array;
	}
}
void checkIntChoice(char array[]) {
	std::cin >> array;
	while (isInt(array) != 1 || stringLength(array) > 5 || atoi(array) > 6 || atoi(array) < 1) {
		std::cout << "Wrong input.Try again\n";
		std::cin >> array;
	}
}
int isInt1(char array[]) {
	if (array[0] == '-' || (array[0] >= '0' && array[0] <= '9') || array[0] == '+') {
		if ((array[0] == '-' && stringLength(array) == 1)) return 0;
		if ((array[0] == '+') && stringLength(array) == 1) return 0;
		//if (array[0] == '0' && array[1] != 0) return 0;
		else {
			for (int i = 1; i < stringLength(array); i++) {
				if (array[i] < '0' || array[i] > '9') return 0;
			}
			return 1;
		}
	}
	else return 0;
}
void checkIntNaturalSize1(char array[]) {
	std::cin >> array;
	while (isInt(array) != 1 || atoi(array) <= 1 || stringLength(array) > 5) {
		std::cout << "Wrong input or your num is incorrect(too big or 0 - 1). Try again\n";
		std::cin >> array;
	}
}