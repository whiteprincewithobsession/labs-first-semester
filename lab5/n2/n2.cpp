#include "/all labs/lab4/bestcheck/top.h"
#include <iostream>
#include <Windows.h>


int main() {
	std::cout << "Task 2. Created by Yaroslav Yastremskiy.\nHere created a function, which will check the array to contain only positive numbers";
	char inputValidation[10000];
	const int N = 10;
	HINSTANCE load;
	load = LoadLibrary(L"DynamicLiib.dll");
	typedef bool (*qCheck) (long double*, int, int);
	qCheck Qcheck;
	std::cout << "\n\n******************************\n\nYou have an array with size for " << N << " elements\n\n";
	long double Y[N];
	for (int i = 0; i < N; i++) {
		std::cout << "Enter the " << i + 1 << " element:\n";
		std::cin >> inputValidation;
		checkDouble(inputValidation);
		rewind(stdin);
		Y[i] = atof(inputValidation);
	}
	Qcheck = (qCheck)GetProcAddress(load, "qCheck");
	if (Qcheck(Y, 0, N - 1) == false) {
		std::cout << "This array has natural numbers";
	}
	if (Qcheck(Y, 0, N - 1) == true) {
		std::cout << "All elements are less than zero";
	}
}
