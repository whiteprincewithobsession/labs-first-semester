#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>

int main() {
    long long countZeros = 0, idMin, min, idMax, max, numLength = 0, totalNumber = 0, k = 0, minusCounter = 0, lengthNew = 0;
    long long stringToInt[20];
    long long intMassive[100];
    long long intMassiveNew[100];
    for (int i = 0; i < 100; i++) {
        intMassive[i] = -21464142;
    }
    std::string s;
    getline(std::cin, s);
    //std::cout << "s.length = " << s.length() << " ";
    /*if (s[0] == '0') {
        countZeros++;
    }*/
    for (int i = 1; i < s.length(); i++) {

        /*if (s[i] == '0' && s[i - 1] == ' ') {
            countZeros++;
        }*/
    }
    for (int i = 0; i < s.length(); i++) {
        int q = 0, a = 0;
        numLength = 0;
        totalNumber = 0;
        minusCounter = 0;
        if (s[i] != 32) {
            while ((int)s[i] != 32 && i < s.length()) {
                if (s[i] == '-') {
                    i++;
                    minusCounter++;
                    continue;
                }
                else {
                    stringToInt[q] = (int)s[i] - 48;
                    i++;
                    //std::cout << "s[" << i << "] = " << s[i];
                    numLength++;
                    /*std::cout << "\nq = " << q << '\n';
                    std::cout << "a[" << q << "] = " << stringToInt[q] << '\n';*/
                    q++;
                }
            }
            //std::cout << "numlength = " << numLength;
            for (int h = numLength; h > 0; h--) {
                totalNumber += stringToInt[a] * pow(10, h - 1);
                //std::cout << "\ntotalNumber = " << totalNumber << '\n';
                a++;
            }
            if (minusCounter == 1) {
                intMassive[k] = -1 * totalNumber;
            }
            else {
                intMassive[k] = totalNumber;
            }
            //std::cout << "intMassive[" << k << "] = " << intMassive[k] << '\n';
            k++;
        }
    }

   /* std::cout << "\ncountZeros = " << countZeros << '\n';
    std::cout << s;
    std::cout << " total massive:\n";
    for (int i = 0; intMassive[i] != -21464142; i++) {
        std::cout << intMassive[i] << " ";
    }*/

    for (int i = 0; intMassive[i] != -21464142; i++) {
        intMassiveNew[i] = intMassive[i];
        lengthNew++;
    }

    min = intMassiveNew[0];
    max = intMassiveNew[0];
    idMin = 0;
    idMax = 0;


    for (int i = 0; i < lengthNew; i++) {
        if (intMassiveNew[i] == 0) {
            countZeros++;
        }
        if (min > intMassiveNew[i]) {
            idMin = i;
            min = intMassiveNew[i];
        }
        if (max < intMassiveNew[i]) {
            idMax = i;
            max = intMassiveNew[i];
        }
        else continue;
    }
    /*std::cout << "min = " << min << " max = " << max << '\n';
    std::cout << "idMin = " << idMin << " idMax = " << max << '\n';*/
        if (idMin < idMax) {
            for (int i = idMin + 1; i < idMax; i++) {
                intMassiveNew[i] = 0;
                countZeros++;
            }
        }
        else if (idMin > idMax) {
            for (int i = idMax + 1; i < idMin; i++) {
                intMassiveNew[i] = 0;
                countZeros++;
            }
        }
    //std::cout << '\n';
        for (int i = 0; i < lengthNew; i++){
            if(countZeros == lengthNew){
                std::cout << intMassiveNew[i] << " ";
            }
            else if (countZeros > lengthNew / 2) {
                if (intMassiveNew[i] == 0) {
                    continue;
                }
                else std::cout << intMassiveNew[i] << " ";
            }
            else {
                std::cout << intMassiveNew[i] << " ";
        }
    }


}