#include "/all labs/lab4/bestcheck/top.h"
#include <iostream> 


long long oddInEven(long long** array, long long rows, long long cols) {
	long long sum = 0, oddCounter = 0;
	for (int j = 0; j < cols; j++) {
		if (j % 2 == 0) {
			for (int q = 0; q < cols; q++) {
				if (array[q][j] % 2 == 1) {
					oddCounter++;
					sum += array[q][j];
				}
			}
		}
	}
	if (oddCounter != 0) return oddCounter;
	else return -1;
}

long double oddInEvenAverageSum(long long** array, long long rows, long long cols) {
	long double sum = 0, oddCounter = 0;
	for (int j = 0; j < cols; j++) {
		if (j % 2 == 0) {
			for (int q = 0; q < cols; q++) {
				if (array[q][j] % 2 == 1) {
					oddCounter++;
					sum += array[q][j];
				}
			}
		}
	}
	if (oddCounter != 0) return sum /= oddCounter;
	else return -1;
}

void oddMassive(long long** array, long long m, long long n) {
	if (oddInEven(array, m, n) == -1) {
		std::cout << "There are no odd elements";
	}
	else {
		long long f = 0;
		long long* array2 = new long long[oddInEven(array, m, n)];
		std::cout << "As a result:\n";
		for (int j = 0; j < n; j++) {
			if (j % 2 == 0) {
				for (int q = 0; q < n; q++) {
					if (array[q][j] % 2 == 1) {
						array2[f] = array[q][j];
						std::cout << array2[f] << " ";
						f++;
					}
				}
			}
		}
		std::cout << '\n' << "Average sum = " << oddInEvenAverageSum(array, m, n);
	}
}




int main() {
	std::cout << "Task 5. Created by Yaroslav Yastremskiy.\nAfter entering two-dim array, programm wil find odd elements in even columns";
	std::cout << "\nNext step wiil be counting average sum of this elements and outputting them on the screen";
	std::cout << "\n\n**********************************\n\n";
	char inputValidation[100000];
	long long m, n, oddCounter = 0;
	long double sum = 0;
	std::cout << "Enter the num of rows:\n";
	std::cin >> inputValidation;
	checkIntNaturalSize(inputValidation);
	m = atoi(inputValidation);
	rewind(stdin);
	std::cout << "Enter the num of cols:\n";
	std::cin >> inputValidation;
	checkIntNaturalSize(inputValidation);
	n = atoi(inputValidation);
	rewind(stdin);
	long long** array = new long long* [m];
	for (int i = 0; i < m; i++)
		array[i] = new long long[n];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << "Enter the [" << i + 1 << "][" << j + 1 << "] element" << '\n';
			std::cin >> inputValidation;
			checkInt(inputValidation);
			array[i][j] = atoi(inputValidation);
			rewind(stdin);
		}
	}
	oddMassive(array, m, n);
	
}