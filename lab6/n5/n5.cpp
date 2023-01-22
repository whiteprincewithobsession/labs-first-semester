#include <iostream>
#include <string>
#include <cmath>


unsigned long long recursiveFunc(unsigned long long k, unsigned long long n, unsigned long long m)
{
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return k % m;
    }
    if(n % 2 == 0){
        unsigned long long temp = recursiveFunc(k, n / 2, m);
        return temp * temp % m;
    }
    else{
        unsigned long long temp = recursiveFunc(k, n - 1, m) * k % m;
        return temp;
    }
}



int main() {
    std::string s1;
    std::string s2;
    const unsigned long long letters = 26;
    unsigned long long l, m, testCounter, len1, len2, answer, lenSim = 0;
    std::cin >> testCounter;
    for(int tests = 0; tests <= testCounter; tests++) {
        point:
        if(tests == testCounter){
        return 0;
        }
        std::cin >> l >> m;
        std::cin >> s1 >> s2;
        len1 = s1.length();
        len2 = s2.length();

        if (len1 + len2 == l && s1 != s2) std::cout << 2 << '\n';
        if (s1 == s2 && len1 + len2 == l) std::cout << 1 << '\n';
        if (s1 == s2 && len1 + len2 < l)  std::cout << recursiveFunc(letters, l - len1 - len2, m) % m << '\n';

        else if(len1 + len2 < l){
            std::cout << (recursiveFunc(letters, l - len1 - len2, m) * 2) % m << '\n';
        }

        else if(len1 + len2 > l){
            //std::cout << s1.find(s2);
            if((len1 == l && s1.find(s2) != std::string::npos) && ((len2 + s1.find(s2)  == len1)) || s1.find(s2) == 0) {
                std::cout << 1 << '\n';
            }
            else if((len2== l && s2.find(s1) != std::string::npos) && ((len1 + s2.find(s1) == len2)) || s2.find(s1) == 0){
                std::cout << 1 << '\n';
            }
            else {
                unsigned long long k = 0;
                for (int i = 0; i < len1; i++) {
                    lenSim = 0;
                    for (int q = 0; q < len2; q++) {
                        if (s1[i] == s2[q]) {
                            k = i;
                            for(int f = q; f <= len2; f++){
                                lenSim++;
                                if(s2[f] != s1[k]){
                                    break;
                                }
                                else if(k == len1 - 1 && ((len2 == f + 1) || (len2 - lenSim == f))){
                                    if(len1 + len2 - lenSim <= l){
                                        std::cout << 1;
                                        tests++;
                                        goto point;
                                        //return 0;
                                    }
                                }
                                k++;
                                //std::cout << "k = " << k << " lenSim = " << lenSim << '\n';

                                //std::cout << lenSim;
                            }
                        }
                    }
                }
                for (int i = 0; i < len2; i++) {
                    lenSim = 0;
                    for (int q = 0; q < len1; q++) {
                        if (s2[i] == s1[q]) {
                            k = i;
                            for(int f = q; f <= len1; f++){
                                lenSim++;
                                if(s1[f] != s2[k]){
                                    break;
                                }
                                else if(k == len2 - 1){
                                    if((len1 + len2 - lenSim <= l) && ((len1 == f + 1) || (len1 - lenSim == f))){
                                        std::cout << 1;
                                        tests++;
                                        goto point;
                                        //return 0;
                                    }
                                }
                                k++;
                                //std::cout << "k = " << k << " lenSim = " << lenSim << '\n';

                                //std::cout << lenSim;
                            }
                        }
                    }
                }
                std::cout << 0 << '\n';
            }
        }
    }
}