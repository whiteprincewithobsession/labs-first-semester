#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string num;
    std::string s1 = "I";
    std::string s2 = "II";
    std::string s3 = "III";
    std::string s4 = "IV";
    std::string s5 = "V";
    std::string s6 = "VI";
    std::string s7 = "VII";
    std::string s8 = "VIII";
    std::string s9 = "IX";
    std::string s10 = "X";
    std::string s20 = "XX";
    std::string s30 = "XXX";
    std::string s40 = "XL";
    std::string s50 = "L";
    std::string s60 = "LX";
    std::string s70 = "LXX";
    std::string s80 = "LXXX";
    std::string s90 = "XC";
    std::string s100 = "C";
    std::string s200 = "CC";
    std::string s300 = "CCC";
    std::string s400 = "CD";
    std::string s500 = "D";
    std::string s600 = "DC";
    std::string s700 = "DCC";
    std::string s800 = "DCCC";
    std::string s900 = "CM";
    std::string s1000 = "M";
    std::string s2000 = "MM";
    std::string s3000 = "MMM";
    std::string temps1000;
    int a, numRanks = 0;
    std::cin >> a;
    int temp = a;
    while (temp != 0) {
        temp /= 10;
        numRanks++;
    }
    int i = 0, rank;
    temp = a;
    while (temp != 0) {
        rank = temp % 10;
        temp /= 10;
        i++;
        if (i == 1) {
            if (rank == 1) num += s1;
            else if (rank == 2) num += s2;
            else if (rank == 3) num += s3;
            else if (rank == 4) num += s4;
            else if (rank == 5) num += s5;
            else if (rank == 6) num += s6;
            else if (rank == 7) num += s7;
            else if (rank == 8) num += s8;
            else if (rank == 9) num += s9;
        }
        if (i == 2) {
            if (rank == 1) num.insert(0, s10);
            else if (rank == 2) num.insert(0, s20);
            else if (rank == 3) num.insert(0, s30);
            else if (rank == 4) num.insert(0, s40);
            else if (rank == 5) num.insert(0, s50);
            else if (rank == 6) num.insert(0, s60);
            else if (rank == 7) num.insert(0, s70);
            else if (rank == 8) num.insert(0, s80);
            else if (rank == 9) num.insert(0, s90);
        }
        if (i == 3) {
            if (rank == 1) num.insert(0, s100);
            else if (rank == 2) num.insert(0, s200);
            else if (rank == 3) num.insert(0, s300);
            else if (rank == 4) num.insert(0, s400);
            else if (rank == 5) num.insert(0, s500);
            else if (rank == 6) num.insert(0, s600);
            else if (rank == 7) num.insert(0, s700);
            else if (rank == 8) num.insert(0, s800);
            else if (rank == 9) num.insert(0, s900);
        }
        if (i == 4) {
            temps1000.insert(0, rank, 'M');
            if (rank == 1) num.insert(0, s1000);
            else if (rank == 2) num.insert(0, s2000);
            else if (rank == 3) num.insert(0, s3000);
            //else if (rank > 3 && rank < 10) num.insert(0, temps1000);
        }
        //std::cout << rank << '\n';
    }
    std::cout << num;
}