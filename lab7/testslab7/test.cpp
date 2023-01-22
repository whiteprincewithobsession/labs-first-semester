#include "pch.h"
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
const int bin = 2;
int b;
std::string Rome(int a);
long long countInteresting(long long num);
std::string numToTernary(int a);


std::string numToBinary(long long a) {
    std::string s1;
    while (a != 0) {
        char b = (a % 2) + '0';
        a /= 2;
        s1.append(1, b);
    }
    reverse(s1.begin(), s1.end());
    return s1;
}
bool finder(std::string result, std::string stringNum) {
    int i = 0;
    while (i < result.length()) {
        //std::cout << i << '\n';
       // std::cout << i << '\n';
        if (result.find(stringNum, i) + stringNum.length() == result.length()) {
            return true;
        }
        if (result.find(stringNum) == (int)std::string::npos) break;
        i++;
    }
    return false;
}
std::string stringToBin(std::string s, const int bin, int index)
{
    std::string inBin;
    s.erase(0, s.find('1'));
    if (s.length() == 0) {
        inBin = 48;
        return inBin;
    }
    int* arr = new int[index];
    for (int i = 0; i < s.length(); i++) {
        arr[i] = s[i] - 48;
    }

    for (int i = 0; i != 1;) {

        //std::cout << arr[s.length() - 1] << '\n';
        if (arr[s.length() - 1] % bin == 0) inBin += 48;
        else inBin += 49;
        i = 1;
        for (int q = 0; q < s.length(); q++) {
            if (q != s.length() - 1) arr[q + 1] += (arr[q] % bin) * 10;
            arr[q] /= bin;
            //std::cout << "arr[" << q << "] = " << arr[q] << '\n';
            if (arr[q] != 0) {
                i = 0;
            }
        }
        if (inBin.length() == index) {
            std::reverse(inBin.begin(), inBin.end());
            return inBin;
        }
    }
    std::reverse(inBin.begin(), inBin.end());
    return inBin;
}
void clearance(std::vector<std::vector<std::string>>& a, std::vector<std::vector<std::string>>& b) {
    int sector = 1;
    a[sector].clear();
    b[sector].clear();
}
void changer(std::vector<std::vector<std::string>>& a, std::vector<std::vector<std::string>>& b) {
    std::vector<std::string> temp = a[0];
    a[0] = a[1];
    //std::cout << temp[0];
    a[1] = temp;
    temp = b[0];
    b[0] = b[1];
    //std::cout << temp[0];
    b[1] = temp;
}
std::string task77(int n) {
    std::string zero = "0";
    std::string one = "1";
    //std::string s;
    //std::cin >> s;
    //std::cout << stringToBin(s, bin) << '\n';
    if (n < 30) {
        //std::string result = numToBinary(n);
    //std::string stringNum = std::to_string(n);
    //std::cout << stringNum << '\n';
    //std::cout << result;
        long long a = 0, power = 0;
        std::string one;
        for (long long i = 1; ; i++) {
            //std::cout << i << '\n';
            std::string result = numToBinary(i);
            std::string stringNum = std::to_string(i);

            if (finder(result, stringNum) == true) {
                //std::cout << stringNum << '\n';
                a++;
            }

            if (a == n) {
                //std::cout << i;
                //std::cout << "power = " << power;
                std::cout << i;
                return 0;
            }
            if (stringNum == one) {
                i = powl(10, power) - 1;
            }
            if (stringNum.length() == one.length() + 1) {
                one.insert(0, 1, '1');
                power++;
            }
        }
    }
    std::vector<std::vector<std::string>> helper;
    helper.resize(10000);
    std::vector<std::vector<std::string>> binDec;
    binDec.resize(10000);
    binDec[0].push_back(zero);
    helper[0].push_back(one);

    int count = 1, i = 0;
    while (count < n)
    {
        ++i;
        for (int k = 0; k < binDec[0].size(); k++) {
            std::string ss = binDec[0][k], tempss = stringToBin(ss, bin, i + 1);
            int length = tempss.length() - i;
            if (tempss.length() < i + 1 || tempss[length - 1] == 48) {
                ss.insert(0, zero);
                binDec[1].push_back(ss);

            }
        }

            /*for (int k = 0; k < binDec[0].size(); k++) {
                std::cout << "binDec[0][k] = ";
                std::cout << binDec[0][k] << '\n';
            }*/
            for (int k = 0; k < helper[0].size(); k++) {
                std::string ss = helper[0][k], tempss = stringToBin(ss, bin, i + 1);
                int length = tempss.length() - i;
                if (tempss.length() < i + 1 || tempss[length - 1] == 48) {
                    ss.insert(0, zero);
                    binDec[1].push_back(ss);
                }
            }
        /*for (int k = 0; k < helper[0].size(); k++) {
            std::cout << "helper[0][k] = ";
            std::cout << helper[0][k] << '\n';
        }*/
        for (int k = 0; k < binDec[1].size(); k++) {
            std::string ss = binDec[1][k], tempss = stringToBin(ss, bin, i + 1);
            int length = tempss.length() - i;
            if (tempss.length() < i + 1 || tempss[length - 1] == 48) {
                ss.replace(0, 1, 1, '1');
                helper[1].push_back(ss);
            }
        }
        /*for (int k = 0; k < binDec[1].size(); k++) {
            std::cout << "binDec[1][k] = ";
            std::cout << binDec[1][k] << '\n';
        }*/
        changer(helper, binDec);
        clearance(helper, binDec);
        count += helper[0].size();
    }
    //std::cout << helper[0].size();
    /*if (helper[0].size() > 8) {
        for (int i = 0; i < helper[0].size() - 1; i++) {
            std::cout << helper[0][i] << '\n';
        }
    }
    else {
        for (int i = 0; i < helper[0].size() - 1; i++) {
            std::cout << "helper[0] = " << helper[0][i] << '\n';
            //std::cout << "helper[1] = " << helper[1][i] << '\n';
        }
    }*/
    if (count >= n) {
        int pos = 0;
        for (int i = count; i >= n; i--) {
            //std::cout << i << '\n';
            if (i != n) {
                pos++;
                continue;
            }
            if (i == n) {
                pos++;
                std::string answer = helper[0][helper[0].size() - pos];
                return answer;
                break;
            }
        }
    }
}

