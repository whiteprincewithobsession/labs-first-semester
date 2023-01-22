#include <iostream>
#include <cstring>

bool isPossible(char* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        if (array[i] != array[i + 1]) return true;
    }
    return false;
}

bool isPalindrome(char* array, int length) {
    for (int i = 0; i < length; i++) {
        if (array[i] != array[length - i - 1]) return false;
    }
    return true;
}


int main() {
    char array[500000];
    std::cin >> array;
    //std::cout << array;
    int len = strlen(array);
    //std::cout << '\n' << len;
    if (isPossible(array, len) == false) {
        std::cout << "-1";
        return 0;
    }
    else {
        int check = isPalindrome(array, len);
        if (check == 0) std::cout << len;
        else std::cout << len - 1;
    }
}