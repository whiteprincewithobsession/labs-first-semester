#include <iostream>
#include <string>
#include <algorithm>

bool finderInLeftSide(std::string s, std::string t, int posS, int posT);
bool finderInRightSide(std::string s, std::string t, int posS, int posT);

int main() {
    int tests;
    std::string s;
    std::string t;
    std::string s1;
    std::cin >> tests;
    while (tests != 0) {
        std::cin >> s >> t;
        s1 = s;
        char tZero = t[0];
        //std::cout << "tzero = " << tZero << '\n';
        //std::cout << "find = " << s1.find(tZero) << '\n';
        //std::cout << "sLen = " << s.length() << " tLen = " << t.length() << '\n';
        int lenS = s.length();
        int lenT = t.length();
        std::reverse(s1.begin(), s1.end());
        if (t == s) std::cout << "YES" << '\n';
        else if (s1.find(tZero) == lenS - 1 && lenS < lenT) std::cout << "NO" << '\n';
        else if (t == s1) std::cout << "YES" << '\n';
        else if (std::string::npos != s.find(t) && lenS > lenT) std::cout << "YES" << '\n';
        else if (std::string::npos != s1.find(t) && lenS > lenT) std::cout << "YES" << '\n';
        else if (s.find(tZero, 0) == s.length() - 1) {
            if (s.find(tZero, 0) == s.length() - 1 && lenS < lenT) {
                std::cout << "NO" << '\n';
            }
            else {
                bool result = finderInLeftSide(s, t, lenS - 1, 0);
                if (result) std::cout << "YES" << '\n';
                else std::cout << "NO" << '\n';
            }
        }
        else {
            bool res;
            for (int i = 0; i < lenS; i++) {
                if (s[i] == t[0]) {
                    res = finderInRightSide(s, t, i, 1);
                    //std::cout << res;
                    if (res == true) {
                        std::cout << "YES" << '\n';
                        break;
                    }
                }
            }
            if (res == false) {
                std::cout << "NO" << '\n';
            }
        }
        //else std::cout << "NO" << '\n';
        tests--;
    }
}

bool finderInRightSide(std::string s, std::string t, int posS, int posT) {
    int lenS = s.length();
    bool result = 0, result1 = 0;
    if (posS - 1 >= 0 && s[posS - 1] == t[posT]) {
        result = finderInLeftSide(s, t, posS - 1, posT);
    }
    if (posS + 1 < lenS && s[posS + 1] == t[posT]) {
        result1 = finderInRightSide(s, t, posS + 1, posT + 1);
    }
    if (result == true) return true;
    else if (result1 == true) return true;
    else return false;

}


bool finderInLeftSide(std::string s, std::string t, int posS, int posT) {
    int lenS = s.length(); int lenT = t.length();
    while (posS > 0 && posT < lenT) {
        if (s[posS] != t[posT]) return false;
        else {
            posT++;
            posS--;
        }
    }
    return true;
}