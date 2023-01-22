#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int bin = 2;
int b;

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
    int k = 0;
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
        k++;
        if (k == index) {
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
//std::string stringToBin(std::string s, const int bin);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::string zero = "0";
    std::string one = "1";
    //std::string s;
    //std::cin >> s;
    //std::cout << stringToBin(s, bin) << '\n';
    int n;
    std::cin >> n;
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
        int position = helper[0].size() - count + n;
        std::cout << helper[0][position];
    }
}
