#include <iostream>
long double myPow(long double a, long double b);
int stringLength(char array[]);
int isInt(char array[]);
int isFloat(char array[]);
void checkIntNaturalSize(char* array);
void checkDouble(char* array);
void checkInt(char* array);


int isInt(char array[]) {
    if (array[0] == '-' || (array[0] >= '0' && array[0] <= '9') || array[0] == '+') {
        if ((array[0] == '-' && stringLength(array) == 1)) return 0;
        if ((array[0] == '+') && stringLength(array) == 1) return 0;
        if (array[0] == '0' && array[1] != 0) return 0;
        else {
            for (int i = 1; i < stringLength(array); i++) {
                if (array[i] < '0' || array[i] > '9') return 0;
            }
            return 1;
        }
    }
    else return 0;
}

int isFloat(char array[]) {
    int pointCount = 0, eCount = 0, eId = 0, expMinusId = 0, pointId;
    if (array[0] == '-' || (array[0] >= '0' && array[0] <= '9') || array[0] == '.') {

        if (array[0] == '-' && stringLength(array) == 1) return 0;
        for (int i = 0; i < stringLength(array); i++) {
            if ((array[i] < '0' || array[i] > '9') && array[i] != '.' && array[i] != '-' && array[i] != 'e') return 0;
            if (array[i] == '.') {
                pointCount++;
                pointId = i;
                if (pointCount > 1) return 0;
            }
            if (array[i] == 'e') {
                eId = i;
                eCount++;
                if (eCount > 1) return 0;
                if (array[i + 1] == '-') expMinusId = i + 1;

            }
        }
        if (pointCount == 1) {
            for (int i = 1; i < stringLength(array); i++) {
                if (array[i] == '.') {
                    if (stringLength(array) == 1) return 0;
                    if (pointId == stringLength(array) - 1) return 0;
                    else continue;
                }
            }
            return 1;
        }
        else {
            if (array[0] == '0' && array[1] != 0) return 0;
            else {
                if (eCount == 1) {
                    for (int i = 1; i < stringLength(array); i++) {
                        if (i == eId || i == expMinusId) {
                            if (i + 1 == stringLength(array)) return 0;
                            else continue;
                        }
                    }
                    return 1;
                }
                else {
                    for (int i = 1; i < stringLength(array); i++) {
                        if (array[i] < '0' || array[i] > '9') return 0;
                    }
                    return 1;
                }
            }
        }
    }
    else return 0;
}

void checkIntNaturalSize(char* array) {
    while (isInt(array) != 1 || atoi(array) <= 1 || stringLength(array) > 5) {
        std::cout << "Wrong input.Try again\n";
        std::cin >> array;
    }
}
void checkInt(char* array) {
    while (isInt(array) != 1 || stringLength(array) > 5) {
        std::cout << "Wrong input.Try again\n";
        std::cin >> array;
    }
}
void checkDouble(char* array) {
    while (isFloat(array) != 1 || stringLength(array) > 7) {
        std::cout << "Wrong input.Try again\n";
        std::cin >> array;
    }
}

int stringLength(char array[]) {
    int strLength = 0;
    for (int i = 0; i < 10000; i++) {
        if (array[i] == 0) {
            break;
        }
        strLength++;
    }
    return strLength;
}

long double myPow(long double a, long double b) {
    long double mult = 1;
    for (int i = 0; i < b; i++) {
        mult *= a;
    }
    return mult;
}