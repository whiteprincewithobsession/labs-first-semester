#define _CRT_SECURE_NO_WARNINGS
#include "checkers.h"
#include "functions_task2.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

int main() {
	while (true) {
		std::string line;
		taskInfo();
		char inputValidation[1000];
		goods* items;
		goods* sortedItems;
		int size = 0, function;
		if (isEmpty() == false) {
			printf("Enter the number of goods: ");
			checkIntSize(inputValidation);
			size = atoi(inputValidation);
			items = creator(size);
		}
		else {	
			std::ifstream entering;
			entering.open("D:\\all labs\\lab8\\task2input.txt", std::ios::in);
			entering >> size;
			items = creatorWithFile(size);
		}
		while (true) {
			std::cout << "\n\n\nChoose the function you want to run:\n1)Print list(in file + console)\n2)Add one item\n3)Find required goods\n4)Delete element\n5)Change element\n6)Quit\n\n\n";
			checkIntFunctions(inputValidation);
			function = atoi(inputValidation);
			if (function == 1) {
				printerArray(items, size);
			}
			else if (function == 2) {
				items = addGoods(items, size);
				arrayChanger(items, size);
			}
			else if (function == 3) {
				sortedItems = creatorSorted(items, size);
				selectionSort(sortedItems, sizearray);
				std::cout << "\n\nSorted array:\n\n";
				//printerArray(sortedItems, sizearray);
				printerRequired(sortedItems, sizearray);
			}
			else if(function == 4 && size == 1) {
				std::ofstream out;
				out.open("D:\\all labs\\lab8\\task2output.txt");
				out << "Array is empty";
				printf("Array is empty\n");
				break;
			}
			else if (function == 4 && size != 1) {
				int index;
				printf("Which struct do you want to remove?\n");
				checkIntStruct(inputValidation, size);
				index = atoi(inputValidation);
				rewind(stdin);
				items = removeElement(items, index, size);
				arrayChanger(items, size);
			}
			else if (function == 5) {
				printf("Which struct do you want to change?\n");
				int index;
				checkIntStruct(inputValidation, size);
				index = atoi(inputValidation);
				rewind(stdin);
				items = changeElement(items, index);
				arrayChanger(items, size);
			}
			else if (function == 6) {
				break;
			}
		}
		if (choice1() == 0) return 0;
	}
}