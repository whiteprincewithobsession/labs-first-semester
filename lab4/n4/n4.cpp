#include <iostream>

int main() {
    long long k, g, countLoc = 0;
    std::cin >> k >> g;
    long long **a = new long long* [k + 2];
    for (int i = 0; i <= k + 2; i++) {
        a[i] = new long long[g + 2];
    }
    for (int i = 0; i < k; i++) {
        for (int q = 0; q < g; q++) {
            std::cin >> a[i][q];
        }
    }
    for (int i = 0; i < k; i++) {
        for (int q = 0; q < g; q++) {
            if (i == 0 && q == 0) {
                if (a[i][q + 1] > a[i][q] && a[i + 1][q] > a[i][q]) {
                    countLoc++;
                }
            }
            else if (i == k - 1 && q == 0) {
                if (a[i - 1][q] > a[i][q] && a[i][q + 1] > a[i][q]) {
                    countLoc++;
                }
            }
            else if (i == 0 && q == g - 1) {
                if (a[i][q - 1] > a[i][q] && a[i + 1][q] > a[i][q]) {
                    countLoc++;
                }
            }
            else if (i == k - 1 && q == g - 1) {
                if (a[i][q - 1] > a[i][q] && a[i - 1][q] > a[i][q]) {
                    countLoc++;
                }
            }
            else if (i > 0 && q > 0 && i < k - 1 && q < g - 1) {
                if (a[i - 1][q] > a[i][q] && a[i + 1][q] > a[i][q] && a[i][q - 1] > a[i][q] && a[i][q + 1] > a[i][q]) {
                    countLoc++;
                }
            }
            else if (i == 0 && q > 0 && q < g - 1) {
                if (a[i][q + 1] > a[i][q] && a[i][q - 1] > a[i][q] && a[i + 1][q] > a[i][q]) {
                    countLoc++;
                }
            }
            else if (q == 0 && i > 0 && i < k - 1) {
                if (a[i - 1][q] > a[i][q] && a[i + 1][q] > a[i][q] && a[i][q + 1] > a[i][q]) {
                    countLoc++;
                }
            }
            else if (q == g - 1 && i > 0 && i < k - 1) {
                if (a[i - 1][q] > a[i][q] && a[i + 1][q] > a[i][q] && a[i][q - 1] > a[i][q]) {
                    countLoc++;
                }
            }
            else if (i == k - 1 && q > 0 && q < g - 1) {
                if (a[i - 1][q] > a[i][q] && a[i][q - 1] > a[i][q] && a[i][q + 1] > a[i][q]) {
                    countLoc++;
                }
            }
        }
    }
    std::cout << countLoc;


}