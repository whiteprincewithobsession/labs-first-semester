#include <iostream>
#include <algorithm>
int main() {
    long long m, n;
    std::cin >> m >> n;
    long double** array = new long double* [m];
    for (int count = 0; count < n; count++)
        array[count] = new long double[n];
    for (int i = 0; i < m; i++) {
        for (int q = 0; q < n; q++) {
            std::cin >> array[i][q];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int q = 0; q < n; q++) {
            if (i == 0 && q == 0) {
                continue;
            }
            else if(i == 0 && q != 0){
                if (array[i][q] < array[i][q - 1]) {
                    array[i][q] = array[i][q - 1];
                }
            }
            else if (q == 0 && i != 0) {
                if (array[i][q] < array[i - 1][q]) {
                    array[i][q] = array[i - 1][q];
                }
            }
            else if(q != 0 && i != 0) {
                if (array[i][q] < array[i][q - 1] || array[i][q] < array[i - 1][q]) {
                    array[i][q] = std::max(array[i][q - 1], array[i - 1][q]);
                }
            }
        }
    }
    std::cout << "\n\n";
    for (int i = 0; i < m; i++) {
        for (int q = 0; q < n; q++) {
            std::cout << array[i][q] << " ";
        }
        std::cout << '\n';
    }
}