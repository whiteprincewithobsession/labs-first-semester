#define _CRT_SECURE_NO_WARNINGS
#include "checker.h"
#include "functions.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

int main() {
	while (true) {
		taskInfo();
		char inputValidation[10000];
		statement* applicants;
		statement* sortedApplicants;
		int n, function;
		std::cout << "Enter the number of applicants: ";
		checkIntSize(inputValidation);
		n = atoi(inputValidation);
		applicants = creator(n);
		while (true) {
			std::cout << "\n\n\nChoose the function you want to run:\n1)Print list\n2)Add one applicant\n3)Finder\n4)Delete element\n5)Change element\n6)Sort elements\n7)Quit\n\n\n";
			checkIntFunctions(inputValidation);
			function = atoi(inputValidation);
			rewind(stdin);
			if (function == 1) {
				printerArray(applicants, n);
			}
			if (function == 2) {
				applicants = addApplicant(applicants, n);
				rewind(stdin);
			}
			if (function == 5) {
				std::cout << "Which struct do you want to change?";
				int index;
				checkIntStruct(inputValidation, n);
				index = atoi(inputValidation);
				rewind(stdin);
				applicants = changeElement(applicants, index);
			}
			if (function == 6) {
				long double supp = averageInUn(applicants, n);
				sortedApplicants = creatorSorted(applicants, n, supp);
				selectionSort(sortedApplicants, sizearray);
				std::cout << "\n\nSorted array:\n\n";
				printerArray(sortedApplicants, sizearray);
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
				applicants = removeElement(applicants, index, n);
			}
			if (function == 7) {
				break;
			}
			if (function == 3) {
				finder(applicants, n);
			}
		}
		if(choice1() == 0) return 0;
	}
}
