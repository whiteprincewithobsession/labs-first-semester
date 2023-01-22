#include "pch.h"
long long evenCounter(long long** array, long long rows, long long cols);
long long evenMult(long long** array, long long rows, long long cols);
long long evenElDiagonale(long long** array, long long rows, long long cols);



TEST(test_task3_longlongmaxplus) {
    long long** a = new long long* [3];
    a[0] = new long long [3] {1000000000000000000, 400, 999999999999};
    a[1] = new long long [3] {2999990, 5000000, 999999999999};
    a[2] = new long long [3] {999999999999, 800000000, 999999999999};
    ASSERT_EQ(evenMult(a, 3, 3), 5000000000000);
}

TEST(test_task3_intmaxminus) {
    long long** a = new long long* [3];
    a[0] = new long long [3] {-1000000, 400, 999999999999};
    a[1] = new long long [3] {2999990, 5000000, 999999999999};
    a[2] = new long long [3] {999999999999, 800000000, 999999999999};
    ASSERT_EQ(evenMult(a, 3, 3), -5000000000000);
}


TEST(test_task3_1) {
    long long** a = new long long* [3];
    a[0] = new long long [3] {7654321, 262356125, 999999325125999};
    a[1] = new long long [3] {299992135690, 500078543000, 999991235125999};
    a[2] = new long long [3] {9134899999999999, 80000008634500, 999992351259999999};
    ASSERT_EQ(evenCounter(a, 3, 3), 1);
}

TEST(test_task3_2) {
    long long temp = 301;
    long long** ptrarray = new long long* [10];
    for (int count = 0; count < 10; count++)
        ptrarray[count] = new long long[10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ptrarray[i][j] = temp;
            temp -= 2;
        }
    }
    ASSERT_EQ(evenCounter(ptrarray, 10, 10), 0);
}

TEST(test_task3_3) {
    long long temp = 301;
    long long** ptrarray = new long long* [10];
    for (int count = 0; count < 10; count++)
        ptrarray[count] = new long long[10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ptrarray[i][j] = temp;
            temp -= 2;
        }
    }
    ASSERT_EQ(evenElDiagonale(ptrarray, 10, 10), 0);
}

TEST(test_task3_4) {
    long long temp = 16;
    long long** ptrarray = new long long* [3];
    for (int count = 0; count < 3; count++)
        ptrarray[count] = new long long[3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ptrarray[i][j] = temp;
            temp -= 2;
        }
    }
    ASSERT_EQ(evenElDiagonale(ptrarray, 3, 3), 1680);
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


long long evenElDiagonale(long long** array, long long rows, long long cols) {
    long long m = rows, n = cols, evenElement = 0, sum = 0;
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
    //if (count == 0) std::cout << "There are no even elements in diagonale";
    //else {
        //std::cout << "\nIn result:\n";
        for (int i = 0; i < count; i++) {
            sum += arrayEven[i] * pow(10, count - i - 1);
        }
   // }
    return sum;
}