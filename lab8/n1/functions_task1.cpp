#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include "checker.h"
#include "functions.h"

int sizearray = 0;

struct statement {
	std::string name;
	std::string surname;
	std::string patronymic;
	int mathGrade;
	int physGrade;
	int langGrade;
	double averageGrade;
};
statement* creator(int& n) {
	char tmp[101];
	statement* applicants = new statement[n];
	for (int i = 0; i < n; i++) {
		printf("Enter name of applicant: ");
		checkFullName(tmp);
		applicants[i].name = tmp;
		printf("Enter surname of applicant: ");
		checkFullName(tmp);
		applicants[i].surname = tmp;
		printf("Enter patronymic of applicant: ");
		checkFullName(tmp);
		applicants[i].patronymic = tmp;
		printf("Enter math points: ");
		checkIntPoints(tmp);
		applicants[i].mathGrade = atoi(tmp);
		printf("Enter physics points: ");
		checkIntPoints(tmp);
		applicants[i].physGrade = atoi(tmp);
		printf("Enter language points: ");
		checkIntPoints(tmp);
		applicants[i].langGrade = atoi(tmp);
		applicants[i].averageGrade = (double)(applicants[i].langGrade + applicants[i].mathGrade + applicants[i].physGrade) / 3;
	}
	return applicants;
}

long double averageInUn(statement* applicants, int& size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += applicants[i].averageGrade;
	}
	return sum / size;
}

statement* addApplicant(statement* applicants, int& size) {
	char temp[101];
	size++;
	statement* tmp = new statement[size];
	for (int i = 0; i < size - 1; i++) {
		tmp[i] = applicants[i];
	}
	printf("Enter name of applicant: ");
	checkFullName(temp);
	tmp[size - 1].name = temp;
	printf("Enter surname of applicant: ");
	checkFullName(temp);
	tmp[size - 1].surname = temp;
	printf("Enter patronymic of applicant: ");
	checkFullName(temp);
	tmp[size - 1].patronymic = temp;
	printf("Enter math points: ");
	checkIntPoints(temp);
	tmp[size - 1].mathGrade = atoi(temp);
	printf("Enter physics points: ");
	checkIntPoints(temp);
	tmp[size - 1].physGrade = atoi(temp);
	printf("Enter language points: ");
	checkIntPoints(temp);
	tmp[size - 1].langGrade = atoi(temp);
	tmp[size - 1].averageGrade = (double)(tmp[size - 1].langGrade + tmp[size - 1].mathGrade + tmp[size - 1].physGrade) / 3;
	applicants = tmp;
	return applicants;
}



void printerArray(statement* applicants, int n) {
	for (int i = 0; i < n; i++) {
		printf("%s ", applicants[i].surname.c_str());
		printf("%s ", applicants[i].name.c_str());
		printf("%s\n", applicants[i].patronymic.c_str());
		printf("Math points: %d ", applicants[i].mathGrade);
		printf("Physics points: %d ", applicants[i].physGrade);
		printf("Language points: %d \n", applicants[i].langGrade);
		printf("Average = %lf", applicants[i].averageGrade);
		printf("\n\n");
	}
}

statement* removeElement(statement* applicants, int index, int& size) {
	if (index == size) size--;
	else {
		for (int i = index; i < size; i++) {
			applicants[i - 1] = applicants[i];
		}
		size--;
	}
	return applicants;
}

statement* changeElement(statement* applicants, int index) {
	int n; char tmp[101];
	printf("Choose the field you want to change:\n");
	printf("1 - name\n2 - surname\n3 - patronymic\n4 - math\n5- phys\n6 - lang\n");
	checkIntChoice(tmp);
	n = atoi(tmp);
	if (n == 1) {
		printf("Enter name of applicant: ");
		checkFullName(tmp);
		applicants[index - 1].name = tmp;
	}
	if (n == 2) {
		printf("Enter surname of applicant: ");
		checkFullName(tmp);
		applicants[index - 1].surname = tmp;
	}
	if (n == 3) {
		printf("Enter patronymic of applicant: ");
		checkFullName(tmp);
		applicants[index - 1].patronymic = tmp;
	}
	if (n == 4) {
		printf("Enter math points: ");
		checkIntPoints(tmp);
		applicants[index - 1].mathGrade = atoi(tmp);
	}
	if (n == 5) {
		printf("Enter physics points: ");
		checkIntPoints(tmp);
		applicants[index - 1].physGrade = atoi(tmp);
	}
	if (n == 6) {
		printf("Enter language points: ");
		checkIntPoints(tmp);
		applicants[index - 1].langGrade = atoi(tmp);
	}
	if (n == 6 || n == 5 || n == 4) {
		applicants[index - 1].averageGrade = (double)(applicants[index - 1].mathGrade + applicants[index - 1].physGrade + applicants[index - 1].langGrade) / 3;
	}
	return applicants;
}


