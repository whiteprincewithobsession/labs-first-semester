#include "/all labs/lab4/bestcheck/top.h"
#include <iostream>
#include <stdlib.h>

void deleter(char* array, int i, int *length);
int exitFromTask(char* inputValidation);
int checkerLit(char* array, int length);
void outputMass(char* array, int length);

int main() {
    char inputValidation[1000000];
    std::cout << "Task3. Created by Yaroslav Yastremskiy, number 14\n";
    std::cout << "\nUser enter the set of symbols which can contain(maybe not) sym \"# \"\n";
    std::cout << "\nEntering symbol \"#\" means to cancel the previous literal of the text; k num of \"#\" cancel the k previous letters";
    std::cout << "\n\n\n***************************************************************************\n\n";
    while (true) {
        int array[1000]{};
        int el = 0;
        std::cout << "\nEnter your text\n\n";
        rewind(stdin);
        char input = 'a';
        int counter = 0, length = 0;
        char* text = NULL;
        text = (char*)malloc(sizeof(char) * 100000);
        input = getchar();
        if (input == '\n') {
            std::cout << "Your choice was empty string ";
            //continue;
        }
        do {
            if (input == '#') {
                counter++;
            }
            text[length] = input;
            length++;
            input = getchar();
            text = (char*)realloc(text, (length + 1) * sizeof(char));
        } while (input != '\n');
        int a = checkerLit(text, length);
        if (a == 0) goto point;
        for (int i = 0; i < length; i++) {
            if (text[i] == '#') {
                if (i == 0) {
                    std::cout << "# is on 0 position, no solution for this";
                    goto point;
                }
                deleter(text, i, &length);
                deleter(text, i - 1, &length);
                i -= 2;
            }
        }
        outputMass(text, length);
        point:
        a = exitFromTask(inputValidation);
        if (a == 1) continue;
        else return 0;
    }
}

void deleter(char* array, int i, int *length) {
    for (int n = i; n < *length - 1; n++) {
        array[n] = array[n + 1];
    }
    (*length)--;
    array = (char*)realloc(array, *length * sizeof(char));
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
    if (userChoice == 'n' || userChoice == 'N') return 0;
    else return 1;
}

int checkerLit(char* array, int length) {
    int counterLit = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == '#') {
            counterLit++;
            if (i == 0) {
                std::cout << "Incorrect position for #, programm starts again\n\n";
                return 0;
            }
        }
        if (counterLit > length / 2) {
            std::cout << "# more than half of symbols, programm starts again\n\n";
            return 0;
        }

    }
    return 1;
}

void outputMass(char* array, int length) {
    std::cout << "In result:\n\n";
    for (int i = 0; i < length; i++) {
        std::cout << array[i];
    }
    std::cout << "\n\n";
}