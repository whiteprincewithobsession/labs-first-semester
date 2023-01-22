#include "/all labs/lab4/bestcheck/top.h"
#include <iostream>
#include <stdlib.h>

long long simFinder(char** text, int* array, int stringCounter);

bool wordChecker(char a) {
    if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')) return true;
    else return false;
}

int main() {
    char inputValidation[1000000];
    std::cout << "Task2. Created by Yaroslav Yastremskiy, number 14\n";
    std::cout << "\nAfter entering text(only in english, else lang will be skiped) programm will find:\n\n1)The sentences with similar words;\n\n2)Count these sentences and give the amount of them";
    std::cout << "\n\n\n***************************************************************************\n\n";
    while (true) {
        int array[1000]{};
        int el = 0;
        std::cout << "\nEnter your text\n\n";
        rewind(stdin);
        char input = 'a';
        int counter = 0, stringCounter = 1, length = 0;
        char** text = NULL;
        text = (char**)malloc(sizeof(char*) * 1000);
        text[0] = (char*)malloc(sizeof(char) * 1);
        char* string = NULL;
        input = getchar();
        if (input == '\n') {
            std::cout << "Your choice was empty string ";
            //continue;
        }
        do {
            length++;
            counter++;
            if (input == '.' || input == '!' || input == '?') {
                el++;
                if (el != 0) {
                    array[el]--;
                }
                array[el]++;
                counter = 1;
                stringCounter++;
                text[stringCounter - 1] = (char*)malloc(1000 * sizeof(char));
                input = getchar();
            }
            text[stringCounter - 1] = (char*)realloc(text[stringCounter - 1], (counter + 1) * sizeof(char));
            text[stringCounter - 1][counter - 1] = input;
            input = getchar();
            array[el]++;
            if (text[stringCounter - 1][counter - 1] == '0') {
                if (text[stringCounter - 1][counter - 2] == '\\') {
                    break;
                    length -= 2;
                }
            }
        } while (input);
        int countSentences = 0;
        //std::cout << array[2];
        int j = 0;
        for (int i = 0; i < stringCounter; i++) {
            for (int q = 0; q < array[j] - 1; q++) {
                if (text[i][q] != ' ') {
                    for (int z = q + 1; z < array[j]; z++) {
                        if (text[i][q] == text[i][z] && wordChecker(text[i][z - 1]) == false) {
                            for (int a = q, b = z; text[i][a] == text[i][b]; a++, b++) {
                                //std::cout << "arr = " << array[j];
                                //std::cout << countSentences << '\n';
                                if (b == array[j] - 1 && wordChecker(text[i][a + 1]) == false) {
                                    countSentences++;
                                    goto point;
                                }
                                else if (b != array[j] - 1 && wordChecker(text[i][a + 1]) == false && wordChecker(text[i][b + 1]) == false) {
                                    countSentences++;
                                    goto point;
                                }
                            }
                        }
                    }
                }
            }
        point:
            j++;
        }
        //std::cout << el << '\n';
        //std::cout << array[0] <<" " << array[1] << " " << array[2] <<   '\n';
        int x = 0;
        std::cout << "Total sentences with sim words = " << simFinder(text, array, stringCounter) << "\n\n";
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
        if (userChoice == 'n' || userChoice == 'N') return 0;
        /*for (int i = 0; i < stringCounter; i++) {
            for (int q = 0; q < array[x]; q++) {
                std::cout << text[i][q];
                std::cout << q;
            }
            std::cout << '\n';
            x++;
        }*/
    }
}


long long simFinder(char** text, int* array, int stringCounter){ 
    int countSentences = 0;
    int j = 0;
    for (int i = 0; i < stringCounter; i++) {
        for (int q = 0; q < array[j] - 1; q++) {
            if (text[i][q] != ' ') {
                for (int z = q + 1; z < array[j]; z++) {
                    if (text[i][q] == text[i][z] && wordChecker(text[i][z - 1]) == false) {
                        for (int a = q, b = z; text[i][a] == text[i][b]; a++, b++) {
                            if (b == array[j] - 1 && wordChecker(text[i][a + 1]) == false) {
                                countSentences++;
                                goto point;
                            }
                            else if (b != array[j] - 1 && wordChecker(text[i][a + 1]) == false && wordChecker(text[i][b + 1]) == false) {
                                countSentences++;
                                goto point;
                            }
                        }
                    }
                }
            }
        }
    point:
        j++;
    }
    return countSentences;
}