void selectionSort(statement* applicants, int& size) {
	int pos = 0;
	for (int i = 0; i < size; i++) {
		pos = 0;
		for (int j = 0; j < size; j++) {
			if (applicants[i].averageGrade < applicants[j].averageGrade)
				pos++;
		}
		std::swap(applicants[i], applicants[pos]);
	}
}

statement* creatorSorted(statement* applicants, int& size, long double supp) {
	int num = 0;
	for (int i = 0; i < size; i++) {
		if (applicants[i].averageGrade >= supp) {
			num++;
		}
	}
	sizearray = num;
	statement* newApplicants = new statement[num];
	for (int i = 0, j = 0; i < size; i++) {
		if (applicants[i].averageGrade >= supp) {
			newApplicants[j] = applicants[i];
			j++;
		}
	}
	return newApplicants;
}

void finder(statement* applicants, int& size) {
	char input[1000];
	int choose;
	long double numPoints;
	printf("Choose the searching element:\n1) Num of point2) Name / Surname / Patronymic\n3) Average grade\n");
	scanf_s("%s", input, 2);
	while (isInt1(input) != 1 || (atoi(input) != 1 && atoi(input) != 2 && atoi(input) != 3)) {
		printf("Choose only 1 - 3. Incorrect input\n");
		scanf_s("%s", input, 3);
		fflush(stdin);
	}
	choose = atoi(input);
	if (choose == 1) {
		bool flag = 0;
		printf("Enter the number of points(searching b): ");
		checkIntNaturalSize1(input);
		numPoints = atoi(input);
		printf("\n\n");
		for (int i = 0; i < size; i++) {
			if (applicants[i].mathGrade == int(numPoints) || applicants[i].physGrade == int(numPoints) || applicants[i].langGrade == int(numPoints)) {
				printf("%s ", applicants[i].surname.c_str());
				printf("%s ", applicants[i].name.c_str());
				printf("%s\n", applicants[i].patronymic.c_str());
				printf("Math points: %d ", applicants[i].mathGrade);
				printf("Physics points: %d ", applicants[i].physGrade);
				printf("Language points: %d \n", applicants[i].langGrade);
				printf("Average = %lf", applicants[i].averageGrade);
				printf("\n\n");
				flag = 1;
			}
		}
		if (flag == 0) {
			printf("\nThere are no elements with such parameter\n");
		}
	}
	else if (choose == 2) {
		bool flag = 0;
		printf("Enter the Name / Surname / Patronymic");
		checkFullName(input);
		std::string input1 = input;
		printf("\n\n");
		for (int i = 0; i < size; i++) {
			if (applicants[i].name == input1 || applicants[i].surname == input1 || applicants[i].patronymic == input1) {
				printf("%s ", applicants[i].surname.c_str());
				printf("%s ", applicants[i].name.c_str());
				printf("%s\n", applicants[i].patronymic.c_str());
				printf("Math points: %d ", applicants[i].mathGrade);
				printf("Physics points: %d ", applicants[i].physGrade);
				printf("Language points: %d \n", applicants[i].langGrade);
				printf("Average = %lf", applicants[i].averageGrade);
				printf("\n\n");
				flag = 1;
			}
		}
		if (flag == 0) printf("\nThere are no elements with such parameter\n");
	}
	if (choose == 3) {
		bool flag = 0;
		printf("Enter the number of points(searching by average): ");
		checkDouble1(input);
		numPoints = atof(input);
		printf("\n\n");
		for (int i = 0; i < size; i++) {
			if (applicants[i].averageGrade == numPoints) {
				printf("%s ", applicants[i].surname.c_str());
				printf("%s ", applicants[i].name.c_str());
				printf("%s\n", applicants[i].patronymic.c_str());
				printf("Math points: %d ", applicants[i].mathGrade);
				printf("Physics points: %d ", applicants[i].physGrade);
				printf("Language points: %d \n", applicants[i].langGrade);
				printf("Average = %lf", applicants[i].averageGrade);
				printf("\n\n");
				flag = 1;
			}
		}
		if (flag == 0) {
			printf("\n\nThere are no elements with such parameter\n\n");
		}
	}
}