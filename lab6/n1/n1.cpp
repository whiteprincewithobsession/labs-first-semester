#include "D:/all labs/lab4/bestcheck/top.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>

int wordCounter(char** text, int stringCounter, int counter, int length);
int longestWord(char** text, int stringCounter, int counter, int length);


int main() {
    char inputValidation[1000000];
    std::cout << "Task1. Created by Yaroslav Yastremskiy, number 14\n";
    std::cout << "After entering text(only in english, else lang will be skiped), programm will find:\n1)The word which is the longest;\n2)Count words";
    std::cout << "\n\n\n*************************************************\n\n";
    while (true) {
        std::cout << "\nEnter your text\n\n";
        rewind(stdin);
        char input = 'a';
        int counter = 0, stringCounter = 1, length = 0;
        char** text = NULL;
        text = (char**)malloc(sizeof(char*) * 2);
        text[0] = (char*)malloc(sizeof(char) * 80);
        char* string = NULL;
        input = getchar();
        if (input == '\n' || input == ' ') {
            std::cout << "Your choice was empty string ";
            continue;
        }
        do {
            length++;
            counter++;
            if (counter == 81) {
                counter = 1;
                stringCounter++;
                text = (char**)realloc(text, stringCounter * sizeof(char*));;
                text[stringCounter - 1] = (char*)malloc(80 * sizeof(char));
            }
            text[stringCounter - 1][counter - 1] = input;
            input = getchar();

        } while (input != '\n');
        /*for (int i = 0; i < stringCounter; i++) {
            for (int q = 0; q < 80; q++) {
                if (i == stringCounter - 1) {
                    if (q == counter) {
                        break;
                    }
                }
                std::cout << text[i][q];
            }
            std::cout << '\n';
        }*/

        std::cout << "\n\nTotal words in text " << wordCounter(text, stringCounter, counter, length) << "\n\n";
        std::cout << "The length of the biggest word " << longestWord(text, stringCounter, counter, length) << "\n\n";
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
    }
    return 0;
}


int wordCounter(char** text, int stringCounter, int counter, int length) {
    int wordCounter = 0;
    for (int i = 0; i < stringCounter; i++) {
        for (int q = 0; q < 80; q++) {
            if (i == stringCounter && q > counter + 1) {
                break;
            }
            if ((text[i][q] < 'A' || text[i][q] > 'z' || (text[i][q] > 'Z' && text[i][q] < 'a')) || i * 80 + q == length) {
                if ((text[i][q - 1] >= 'a' && text[i][q - 1] <= 'z') || (text[i][q - 1] >= 'A' && text[i][q - 1] <= 'Z')) {
                    wordCounter++;
                }
                else if ((text[i][q - 1] >= 'A' && text[i][q - 1] <= 'Z') || (text[i][q - 1] >= 'a' && text[i][q] <= 'z')) {
                    wordCounter++;
                }
            }
        }
    }
    return wordCounter;
}

int longestWord(char** text, int stringCounter, int counter, int length) {
    int numLetters = 0, maxLetters = 0;

    for (int i = 0; i < stringCounter; i++) {
        for (int q = 0; q < 80; q++) {
            /*if (i == stringCounter && q > counter) {
                break;
            }*/
            if ((text[i][q] < 'A' || text[i][q] > 'z' || (text[i][q] > 'Z' && text[i][q] < 'a')) || i * 80 + q == length && (q != 0)) {
                maxLetters = std::max(numLetters, maxLetters);
                numLetters = 0;
            }
            else {
                numLetters++;
                if (i * 80 + q == length)
                    maxLetters = std::max(numLetters, maxLetters);
            }
        }
    }
    return maxLetters;
}