 #include <iostream>
 #include <stdlib.h>
 #include "D:\all labs\lab4\bestcheck\top.h"

 int main() {
	std::cout << "Task 13, created by Yaroslav Yastremskiy, variant 14";
	std::cout << "\nHere you can enter the order of square and computer will built Magic Square for you(it must be more than 2)\n\n\n\n**********************\n\n\n";
	while(true){
    long long n, element = 1;
	long long** mSquare = NULL;
	char inputValidation[200000];
	std::cout << "Enter the order of Magic Square: ";
	std::cin >> inputValidation;
	while (isInt(inputValidation) != 1 || atoi(inputValidation) < 3 || atoi(inputValidation) > 35000) {
		std::cout << "Size not correct. Try again\n";
		std::cin >> inputValidation;
	}
	n = atoi(inputValidation);
	mSquare = (long long**)malloc(n * sizeof(long long*));
	for (long long i = 0; i < n; i++) {
		mSquare[i] = (long long*)calloc(n, sizeof(long long));
	}

	if (n % 2 == 1) {
		int rowOdd = 0, colOdd = n / 2;
		for (int q = 1; q <= n * n; q++) {
			mSquare[rowOdd][colOdd] = q;
			rowOdd--; colOdd++;
			if (q % n == 0) {
				rowOdd += 2;
				--colOdd;
			}
			else {
				if (colOdd == n) {
					colOdd -= n;
				}
				else if (rowOdd < 0) {
					rowOdd += n;
				}
			}
		}
	}




	else if (n % 4 == 0) {
		for (int q = 0; q < n; q++) {
			for (int j = 0; j < n; j++) {
				if ((j >= n / 4 && j < 3 * n / 4) && q < n / 4) {
					mSquare[q][j] = element;
				}
				else if (j < n / 4 && (q >= n / 4 && q < 3 * n / 4)) {
					mSquare[q][j] = element;
				}
				else if (j >= 3 * n / 4 && (q >= n / 4 && q < 3 * n / 4)) {
					mSquare[q][j] = element;
				}
				else if (q >= 3 * n / 4 && (j >= n / 4 && j < 3 * n / 4)) {
					mSquare[q][j] = element;
				}
				element++;
			}
		}
		element = n * n;
		for (int q = 0; q < n; q++) {
			for (int j = 0; j < n; j++) {
				if (q < n / 4 && j < n / 4) {
					mSquare[q][j] = element;
				}
				else if (j >= 3 * n / 4 && q < n / 4) {
					mSquare[q][j] = element;
				}
				else if ((q >= n / 4 && q < 3 * n / 4) && (j >= n / 4 && j < 3 * n / 4)) {
					mSquare[q][j] = element;
				}
				else if (j < n / 4 && q >= 3 * n / 4) {
					mSquare[q][j] = element;
				}
				else if (j >= 3 * n / 4 && q >= 3 * n / 4) {
					mSquare[q][j] = element;
				}

				element--;
			}
		}
	}

	else if (n % 4 == 2) {
		int rowOdd1 = 0, colOdd1 = n / 4;
		for (int q = 1; q <= n / 2 * n / 2; q++) {
			mSquare[rowOdd1][colOdd1] = q;
			rowOdd1--; colOdd1++;
			if (q % (n / 2) == 0) {
				rowOdd1 += 2;
				--colOdd1;
			}
			else {
				if (colOdd1 == n / 2) {
					colOdd1 -= n / 2;
				}
				else if (rowOdd1 < 0) {
					rowOdd1 += n / 2;
				}
			}
		}
		int rowOdd2 = n / 2, colOdd2 = n / 4 * 3 + 1;
		for (int q = n / 2 * n / 2 + 1; q <= n * n / 2; q++) {
			mSquare[rowOdd2][colOdd2] = q;
			rowOdd2--; colOdd2++;
			if (q % (n / 2) == 0) {
				rowOdd2 += 2;
				--colOdd2;
			}
			else {
				if (colOdd2 == n) {
					colOdd2 -= n / 2;
				}
				else if (rowOdd2 < n / 2) {
					rowOdd2 += n / 2;
				}
			}
		}
		int rowOdd3 = 0, colOdd3 = n / 4 * 3 + 1;
		for (int q = n * n / 2 + 1; q <= 3 * n * n / 4; q++) {
			mSquare[rowOdd3][colOdd3] = q;
			rowOdd3--; colOdd3++;
			if (q % (n / 2) == 0) {
				rowOdd3 += 2;
				colOdd3 -= 1;
			}
			else {
				if (colOdd3 == n) {
					colOdd3 -= n / 2;
				}
				else if (rowOdd3 < 0) {
					rowOdd3 += n / 2;
				}
			}
		}
		int rowOdd4 = n / 2, colOdd4 = n / 4;
		for (int q = n * n * 3 / 4 + 1; q <= n * n; q++) {
			mSquare[rowOdd4][colOdd4] = q;
			rowOdd4--; colOdd4++;
			if (q % (n / 2) == 0) {
				rowOdd4 += 2;
				--colOdd4;
			}
			else {
				if (colOdd4 == n / 2) {
					colOdd4 -= n / 2;
				}
				else if (rowOdd4 < n / 2) {
					rowOdd4 += n / 2;
				}
			}
		}

		int length = n / 7, tempEl = 0, a = n / 2;
		int lenLastCol = length;
		for (int q = n - lenLastCol; q < n; q++) {
			a = n / 2;
			for (int i = 0; i < n / 2; i++) {
				tempEl = mSquare[i][q];
				mSquare[i][q] = mSquare[a][q];
				mSquare[a][q] = tempEl;
				a++;
			}
		}
		length = n / 7 + 1; a = n / 4 * 3 + 1;
		lenLastCol = length;
		int rowSwap = n / 7 + 1;
		for (int q = 1; q <= length; q++) {
			tempEl = mSquare[rowSwap][q];
			mSquare[rowSwap][q] = mSquare[a][q];
			mSquare[a][q] = tempEl;
		}

		int heightSquare = n / 7 + 1;
		a = n / 2;
		for (int q = 0; q < heightSquare; q++) {
			for (int i = 0; i < heightSquare; i++) {
				tempEl = mSquare[q][i];
				mSquare[q][i] = mSquare[a][i];
				mSquare[a][i] = tempEl;
			}
			a++;
		}

		a = n / 4 * 3 + 2;
		for (int q = n / 7 + 2; q < n / 2; q++) {
			a = n / 4 * 3 + 2;
			for (int i = 0; i < heightSquare; i++) {
				tempEl = mSquare[q][i];
				mSquare[q][i] = mSquare[a][i];
				mSquare[a][i] = tempEl;
			}
			a++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << mSquare[i][j] << " ";
		std::cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		free(mSquare[i]);
	}
	free(mSquare);
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
