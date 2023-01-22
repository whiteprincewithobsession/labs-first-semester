#include <windows.h>
#include <iostream>
#include "libCheck.h"
extern "C" __declspec(dllexport) bool qCheck(long double* array, int left, int right) {
	int i, j;
	long double x;
	i = left; j = right;
	do {
		while (array[i] < 0 && i < right) i++;
		while (0 > array[j] && j > left) j--;
		if (i <= j) {
			if (array[i] > 0 || array[j] > 0) return false;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) qCheck(array, left, j);
	if (right > i) qCheck(array, i, right);
	return true;
}

extern "C" __declspec(dllexport) void t2() {
	while (true) {
		std::cout << "Task 2. Created by Yaroslav Yastremskiy.\nHere created a function, which will check the array to contain only negative numbers";
		char inputValidation[10000];
		const int N = 10;
		std::cout << "\n\n******************************\n\nYou have an array with size for " << N << " elements\n\n";
		long double Y[N];
		for (int i = 0; i < N; i++) {
			std::cout << "Enter the " << i + 1 << " element:\n";
			std::cin >> inputValidation;
			checkDouble(inputValidation);
			rewind(stdin);
			Y[i] = atof(inputValidation);
		}
		bool a = qCheck(Y, 0, N - 1);
		if (a == false) {
			std::cout << "This array has natural numbers";
		}
		if (a == true) {
			std::cout << "All elements are less than zero";
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
		if (userChoice == 'n' || userChoice == 'N') exit(1);
	}
}