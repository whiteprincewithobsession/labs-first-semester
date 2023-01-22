#include "/all labs/lab4/bestcheck/top.h"
#include <iostream>
#include <string>
#include <algorithm>

void checkIntNatural1(char* array) {
    while (isInt(array) != 1 || atoi(array) < 0 || stringLength(array) > 8) {
        std::cout << "Wrong input or your num is incorrect(too big or 0 - 1). Try again\n";
        std::cin >> array;
    }
}
const int one = 4294967295;
std::string numToBin(long long num) {
    long long temp = num;
    std::string bin;
    while (num != 0) {
        bin.push_back((num & 1) + '0');//O(log(num))
        num >>= 1;
    }
    bin.push_back('+');
    std::reverse(bin.begin(), bin.end());
    return bin;
}
std::string binToAdditional(std::string s) {
    std::string sNat = "00", sNeg = "11";
    if (s[0] == '-') {
        for (int i = s.length() + one, flag = 0; i >= 0; i += one) {  // O(|s|) 
            //std::cout << i << '\n';
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
std::string addZeros(std::string s, int len) {
    int length = s.length();
    if (length < len) {  
        s.insert(0, len - length, s[0]); // O(len - length) 
    }
    return s;
}
std::string eraserZeros(std::string s) { // O(n)
    if (s[1] == '0') {
        while (s[1] != '1' && s.length() != 2) { // O(|s| - 2) 
            s.erase(1, 1);
        }
    }
    return s;
}
std::string additionalToBin(std::string s) {
    for (int i = s.length() + one, flag = 0; i >= 0; i += one) { // O(|s|) 
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


int main() {
    std::cout << "Task6. Variant 14. Created by Yaroslav Yastremskiy\n";
    std::cout << "This programm can check if 11, 43 and 179 cases of the entered number(only natural), using bitwise operations";
    std::cout << "\n\n**************************************************************************************\n\n";
    long long number;
    char inputValidation[10000];
    while (true) {
        std::cout << "Enter the num, which you want to check:";
        rewind(stdin);
        std::cin >> inputValidation;
        checkIntNatural1(inputValidation);
        number = atoi(inputValidation);
        rewind(stdin);
        std::string s1; std::string s;
        std::string s179 = "-10110011"; s179 = binToAdditional(s179);
        std::string s11 = "-1011"; s11 = binToAdditional(s11);
        int length = s11.length(), flag = 0;
        std::string s43 = "-101011"; s43 = binToAdditional(s43);
        //std::cout << s179 << '\n' << s11 << '\n' << s43 << '\n';
        s1 = numToBin(number);
        s1 = binToAdditional(s1);
        s1 = addZeros(s1, s11.length()); s11 = addZeros(s11, s1.length());
        std::string temp = s1;
        while (s1 != "+0") { // O(log(num) ) 
            if (s1.length() < length + one && s1 != s11) {
                std::cout << "This number can't be divided by 11\n";
                flag = 5;
                break;
            }
            s1 = binToAdditional(s1); s11 = binToAdditional(s11);
            s1 = addZeros(s1, s11.length()); s11 = addZeros(s11, s1.length());
            int flag = 0;
            for (int i = s1.length() + one; i >= 0; i += one) { // O(|s|) 
                if (flag == 1) {
                    s1[i] = s1[i] + s11[i] + 208 + 1;
                    flag += one;
                }
                else s1[i] = s1[i] + s11[i] + 208;
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
        }
        if (flag != 5) {
            std::cout << number << " can be divided by 11\n";
        }
        s1 = temp;
        length = s43.length();
        s1 = numToBin(number);
        s1 = binToAdditional(s1);
        s1 = addZeros(s1, s11.length()); s11 = addZeros(s11, s1.length());
        while (s1 != "+0") { // O(log(num) ) 
            if (s1.length() < length + one && s1 != s43 && number != 0) {
                std::cout << "This number can't be divided by 43\n";
                flag = 7;
                break;
            }
            s1 = binToAdditional(s1); s43 = binToAdditional(s43);
            s1 = addZeros(s1, s43.length()); s43 = addZeros(s43, s1.length());
            int flag = 0;
            for (int i = s1.length() + one; i >= 0; i += one) { // O(|s|) 
                if (flag == 1) {
                    s1[i] = s1[i] + s43[i] + 208 + 1;
                    flag += one;
                }
                else s1[i] = s1[i] + s43[i] + 208;
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
        }
        if (flag != 7) {
            std::cout << number << " can be divided by 43\n";
        }
        length = s179.length();
        s1 = temp;
        s1 = numToBin(number);
        s1 = binToAdditional(s1);
        s1 = addZeros(s1, s179.length()); s179 = addZeros(s179, s1.length());
        while (s1 != "+0") { // O(log(num) ) 
            if (s1.length() < length + one && s1 != s179) {
                std::cout << "This number can't be divided by 179\n";
                flag = 9;
                break;
            }
            s1 = binToAdditional(s1); s179 = binToAdditional(s179);
            s1 = addZeros(s1, s179.length()); s179 = addZeros(s179, s1.length());
            int flag = 0;
            for (int i = s1.length() + one; i >= 0; i += one) { //O(|s1|)
                if (flag == 1) {
                    s1[i] = s1[i] + s179[i] + 208 + 1;
                    flag += one;
                }
                else s1[i] = s1[i] + s179[i] + 208;
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
        }
        if (flag != 9) {
            std::cout << number << " can be divided by 179\n";
        }
        if (choice() == 0) return 0;
        else continue;
    }
}
