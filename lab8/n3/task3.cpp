#include <iostream>
#include <string>
#include "checkers.h"
#include "functions.h"
#include <fstream>

int main() {

	while (true) {
		taskInfo();
		char inputValidation[10000];
		task* library;
		task* sortedLib;
		int n, function;
		if (isEmpty() == false) {
			std::cout << "Enter the num of books in library: ";
			checkIntSize(inputValidation);
			n = atoi(inputValidation);
			library = creator(n);
		}
		else {
			std::ifstream entering;
			entering.open("D:\\all labs\\lab8\\task3input.txt", std::ios::in);
			entering >> n;
			library = creatorWithFile(n);
		}

		while (true) {
			std::cout << "\n\n\nChoose the function you want to run:\n1)Print list\n2)Add one book\n3)Finder\n4)Delete element\n";
			std::cout << "5)Change element\n6)Sort elements\n7)Writing in file\n8)Quit\n\n\n";
			checkIntFunctions(inputValidation);
			function = atoi(inputValidation);
			rewind(stdin);
			if (function == 1) {
				printer(library, n);
			}
			if (function == 2) {
				library = addBook(library, n);
				rewind(stdin);
			}
			if (function == 5) {
				std::cout << "Which struct do you want to change?";
				int index;
				checkIntStruct(inputValidation, n);
				index = atoi(inputValidation);
				rewind(stdin);
				library = changeElement(library, index);
			}
			if (function == 6) {
				sortedLib = creatorSorted(library, n);
				printerSorted(sortedLib, sizeSort);
			}
			if (function == 4 && n == 1) {
				std::cout << "Array is empty";
				break;
			}
			else if (function == 4) {
				int index;
				std::cout << "Which struct do you want to remove? ";
				checkIntStruct(inputValidation, n);
				index = atoi(inputValidation);
				rewind(stdin);
				library = removeElement(library, index, n);
			}
			if (function == 7) {
				printerInFile(library, n);
			}
			if (function == 3) {
				finder(library, n);
			}
			if (function == 8) {
				break;
			}
		}
		if (choice1() == 0) return 0;
	}

}