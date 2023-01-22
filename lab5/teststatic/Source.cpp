#include "/all labs/lab4/bestcheck/top.h"
#include <iostream>


void saddlePoints(long double** array, long long rows, long long cols) {
    long long m = rows, n = cols;
    std::cout << "\n\nOutput array:\n";
    long double tempPoint;
    int saddlePoint = 0, f, numSimilar;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            numSimilar = 0;
            int inRow = 0, inCol = 0;
            tempPoint = array[i][j];
            for (inRow = 0; inRow < n; inRow++) {
                if (array[i][inRow] < tempPoint) {
                    numSimilar++;
                }
            }
            for (inCol = 0; inCol < m; inCol++) {
                if (array[inCol][j] > tempPoint) {
                    numSimilar++;
                }
            }
            if (numSimilar == 0) {
                std::cout << array[i][j] << " ";
                saddlePoint++;
            }
            else std::cout << 0 << " ";
        }
        std::cout << '\n';
    }
    if (saddlePoint == 0) std::cout << "\nTHERE ARE NO SADDLE POINTS\n";

}


void task() {
    while (true) {
        std::cout << "Task 1. Variant 15. Made by Yaroslav Yastremskiy\nIn this problem user can enter the size of matrix and its elements\nThen programm will find saddle points, if its possible";
        std::cout << "\n\n\n********************\n\n\n";
        char inputValidation[10000];
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

