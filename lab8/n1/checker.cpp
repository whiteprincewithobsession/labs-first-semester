#define _CRT_SECURE_NO_WARNINGS
#include "/all labs/lab4/bestcheck/top.h"
#include <stdio.h>
#include <iostream>


void checkIntStruct(char array[], int& size) {
	std::cin >> array;
	while (isInt(array) != 1 || atoi(array) < 1 || stringLength(array) > 5 || atoi(array) > size) {
		printf("Wrong input or your num is incorrect(too big or 0 - 1). Try again\n");
		std::cin >> array;
	}
}
void checkIntFunctions(char array[]) {
	std::cin >> array;
	while (isInt(array) != 1 || atoi(array) < 1 || stringLength(array) > 5 || atoi(array) > 7) {
		printf("Choose only from 1 to 6. Try again\n");
		std::cin >> array;
	}
}
void checkIntSize(char array[]) {
	std::cin >> array;
	while (isInt(array) != 1 || atoi(array) < 1 || stringLength(array) > 5) {
		printf("Only natural numbers(Max 999999). Try again\n");
		rewind(stdin);
		std::cin >> array;
	}
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
		printf("Only symbols (A - Z), (a - z). Try again\n");
		rewind(stdin);
		scanf("%s", array);
	}
}
void checkIntPoints(char array[]) {
	scanf_s("%s", array, 4);
	while (isInt(array) != 1 || atoi(array) < 0 || stringLength(array) > 3 || atoi(array) > 100) {
		printf("Enter from 1 to 100. Try again\n");
		rewind(stdin);
		scanf_s("%s", array, 4);
	}
}
void taskInfo() {
	printf("Task1. Variant 14. Created by Yaroslav Yastremskiy\n");
	printf("List of applicants who passed the entrance exams to the university.\nContains the full name of the applicant and his grades");
	printf("\n\n\n***********************************************************************************\n\n\n");
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
void checkIntNaturalSize1(char array[]) {
	std::cin >> array;
	while (isInt(array) != 1 || atoi(array) <= 1 || stringLength(array) > 5) {
		std::cout << "Wrong input or your num is incorrect(too big or 0 - 1). Try again\n";
		std::cin >> array;
	}
}
void checkInt1(char array[]) {
	while (isInt(array) != 1 || stringLength(array) > 5) {
		std::cout << "Wrong input or too big num.Try again\n";
		std::cin >> array;
	}
}
void checkDouble1(char array[]) {
	std::cin >> array;
	while (isFloat(array) != 1 || stringLength(array) > 7) {
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
void checkIntChoice(char array[]) {
	std::cin >> array;
	while (isInt(array) != 1 || stringLength(array) > 5 || atoi(array) > 6 || atoi(array) < 1) {
		std::cout << "Wrong input or too big num.Try again\n";
		std::cin >> array;
	}
}