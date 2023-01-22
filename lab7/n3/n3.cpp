#include "/all labs/lab4/bestcheck/top.h"
#include <iostream>
#include <string>
#include <algorithm>

std::string converter(long long number, long long system, std::string symbols) {
    std::string s;
    long long temp = number;
    while (number != 0) { //O(logSystem(number)
        s.push_back(symbols[number % system]);
        number /= system;
    }
    s.push_back('0');
    //s.push_back('0');
    std::reverse(s.begin(), s.end());
    return s;
}
std::string addZeros(std::string s, int len) {
    int length = s.length();
    if (length < len) {
        s.insert(0, len - length, '0'); //O (len - length)
        //s.insert(0, 1, '0');
    }
    return s;
}
std::string sum(int system, std::string s1, std::string s2){
    std::string result;
    int temp, trans = 0;
    s1 = addZeros(s1, s2.length()); s2 = addZeros(s2, s1.length());
    for (int i = s1.length() - 1; i >= 0; i--) { //O (|s| - 1)
        temp = s1[i] + s2[i] + trans;
        if (s1[i] >= 'A') temp -= '7';
        else temp -= '0';
        if (s2[i] >= 'A') temp -= '7';
        else temp -= '0';
        temp -= system;
        if (temp < 0) {
            temp += system;
            if (temp > 9) temp += '7';
            else temp += '0';
            trans = 0;
        }
        else {
            if (temp > 9) temp += '7';
            else temp += '0';
            trans = 1;
        }
        result.push_back(temp);
    }
    std::reverse(result.begin(), result.end());
    if (result[0] == '0') {
        int i = 0;
        while (result[i] == '0' && result.length() > 1) { ////O (|s| - 2)
            result.erase(0, 1); 
        }
    }
    return result;
}
std::string difference(int system, std::string s1, std::string s2) {
    std::string result;
    int temp = 0, trans = 0;
    s1 = addZeros(s1, s2.length()); s2 = addZeros(s2, s1.length());
    for (int i = s1.length() - 1; i >= 0; i--) { //O (|s| - 1)
        temp = s1[i] - s2[i] + trans;
        if (s1[i] >= 'A') temp -= '7';
        else temp -= '0';
        if (s2[i] >= 'A') temp += '7';
        else temp += '0';
        //temp += system;
        if (temp < 0) {
            temp += system;
            if (temp > 9) temp += '7';
            else temp += '0';
            trans = -1;

        }
        else {
            if (temp > 9) temp += '7';
            else temp += '0';
            trans = 0;
        }
        result.push_back(temp);
    }
    std::reverse(result.begin(), result.end());
    if (result[0] == '0') {
        int i = 0;
        while (result[i] == '0' && result.length() > 1) { //O (|s| - 2)
            result.erase(0, 1);
        }
    }
    return result;
}
void checkIntNaturalSize1(char array[]) {
    std::cin >> array;
    while (isInt(array) != 1 || (atoi(array) < 2  || atoi(array) > 36)) {
        std::cout << "Wrong input or your num is incorrect(input onlyy 2-36). Try again\n";
        std::cin >> array;
    }
}
void checkInt1(char array[]) {
    std::cin >> array;
    while (isInt(array) != 1 || stringLength(array) > 10) {
        std::cout << "Wrong input or too big num.Try again\n";
        std::cin >> array;
    }
}
long long convertToInt(std::string s, int system){
    long long num = 0, j = 0;
    for (int i = s.length() - 1; i > 0; i--) {
        //std::cout << "s[" << i <<"] = " <<  s[i] << '\n';
        if (s[i] >= 'A')
            num += powl(system, j) * (s[i] - '7');
        if (s[i] < 'A')
            num += powl(system, j) * (s[i] - '0');
        
        j++;
        std::cout << num << '\n';
    }
    if (s[0] == '1') {
        num *= -1;
    }
    //std::cout << "num in func = " << num << '\n';
    return num;
}
int main() {
    /*std::string s = "ABC";
    std::cout << convertToInt(s, 15);*/
    std::cout << "User can enter the system of notation(from 2 to 36) and then enter nums in decimal system\n";
    std::cout << "Programm will convert nums in needable system and count diff and sum of them\n";
    char inputValidation[10000];
    std::string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string num1str, num2str, tempstr;
    while (true) {
        std::cout << "\n\nChoose the system of notation(from 2 to 36) = ";
        checkIntNaturalSize1(inputValidation);
        long long system = atoi(inputValidation);
        std::cout << "system = " << system << '\n';
        long long num1, num2, tempn1, tempn2;
        std::cout << "Enter the first num: ";
        std::cin >> num1str;
        num1 = convertToInt(num1str, system);
        //std::cin >> num1;
        tempn1 = num1;
        num1 = abs(num1);
        //std::cout << "num1 = " << num1 << '\n';
        std::cout << "Enter the second num: ";
        //std::cin >> num2;
        std::cin >> num2str;
        num2 = convertToInt(num2str, system);
        //std::cout << "num2 = " << num2 << '\n';
        tempn2 = num2;
        num2 = abs(num2);
        //num1str = converter(num1, system, symbols);
        tempstr = num1str;
        //num2str = converter(num2, system, symbols);
        int flag = 0;
        num1str = addZeros(num1str, num2str.length());
        num2str = addZeros(num2str, num1str.length());
        //std::cout << "num1 =" << num1str << " " << num1 << '\n';
        //std::cout << "num2 =" << num2str << " " << num2 << '\n';

        num1str = sum(system, num1str, num2str);
        std::string tempsum = num1str;
        std::cout << "sum = ";
        if (tempn1 < 0 && tempn2 <= 0) std::cout << "-" << num1str << '\n';
        else if (tempn1 >= 0 && tempn2 >= 0) std::cout << num1str << '\n';
        else if (tempn1 <= 0 && tempn2 > 0) {
            num1str = tempstr;
            if (num1 > num2) {
                num1str = difference(system, num1str, num2str);
                std::cout << "-" << num1str << '\n';
            }
            if (num2 > num1) {
                num1str = difference(system, num2str, num1str);
                std::cout << num1str << '\n';
            }
            if (num2 == num1) std::cout << 0 << '\n';
        }
        else if (tempn1 >= 0 && tempn2 < 0) {
            num1str = tempstr;
            if (num1 >= num2) {
                num1str = difference(system, num1str, num2str);
                std::cout << num1str << '\n';
            }
            else if (num1 < num2) {
                num1str = difference(system, num2str, num1str);
                std::cout << "-" << num1str << '\n';
            }
        }

        std::cout << "difference = ";
        if (tempn1 >= 0 && tempn2 >= 0 && tempn1 > tempn2) {
            num1str = tempstr;
            num1str = difference(system, num1str, num2str);
            std::cout << num1str << '\n';
        }
        else if (tempn1 >= 0 && tempn2 >= 0 && tempn1 <= tempn2) {
            num1str = tempstr;
            num1str = difference(system, num2str, num1str);
            std::cout << "-" << num1str << '\n';
        }
        else if (tempn1 <= 0 && tempn2 <= 0 && tempn1 <= tempn2) {
            num1str = tempstr;
            num1str = difference(system, num1str, num2str);
            std::cout << "-" << num1str << '\n';
        }
        else if (tempn1 <= 0 && tempn2 <= 0 && tempn1 >= tempn2) {
            num1str = tempstr;
            num1str = difference(system, num2str, num1str);
            std::cout << num1str << '\n';
        }
        else if (tempn1 >= 0 && tempn2 <= 0) {
            num1str = tempstr;
            num1str = sum(system, num2str, num1str);
            std::cout << num1str << '\n';
        }
        else if (tempn1 <= 0 && tempn2 >= 0) {
            num1str = tempstr;
            num1str = sum(system, num2str, num1str);
            std::cout << "-" << num1str << '\n';
        }
        //num1str = difference(system, tempstr, num2str);
        //std::cout << num1str << '\n';
        // std::cout << num1str;
        if (choice() == 0) return 0;
    }
}