TEST(task4_3999) {
    std::string s = "MMMCMXCIX";
    ASSERT_EQ(Rome(3999), s);
}

TEST(task5) {
    long long a = 10000000000000000;
    ASSERT_EQ(countInteresting(a), 1000000000000000);
}

TEST(task8) {
    int a = 2147483647;
    std::string s = "12112122211333131331";
    ASSERT_EQ(numToTernary(a), s);
}

TEST(task7) {
    int n = 10000;
    std::string ans = "11001000000011100110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    ASSERT_EQ(task77(10000), ans);
}

std::string numToTernary(int a) {
    std::string s1;
    int temp = a;
    while (temp != 0) {
        s1.insert(0, 1, (temp % 3) + 48);
        temp /= 3;
    }
    std::string result = s1;
    std::string s20 = "13";
    std::string s30 = "23";
    std::string s10 = "03";
    //std::cout << result;
    int countOp = 0;
    for (int i = 0; i < result.length() - 1; i++) {
        if (result[i] == '1' && result[i + 1] == '0') {
            result.replace(i, 2, s10);
            if (i != 0) {
                i -= 2;
            }
        }
        if (result[i] == '2' && result[i + 1] == '0') {
            result.replace(i, 2, s20);
            i--;
        }
        if (result[i] == '3' && result[i + 1] == '0') {
            result.replace(i, 2, s30);
            i--;
        }
    }
    while (result[0] == '0') {
        result.erase(0, 1);
    }
    return result;
}

long long countInteresting(long long num) {
    return((num + 1) / 10);
}

std::string Rome(int a) {
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
    int numRanks = 0;
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
    return num;
}