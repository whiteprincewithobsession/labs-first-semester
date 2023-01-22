#include <iostream>
#include <cstring>
long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else return n * factorial(n - 1);
}

void qsort(char* items, int left, int right) {
    int i, j;
    char x, y;
    i = left; j = right;
    x = items[(left + right) / 2];
    do {
        while (items[i] < x && i < right) i++;
        while (x < items[j] && j > left) j--;
        if (i <= j) {
            std::swap(items[i], items[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) qsort(items, left, j);
    if (right > i) qsort(items, i, right);
}

int main() {
    char str[15];
    long long counterDiff = 1;
    std::cin >> str;
    int length = strlen(str);
    qsort(str, 0, length - 1);
    //std::cout << str;
    char temp = str[0];
    for (int i = 1; i < length; i++) {
        if (temp != str[i]) {
            counterDiff++;
            temp = str[i];
        }
    }
    int x = 0, facCount = 0;
    int* array = new int[counterDiff];
    temp = str[0];
    for (int i = 0; i <= length; i++) {
        if (temp == str[i]) {
            facCount++;
        }
        else {
            array[x] = facCount;
            x++;
            facCount = 1;
            temp = str[i];
        }
    }
    /*for(int i = 0; i < counterDiff; i++){
        std::cout << " " << array[i] << " ";
    }*/
    long long combinations = factorial(length);
    for (int i = 0; i < counterDiff; i++) {
        //std::cout << "Comb = " << combinations << '\n';
        combinations /= factorial(array[i]);
    }
    std::cout << combinations;
}