int sum(int a, int b);
void t1() {
    std::cout << "Task 1. Variant 15. Made by Yaroslav Yastremskiy\nIn this problem user can enter the size of matrix and its elements\nThen programm will find saddle points, if its possible";
    std::cout << "\n\n\n********************\n\n\n";
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
    for (int i = 0; i < m; i++) {
        array[i] = new long double[n];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "Enter the [" << i + 1 << "][" << j + 1 << "] element" << '\n';
            std::cin >> inputValidation;
            checkDouble(inputValidation);
            array[i][j] = atof(inputValidation);
            rewind(stdin);
        }
    }
    std::cout << "Input array:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << '\n';
    }
    saddlePoints(array, m, n);

}
