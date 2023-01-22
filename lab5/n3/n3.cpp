#include "/all labs/lab4/bestcheck/top.h"
#include <iostream>
long long evenCounter(long long** array, long long rows, long long cols);
long long evenMult(long long** array, long long rows, long long cols);
void evenElDiagonale(long long** array, long long rows, long long cols);

int main() {
    std::cout << "Task 3. Made by Yaroslav Yastremskiy.\nHere user enter the size of two-dim array\nProgramm will input the even elements of main diagonale in new array";
    std::cout << " and then output all new array\n(if new size = 0, it will say about it)\n\n*******************************************\n\n";
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
    long long** array = new long long* [m];
    for (int i = 0; i < m; i++) {
        array[i] = new long long[n];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "Enter the [" << i + 1 << "][" << j + 1 << "] element" << '\n';
            std::cin >> inputValidation;
            checkInt(inputValidation);
            array[i][j] = atoi(inputValidation);
            rewind(stdin);
        }
    }
    long long* arrayEven = new long long[evenCounter(array, m, n)];
    long long evenElement = 0;

    evenElDiagonale(array, m, n);
    evenMult(array, m, n);
    if (evenMult(array, m, n) == -1) {
        std::cout << "\n\nThere are no elements for multiplication\n\n";
    }
    else std::cout << "\n\nTotal multiplication = " << evenMult(array, m, n) << '\n';
    return 0;
}


void evenElDiagonale(long long** array, long long rows, long long cols) {
    long long m = rows, n = cols, evenElement = 0;
    long long count = evenCounter(array, rows, cols);
    long long row = 0, col = 0;
    long long* arrayEven = new long long[count];
    long long mult = 1;
    col = 0;
    for (int i = 0; i < count; i++) {
        for (row = 0; row < m; row++) {
            if (array[row][col] % 2 == 0) {
                arrayEven[evenElement] = array[row][col];
                evenElement++;
            }
            if (row == m - 1 || col == n - 1) {
                break;
            }
            col++;
        }
    }
    if (count == 0) std::cout << "There are no even elements in diagonale";
    else {
        std::cout << "\nIn result:\n";
        for (int i = 0; i < count; i++
            ) {
            std::cout << arrayEven[i] << " ";
        }
    }
}

long long evenCounter(long long** array, long long rows, long long cols) {
    long long m = rows, n = cols;
    long long row = 0, col = 0, countEven = 0;
    for (row = 0; row < m; row++) {
        if (array[row][col] % 2 == 0) {
            countEven++;
        }
        if (row == m - 1 || col == n - 1) {
            break;
        }
        col++;
    }
    return countEven;
}
long long evenMult(long long** array, long long rows, long long cols) {
    long long m = rows, n = cols, mult = 1;
    long long row = 0, col = 0, countEven = 0;
    for (row = 0; row < m; row++) {
        if (array[row][col] % 2 == 0) {
            countEven++;
            mult *= array[row][col];
        }
        if (row == m - 1 || col == n - 1) {
            break;
        }
        col++;

    }
    if (countEven == 0) return -1;
    else return mult;
}
