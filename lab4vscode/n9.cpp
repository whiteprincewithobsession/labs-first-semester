#include <iostream>
#include <stdlib.h>
#include "/all labs/lab4/bestcheck/top.h"

int main() {
    std::cout << "Task 9, created by Yaroslav Yastremskiy\n\n\n";
    std::cout << "Here user can enter the length of cubic matrix(length of rows, columns and block are the same)\n";
    std::cout << "Then the program will output the biggest diagonal and its terms\n\n\n";
    while (true){
        char inputValidation[200000];
	int h = 1;
	long long*** arr;
	long long i, g, d1 = 0, d2 = 0, d3 = 0, d4 = 0, n, j;
	std::cout << "Enter the length of edge: ";
	std::cin >> inputValidation;
	while (isInt(inputValidation) != 1 || stringLength(inputValidation) > 5 || atoi(inputValidation) <= 1 || atoi(inputValidation) > 1000) {
		std::cout << "Wrong input. Try again.\n";
		std::cin >> inputValidation;
	}
	n = atoi(inputValidation);
	rewind(stdin);
	arr = (long long***)malloc(sizeof(long long***) * n);
	for (i = 0; i < n; i++)
	{
		arr[i] = (long long**)malloc(sizeof(long long*) * n);
		for (j = 0; j < n; j++)
		{
			arr[i][j] = (long long*)malloc(sizeof(long long) * n);
		}
	}
	for (long long q = 0; q < n; q++) {
		for (long long k = 0; k < n; k++) {
			for (long long f = 0; f < n; f++) {
				std::cout << "Enter the " << q + 1 << "x" << k + 1 << "x" << f + 1 << " element: ";
				std::cin >> inputValidation;
				while (isInt(inputValidation) != 1 || atof(inputValidation) < 0 || stringLength(inputValidation) > 15) {
					std::cout << "Wrong input. Try again.\n";
					std::cin >> inputValidation;
				}
				arr[q][k][f] = atoi(inputValidation);
				rewind(stdin);
			}
		}
	}
	for (long long q = 0; q < n; q++) {
		d1 += arr[q][q][q];
	}
	for (long long q = 0, m = n - 1; q < n; q++) {
		d2 += arr[q][q][m];
		m--;
	}
	for (long long q = 0, m = n - 1; q < n; q++) {
		d3 += arr[q][m][m];
		m--;
	}
	for (long long q = 0, m = n - 1; q < n; q++) {
		d4 += arr[q][m][q];
		m--;
	}
	//std::cout << '\n' << "d1 = " << d1 << " d2 = " << d2 << " d3 = " << d3 << " d4 = " << d4 << "\n\n";
	if (d1 >= d2 && d1 >= d3 && d1 >= d4) {
		std::cout << "Elements: ";
		for (long long q = 0; q < n; q++) {
			std::cout << arr[q][q][q] << " ";
		}
		std::cout << "\nmax is d1 = " << d1;

	}
	else if (d2 > d1 && d2 >= d3 && d2 >= d4) {
		std::cout << "Elements: ";
		for (long long q = 0, m = n - 1; q < n; q++) {
			std::cout << arr[q][q][m] << " ";
			m--;
		}
		std::cout << "\nmax is d2 = " << d2;
	}
	if (d3 > d1 && d3 > d2 && d3 >= d4) {
		std::cout << "Elements: ";
		for (long long q = 0, m = n - 1; q < n; q++) {
			std::cout << arr[q][m][m] << " ";
			m--;
		}
		std::cout << "\nmax is d3 = " << d3;
	}
	if (d4 > d1 && d4 > d2 && d4 > d3) {
		std::cout << "Elements: ";
		for (long long q = 0, m = n - 1; q < n; q++) {
			std::cout << arr[q][m][q] << " ";
			m--;
		}
		std::cout << "\nmax is d4 = " << d4;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) free(arr[i][j]);
	}
	for (i = 0; i < n; i++) free(arr[i]);
	free(arr);

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