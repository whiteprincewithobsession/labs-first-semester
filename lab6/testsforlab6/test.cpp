#include "pch.h"

long long taskAnnagrames(char* array); // t6
long long factorial(int n); // t6
void qsort(char* items, int left, int right); // t6

unsigned long long recursiveFunc(unsigned long long k, unsigned long long n, unsigned long long m); // t5
long long t5Prefix(std::string s1, std::string s2, long long l, long long m); // t5

bool isPossible(char* array, int length); // t7

bool finderInLeftSide(std::string s, std::string t, int posS, int posT); // t8
bool finderInRightSide(std::string s, std::string t, int posS, int posT); // t8

TEST(test_t6_14) {
  char str[15] = "abcdefghijklmn";
  ASSERT_EQ(taskAnnagrames(str), 87178291200);
}

TEST(test_t6) {
    std::string s1 = "a";
    std::string s2 = "b";
    ASSERT_EQ(t5Prefix(s1, s2, 200, 10000), 1152);
}

TEST(test_t7) {
    char array[100000];

    for (int i = 0; i < 100000; i++) {
        array[i] = 'a';
    }
    ASSERT_EQ(isPossible(array, 99999), false);
}

TEST(test_t8) {
    std::string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaababaaaaaaaaaaaaabaaaaaaaaaaabaaaaaaaaaaacaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    std::string s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    ASSERT_EQ(finderInRightSide(s1, s2, 100, 100), true);
}


long long taskAnnagrames(char* array){
long long counterDiff = 1;
int length = strlen(array);
qsort(array, 0, length - 1);
char temp = array[0];
for (int i = 1; i < length; i++) {
    if (temp != array[i]) {
        counterDiff++;
        temp = array[i];
    }
}
int x = 0, facCount = 0;
int* diff = new int[counterDiff];
temp = array[0];
for (int i = 0; i <= length; i++) {
    if (temp == array[i]) {
        facCount++;
    }
    else {
        diff[x] = facCount;
        x++;
        facCount = 1;
        temp = array[i];
    }
}
long long combinations = factorial(length);
for (int i = 0; i < counterDiff; i++) {
    combinations /= factorial(diff[i]);
}
return combinations;
}


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


long long t5Prefix(std::string s1, std::string s2, long long l, long long m) {

    const unsigned long long letters = 26;
    unsigned long long len1, len2, answer, lenSim = 0;
        len1 = s1.length();
        len2 = s2.length();

        if (len1 + len2 == l && s1 != s2) std::cout << 2 << '\n';
        if (s1 == s2 && len1 + len2 == l) std::cout << 1 << '\n';
        if (s1 == s2 && len1 + len2 < l)  std::cout << recursiveFunc(letters, l - len1 - len2, m) % m << '\n';

        else if (len1 + len2 < l) {
            long long a = (recursiveFunc(letters, l - len1 - len2, m) * 2);
            return a % m;
        }

        else if (len1 + len2 > l) {
            if ((len1 == l && s1.find(s2) != std::string::npos) && ((len2 + s1.find(s2) == len1)) || s1.find(s2) == 0) {
                std::cout << 1 << '\n';
            }
            else if ((len2 == l && s2.find(s1) != std::string::npos) && ((len1 + s2.find(s1) == len2)) || s2.find(s1) == 0) {
                std::cout << 1 << '\n';
            }
            else {
                unsigned long long k = 0;
                for (int i = 0; i < len1; i++) {
                    lenSim = 0;
                    for (int q = 0; q < len2; q++) {
                        if (s1[i] == s2[q]) {
                            k = i;
                            for (int f = q; f <= len2; f++) {
                                lenSim++;
                                if (s2[f] != s1[k]) {
                                    break;
                                }
                                else if (k == len1 - 1 && ((len2 == f + 1) || (len2 - lenSim == f))) {
                                    if (len1 + len2 - lenSim <= l) {
                                        std::cout << 1;
                                    }
                                }
                                k++;

                            }
                        }
                    }
                }
                for (int i = 0; i < len2; i++) {
                    lenSim = 0;
                    for (int q = 0; q < len1; q++) {
                        if (s2[i] == s1[q]) {
                            k = i;
                            for (int f = q; f <= len1; f++) {
                                lenSim++;
                                if (s1[f] != s2[k]) {
                                    break;
                                }
                                else if (k == len2 - 1) {
                                    if ((len1 + len2 - lenSim <= l) && ((len1 == f + 1) || (len1 - lenSim == f))) {
                                        std::cout << 1;
                                    }
                                }
                                k++;

                            }
                        }
                    }
                }
                std::cout << 0 << '\n';
            }
        }
    }


unsigned long long recursiveFunc(unsigned long long k, unsigned long long n, unsigned long long m)
{
    if (n == 0)   {
        return 1;
    }
    if (n == 1){
        return k % m;
    }
    if (n % 2 == 0){
        unsigned long long temp = recursiveFunc(k, n / 2, m);
        return temp * temp % m;
    }
    else{
        unsigned long long temp = recursiveFunc(k, n - 1, m) * k % m;
        return temp;
    }
}


bool isPossible(char* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        if (array[i] != array[i + 1]) return true;
    }
    return false;
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