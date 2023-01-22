#include "/all labs/lab4/bestcheck/top.h"
#include <iostream>
#include <string>

std::string binToAdditional(std::string s) {
    std::string sNat = "00", sNeg = "11";
    if (s[0] == '-') {
        for (int i = s.length() - 1, flag = 0; i >= 0; i--) {  // O(n)
            if (flag >= 1) {
                if (s[i] == '1') s[i] = '0';
                else if (s[i] == '0') s[i] = '1';
            }
            else if (s[i] == '1') {
                flag++;
            }
        }
    }
    if (s[0] == '+') s.replace(0, 1, sNat);
    if (s[0] == '-') s.replace(0, 1, sNeg);
    return s;
}
std::string additionalToBin(std::string s) {
    for (int i = s.length() - 1, flag = 0; i >= 0; i--) {  // O(n)
        if (flag >= 1) {
            if (s[i] == '1') s[i] = '0';
            else if (s[i] == '0') s[i] = '1';
        }
        else if (s[i] == '1') {
            flag++;
        }
    }
    if (s[0] == '1') s.replace(0, 1, 1, '+');
    if (s[0] == '0') s.replace(0, 1, 1, '-');
    return s;
}
std::string addZeros(std::string s, int len) {
    int length = s.length();
    if (length < len) {
        s.insert(0, len - length, s[0]);
    }
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
    if (s.length() == 1) return 0;
    if (s[0] != '-' && s[0] != '+') return 0; 
    for (int i = 1; i < s.length(); i++) { // O(|s|)
        if (s[i] != '0' && s[i] != '1') return 0;
    }
    return 1;
}
void checkerAgain(std::string& s) {
    while (checker(s) != 1) {
        std::cout << "Wrong input.Try again" << std::endl;
        //rewind(stdin);
        std::cin >> s;
    }
}

int main() {
    std::cout << "Task2, variant 14. Created by Yaroslav Yastremskiy\n";
    std::cout << "In this task user enters two nums in natural binary forms\nThen programm will perform the addition";
    std::cout << "\n\n************************************************************************************\n\n";
    while (true) {
        std::string s1, s2, s3;
        std::cout << "Enter the first num(\"+\" or \"-\" on first position)\n";
        std::cin >> s1;
        checkerAgain(s1);
        std::cout << "Enter the second num(\"+\" or \"-\" on first position)\n";
        std::cin >> s2;
        checkerAgain(s2);
        s1 = binToAdditional(s1); s2 = binToAdditional(s2);
        s1 = addZeros(s1, s2.length()); s2 = addZeros(s2, s1.length());
        int flag = 0;
        for (int i = s1.length() - 1; i >= 0; i--) { //O(|s| - 1)
            if (flag == 1) {
                s1[i] = s1[i] + s2[i] - '0' + 1;
                flag--;
            }
            else s1[i] = s1[i] + s2[i] - '0';
            if (s1[i] == '2') {
                flag++;
                s1[i] = '0';
            }
            else if (s1[i] == '3') {
                flag++;
                s1[i] = '1';
            }
        }
        int a = 0;
        if (s1[0] == '1') {
            s1 = additionalToBin(s1);
            s1 = eraserZeros(s1);
        }
        if (a == 0) {
            s1 = eraserZeros(s1);
            s1[0] = '+';
        }
        std::cout << '\n' << s1;
        if (choice() == 0) return 0;
    }
}
