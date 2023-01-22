long long countZeros(long double** array, long long rows, long long cols) {
	long long counter = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (array[i][j] == 0) {
				counter++;
				std::cout << "Element [" << i << "][" << j << "] is zero\n";
			}
		}
	}
	return counter;
}

void reverseOutput(long double** array, long long m, long long n) {
	std::cout << "Array in reverse:\n";
	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			std::cout << array[i][j] << " ";
		}
		std::cout << '\n';
	}
}

void t4() {
    std::cout << "Task 4.Made by Yaroslav Yastremskiy.\nAfter inputting two-dim array programm will count all elements which are equal zero\nAnd output this array in reverse";
    std::cout << "\n\n************************\n\n";
    char inputValidation[100000];
    long long m, n;
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
    long double** array = new long double* [m];
    for (int i = 0; i < m; i++)
        array[i] = new long double[n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "Enter the [" << i + 1 << "][" << j + 1 << "] element" << '\n';
            std::cin >> inputValidation;
            checkDouble(inputValidation);
            array[i][j] = atof(inputValidation);
            rewind(stdin);
        }
    }
    countZeros(array, m, n);
    std::cout << "\nTotal zeros in array = " << countZeros(array, m, n) << '\n';
    reverseOutput(array, m, n);
}