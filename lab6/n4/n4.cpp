#include "/all labs/lab4/bestcheck/top.h"
#include <iostream>
#include <string>

int exitFromTask(char* inputValidation);

int main() {
    std::cout << "Task4. Created by Yaroslav Yastremskiy.\n\n After entering text, it will be converted according to task reform";
    std::cout << "\n\n\n**************************************************************\n\n\n";
    std::string qu = "kv"; std::string Qu = "Kv";
    std::string x = "ks"; std::string X = "Ks";
    std::string s1 = "1";
    std::string bcd = "b, c, d, f, g, h, j, k, l, m, n, p, q, r, s, t, v, w, x, z";
    std::string BCD = "B, C, D, F, G, H, J, K, L, M, N, P, Q, R, S, T, V, W, X, Z";
    std::cout << "Enter text, which you want to change:\n\n";
    int numTry = 0;
    while (getline(std::cin, s1)) {
        if (numTry != 0) {
        }
        numTry++;
        char inputValidation[10000];
        long long len = s1.length();
        for (long long i = 0; i < s1.length(); i++) {
            //for c

            if (s1[i] == 'c' && i != len - 1) {
                //std::cout << "c";
                if (s1[i + 1] == 'e' || s1[i + 1] == 'i' || s1[i + 1] == 'y' || s1[i + 1] == 'E' || s1[i + 1] == 'Y' ||
                    s1[i + 1] == 'I')
                    s1.replace(i, 1, 1, 's');
                else s1.replace(i, 1, 1, 'k');
            }
            if (s1[i] == 'C' && i != s1.length()) {
               //std::cout << "C";
                if (s1[i + 1] == 'e' || s1[i + 1] == 'i' || s1[i + 1] == 'y' || s1[i + 1] == 'E' || s1[i + 1] == 'Y' ||
                    s1[i + 1] == 'I')
                    s1.replace(i, 1, 1, 'S');
                else s1.replace(i, 1, 1, 'K');
            }
            if (s1[i] == 'c' && (i == 0 || i == len - 1)) {
                s1.replace(i, 1, 1, 'k');
            }
            if (s1[i] == 'C' && (i == 0 || s1.length())) {
                s1.replace(i, 1, 1, 'K');
            }
            //for q

            if (s1[i] == 'q' && i != s1.length() - 1) {
                //std::cout << "q";
                if (s1[i + 1] == 'u') {
                    s1.replace(i, 2, qu);
                }
                else s1.replace(i, 1, 1, 'k');
                i--;
                continue;
            }
            if (s1[i] == 'q') {
                //std::cout << "q";
                s1.replace(i, 1, 1, 'k');
                i--;
                continue;
            }
            if (s1[i] == 'Q' && i != len - 1) {
                //std::cout << "Q";
                if (s1[i + 1] == 'u' || s1[i + 1] == 'U')
                    s1.replace(i, 2, Qu);
                else s1.replace(i, 1, 1, 'K');
                i--;
                continue;
            }
            if (s1[i] == 'Q' && i == len - 1) {
                s1.replace(i, 1, 1, 'K');
            }

            //for x and ee

            if (s1[i] == 'x') {
                if (i != len - 1)
                    s1.insert(i + 1, 1, s1[i + 1]);
                s1.replace(i, 2, x);
                if (i != 0) {
                    i -= 1;
                }
                if (i == len - 1) {
                    s1.replace(i, 2, x);
                }
                len++;
                continue;
            }
            if (s1[i] == 'X') {
                if (i != len - 1)
                    s1.insert(i + 1, 1, (char)s1[i + 1]);
                s1.replace(i, 2, X);
                if (i != 0) {
                    i--;
                }
                len++;
                continue;
            }
            if ((s1[i] == 'e' || s1[i] == 'E') && i != 0) {
                if (s1[i - 1] == 'e') {
                    s1.replace(i - 1, 2, 1, 'i');
                    i--;
                }

            }
            if (s1[i] == 'e' && i != 0) {
                if (s1[i - 1] == 'E') {
                    s1.replace(i - 1, 2, 1, 'I');
                    i--;
                }
                continue;
            }
            if (s1[i] == 'E' && i < s1.length() - 1) {
                if (s1[i - 1] == 'E') {
                    s1.replace(i - 1, 2, 1, 'I');
                    i--;
                }
                continue;
            }


            //for w
            if (s1[i] == 'w' || s1[i] == 'W') {
                if (s1[i] == 'w')
                    s1.replace(i, 1, 1, 'v');
                if (s1[i] == 'W')
                    s1.replace(i, 1, 1, 'V');
            }

            //for ph && th

            if ((s1[i] == 'h' || s1[i] == 'H') && i != 0) {
                if (s1[i - 1] == 'T' || s1[i - 1] == 't' || s1[i - 1] == 'p' || s1[i - 1] == 'P') {
                    if (s1[i - 1] == 't')
                        s1.replace(i - 1, 2, 1, 'z');
                    if (s1[i - 1] == 'T')
                        s1.replace(i - 1, 2, 1, 'Z');
                    if (s1[i - 1] == 'p')
                        s1.replace(i - 1, 2, 1, 'f');
                    if (s1[i - 1] == 'P')
                        s1.replace(i - 1, 2, 1, 'F');
                    i -= 1;
                    len--;
                    continue;
                }
            }

            //for oo && you

            if ((s1[i] == 'o' || s1[i] == 'O') && i != 0) {
                if (s1[i - 1] == 'o') {
                    s1.replace(i - 1, 2, 1, 'u');
                    i--;
                    len--;
                    goto point;
                }
                if (s1[i - 1] == 'O') {
                    s1.replace(i - 1, 2, 1, 'U');
                    i--;
                    len--;
                    goto point;
                }

            }
            point:
            if ((s1[i] == 'o' || s1[i] == 'O') && i > 0 && i != len - 1) {
                if (s1[i - 1] == 'y' && (s1[i + 1] == 'u' || s1[i + 1] == 'U')) {
                    s1.replace(i - 1, 3, 1, 'u');               
                    i--;
                    len -= 2;
                    continue;
                }
                if (i > 0 && i != len - 1) {
                    if (s1[i - 1] == 'Y' && (s1[i + 1] = 'u' || s1[i + 1] == 'U')) {
                        s1.replace(i - 1, 3, 1, 'U');
                        i--;
                        len -= 2;
                        //continue;
                    }
                }
            }

            //for double
        }
        long long len2 = s1.length();
        for (long long i = s1.length(); i > 0; i--) {
            if (bcd.find(s1[i], 0) != std::string::npos || BCD.find(s1[i], 0) != std::string::npos) {
                if (s1[i] == s1[i - 1]) {
                    while (s1[i] == s1[i - 1]) {
                        s1.erase(i - 1, 1);
                        if (s1.length() == 1) break;
                    }
                }
                else if (s1[i] - 32 == s1[i - 1]) {
                    while (s1[i] - 32 == s1[i - 1]) {
                        s1.erase(i, 1);
                        if (s1.length() == 1) break;
                    }
                }
                else if (s1[i] + 32 == s1[i - 1]) {
                    while (s1[i] + 32== s1[i - 1]) {
                        s1.erase(i, 1);
                        if (s1.length() == 1) break;
                    }
                }
            }
        }
        //std::cout << s1 << "\n";
        for (int i = 0; i < s1.length(); i++) {
            if(s1[i] == '\\' && i != s1.length() - 1){
                if (s1[i + 1] == '0') std::cout << ' ';
            }
            else {
                std::cout << s1[i];
            }
            if (s1[i] == '\\' && s1[i + 1] == '0') return 0;
        }
        std::cout << '\n';
    }
}

int exitFromTask(char* inputValidation) {
    rewind(stdin);
    std::cout << "Do you want to continue? (y / n) ";
    char userChoice;
    std::cin >> inputValidation;
    while (stringLength(inputValidation) > 1 || (inputValidation[0] != 'y' && inputValidation[0] != 'n' && inputValidation[0] != 'N' && inputValidation[0] != 'Y')) {
        std::cout << "Wrong input. Try again.\n";
        std::cout << '\n' << "Do you want to continue? (y / n) ";
        rewind(stdin);
        std::cin >> inputValidation;
    }
    userChoice = inputValidation[0];
    rewind(stdin);
    if (userChoice == 'n' || userChoice == 'N') return 0;
    else return 1;
}

