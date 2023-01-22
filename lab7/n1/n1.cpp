#include "/all labs/lab4/bestcheck/top.h"
#include <iostream>
#include <string>

std::string additionalToBin(std::string s) {
    for (int i = s.length() - 1, flag = 0; i >= 2; i--) {  // O(|s| - 1)
        if (flag >= 1) {
            if (s[i] == '1') s[i] = '0';
            else if (s[i] == '0') s[i] = '1';
        }
        else if (s[i] == '1') {
            flag++;
        }
    }
    if (s[0] == '1') s.replace(0, 2, 1, '-');
    if (s[0] == '0') s.replace(0, 2, 1, '+');
    return s;
}
std::string eraserZeros(std::string s) { // O(n)
    if (s[1] == '0') {
        while (s[1] != '1' && s.length() != 2) {
            s.erase(1, 1);
        }
    }
    return s;
}
int checker(std::string s) {
    if (s.length() == 2 || s.length() == 1) return 0;
    if (s[1] != '.') return 0;
    for (int i = 0; i < s.length(); i++) { //O(|s|)
        if (i == 1) continue;
        if (s[i] != '0' && s[i] != '1') return 0;
    }
    return 1;
}
void checkerAgain(std::string &s) {
    while (checker(s) != 1) {
        std::cout << "Wrong input.Try again" << std::endl;
        //rewind(stdin);
        std::cin >> s;
    }
}

int main() {
    std::cout << "Task1. Created by Yaroslav Yastremskiy. Variant 14\n";
    std::cout << "In this task user enters the num in additional code and programm will convert it to straight";
    std::cout << "\n\n****************************************************************************************\n\n";
    while (true) {
        std::string s1;
        std::cout << "Enter the num in additional code: ";
        std::cin >> s1;
        checkerAgain(s1);
        s1 = additionalToBin(s1);
        s1 = eraserZeros(s1);
        std::cout << s1;
        if (choice() == 0) return 0;
    }
}

