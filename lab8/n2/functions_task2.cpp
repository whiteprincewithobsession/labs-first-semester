#define _CRT_SECURE_NO_WARNINGS
#include "checkers.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

int sizearray = 0;
const int day1 = 16;
const int month1 = 12;
const int year1 = 2022;
struct goods {
	std::string product;
	long double cost;
	long double profit;
	int day;
	int month;
	int year;
	int amount;
	int timeInStock = -1;
};
goods* creator(int& n) {
	char tmp[101];
	bool flag = 0;
	goods* items = new goods[n];
	for (int i = 0; i < n; i++) {
		printf("Enter the name of product: ");
		checkFullName(tmp);
		items[i].product = tmp;
		printf("Enter cost of product: ");
		checkDouble1(tmp);
		items[i].cost = atof(tmp);
		printf("Enter date in format day.month.year");
		while (scanf_s("%d.%d.%d", &items[i].day, &items[i].month, &items[i].year) != 3 || items[i].timeInStock < 0 || items[i].day < 0 || items[i].month < 0 || items[i].year < 0 || items[i].day > 30 || items[i].year > 2022 || items[i].year < 2012 || items[i].month > 12) {
			items[i].timeInStock = day1 - items[i].day + (month1 - items[i].month) * 30 + (year1 - items[i].year) * 365;
			rewind(stdin);
		}
		printf("Enter number of sold items: ");
		checkIntNatural1(tmp);
		items[i].amount = atoi(tmp);
		items[i].profit = items[i].amount * items[i].cost;
		printf("\n\n");
	}
	return items;
}
goods* creatorWithFile(int& n) {
	std::ifstream entering;
	entering.open("D:\\all labs\\lab8\\task2input.txt", std::ios::in);
	entering >> n;
	char tmp[101];
	bool flag = 0;
	goods* items = new goods[n];
	for (int i = 0; i < n; i++) {
		entering >> items[i].product;
		entering >> items[i].cost;
		entering >> items[i].day;
		entering >> items[i].month;
		entering >> items[i].year;
		items[i].timeInStock = day1 - items[i].day + (month1 - items[i].month) * 30 + (year1 - items[i].year) * 365;
		entering >> items[i].amount;
		items[i].profit = items[i].amount * items[i].cost;
	}
	return items;
}
void printerArray(goods* items, int n) {
	std::ofstream out;
	out.open("D:\\all labs\\lab8\\task2output.txt");
	for (int i = 0; i < n; i++) {
		out << items[i].product << '\n';
		out << "Date of arrival: " << items[i].day << '.' << items[i].month << '.' << items[i].year << '\n';
		out << "The item is already in stoch for " << items[i].timeInStock << '\n';
		out << "Cost: " << items[i].cost << '\n';
		out << "Amount of such goods: " << items[i].profit << '\n';
		out << "Profit from selling:  " << items[i].profit << " rubles\n\n\n";
		printf("\n\n%s\n", items[i].product.c_str());
		printf("Date of arrival: %d.%d.%d\n", items[i].day, items[i].month, items[i].year);
		printf("The item is already in stock for %d days\n", items[i].timeInStock);
		printf("Cost: %.2lf\n", items[i].cost);
		printf("Amount of such goods %d\n", items[i].amount);
		printf("Profit from selling = %.2lf\n", items[i].profit);
		printf("\n\n");
	}
}
void arrayChanger(goods* items, int n) {
	std::ofstream out;
	out.open("D:\\all labs\\lab8\\task2output.txt");
	for (int i = 0; i < n; i++) {
		out << items[i].product << '\n';
		out << "Date of arrival: " << items[i].day << '.' << items[i].month << '.' << items[i].year << '\n';
		out << "The item is already in stoch for " << items[i].timeInStock << '\n';
		out << "Cost: " << items[i].cost << '\n';
		out << "Amount of such goods: " << items[i].profit << '\n';
		out << "Profit from selling:  " << items[i].profit << " rubles\n\n\n";
	}
}
void printerRequired(goods* items, int size) {
	std::ofstream out;
	out.open("D:\\all labs\\lab8\\task2outputreq.txt");
	for (int index = 0; index < size; index++) {
		out << items[index].product << '\n';
		out << "Date of arrival: " << items[index].day << '.' << items[index].month << '.' << items[index].year << '\n';
		out << "The item is already in stoch for " << items[index].timeInStock << '\n';
		out << "Cost: " << items[index].cost << '\n';
		out << "Amount of such goods: " << items[index].amount << '\n';
		out << "Profit from selling:  " << items[index].profit << " rubles\n\n\n";
		printf("\n\n%s\n", items[index].product.c_str());
		printf("Date of arrival: %d.%d.%d\n", items[index].day, items[index].month, items[index].year);
		printf("The item is already in stock for %d days\n", items[index].timeInStock);
		printf("Cost: %lf\n", items[index].cost);
		printf("Amount of such goods %d\n", items[index].amount);
		printf("Profit from selling = %lf\n", items[index].profit);
		printf("\n\n");
	}
}
goods* removeElement(goods* items, int index, int& size) {
	if (index == size) size--;
	else {
		for (int i = index; i < size; i++) {
			items[i - 1] = items[i];
		}
		size--;
	}
	return items;
}
goods* addGoods(goods* items, int& size) {
	char tmp[101]; bool flag = 0;
	size++;
	goods* temp = new goods[size];
	for (int i = 0; i < size - 1; i++) {
		temp[i] = items[i];
	}
	printf("Enter the name of product: ");
	checkFullName(tmp);
	temp[size - 1].product = tmp;
	printf("Enter cost of product: ");
	checkDouble1(tmp);
	temp[size - 1].timeInStock = -1;
	printf("Enter date in format day.month.year: ");
	int a, b, c;
	while (scanf_s("%d.%d.%d", &a, &b, &c) != 3 || checkDays(a) != 1 || checkMonths(b) != 1 || checkYears(c) != 1 || (a > 16 && b == 12 && c == 2022))  {		
		rewind(stdin);
		printf("Wrong input.Try again\n");
	}
	items[size - 1].day = a; items[size - 1].month = b; items[size - 1].year = c;
	items[size - 1].timeInStock = day1 - items[size - 1].day + (month1 - items[size - 1].month) * 30 + (year1 - items[size - 1].year) * 365;
	printf("Enter number of sold temp: ");
	checkIntNatural1(tmp);
	temp[size - 1].profit = atoi(tmp) * temp[size - 1].cost;
	items = temp;
	return items;
}
goods* changeElement(goods* items, int index) {
	int n; char tmp[101];
	printf("Choose the field you want to change:\n");
	printf("1 - product name\n2 - cost\n3 - datel\n4 - amount of goods\n");
	scanf_s("%d", &n);
	if (n == 1) {
		printf("Enter name of product: ");
		checkFullName(tmp);
		items[index - 1].product = tmp;
	}
	else if (n == 2) {
		printf("Enter cost of good: ");
		checkDouble1(tmp);
		items[index - 1].cost = atof(tmp);
		items[index - 1].profit = items[index - 1].amount * items[index - 1].cost;
	}
	else if (n == 4) {
		printf("Enter amount of goods: ");
		checkIntNatural1(tmp);
		items[index - 1].amount = atoi(tmp);
		items[index - 1].profit = items[index - 1].amount * items[index - 1].cost;
	}
	else if (n == 3) {
		printf("Enter date in format day.month.year: ");
		int a, b, c;
		while (scanf_s("%d.%d.%d", &a, &b, &c) != 3 || checkDays(a) != 1 || checkMonths(b) != 1 || checkYears(c) != 1 || (a > 16 && b == 12 && c == 2022)) {
			rewind(stdin);
			printf("Wrong input.Try again\n");
		}
		items[index - 1].day = a; items[index - 1].month = b; items[index - 1].year = c;
		items[index - 1].timeInStock = day1 - items[index - 1].day + (month1 - items[index - 1].month) * 30 + (year1 - items[index - 1].year) * 365;
	}
	return items;
}
goods* findingRequired(goods* items, int& size) {
	for (int i = 0; i < size; i++) {
		if (items[i].timeInStock >= 30 && items[i].cost > 10574) {
			printerRequired(items, i);
		}
	}
	return items;
}
bool isEmpty() {
	bool checker;
	std::fstream input;
	input.open("D:\\all labs\\lab8\\task2input.txt");
	if (input.peek() == EOF) checker = false;
	else checker = true;
	return checker;
}
void selectionSort(goods* items, int& size) {
	int pos = 0;
	for (int i = 0; i < size; i++) {
		pos = 0;
		for (int j = 0; j < size; j++) {
			if (items[i].product[0] < items[j].product[0])
				pos++;
		}
		std::swap(items[size - i - 1], items[pos]);
	}
}

goods* creatorSorted(goods* items, int& size) {
	int num = 0;
	for (int i = 0; i < size; i++) {
		if (items[i].cost >= 10574 && items[i].timeInStock >= 30) {
			num++;
		}
	}
	sizearray = num;
	goods* newitems = new goods[num];
	for (int i = 0, j = 0; i < size; i++) {
		if (items[i].cost >= 10574 && items[i].timeInStock >= 30) {
			newitems[j] = items[i];
			j++;
		}
	}
	return newitems;
}
