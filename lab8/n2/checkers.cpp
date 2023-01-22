#define _CRT_SECURE_NO_WARNINGS
#include "/all labs/lab4/bestcheck/top.h"
void taskInfo() {
	printf("Task2. Variant 14. Created by Yaroslav Yastremskiy\n\n");
	printf("The list of goods in stock includes the name goods, quantity, unit price and receipt onstock.");
	printf("\n\nTask: Display in alphabetical order a list of products stored more months and cost more than 10.574rub");
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
	while (isInt(array) != 1 || atoi(array) < 1 || stringLength(array) > 5 || atoi(array) > 6) {
		std::cout << "Choose only from 1 to 6. Try again\n";
		std::cin >> array;
	}
}
int checkDays(int days) {
	if (days > 31 || days < 1) return 0;
	return 1;
}
int checkMonths(int months) {
	if (months < 0 || months > 12) return 0;
	return 1;
}
int checkYears(int years) {
	if (years > 2022 || years < 2010) return 0;
	return 1;
}
int isFullName(char array[]) {
	for (int i = 0; i < stringLength(array); i++) {
		if (i == 0) {
			if (array[i] < 'A' || array[i] > 'Z') return 0;
		}
		else if (array[i] < 'a' || array[i] > 'z') return 0;
	}
	return 1;
}
void checkFullName(char array[]) {
	scanf("%s", array);
	while (isFullName(array) != 1) {
		std::cout << "Only symbols (A - Z), (a - z). Try again\n";
		rewind(stdin);
		scanf("%s", array);
	}
}
void checkDouble1(char array[]) {
	std::cin >> array;
	while (isFloat(array) != 1 || stringLength(array) > 7 || atof(array) < 0) {
		std::cout << "Wrong input.Try again\n";
		rewind(stdin);
		std::cin >> array;
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
	while (isInt(array) != 1 || atoi(array) < 0 || stringLength(array) > 5) {
		std::cout << "Wrong input or your num is incorrect(too big or 0 - 1). Try again\n";
		std::cin >> array;
	}
}