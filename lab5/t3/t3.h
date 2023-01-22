
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

