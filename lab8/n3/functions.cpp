#include <iostream>
#include <string>
#include "checkers.h"
#include <fstream>
#include <stdio.h>
int sizeSort = 0;

class task {
public:
	union {
		int num;
		int tNum;
	};

	std::string author;
	std::string title;
	std::string publisher;

	int registrationNumber;
	int year;
	int pages;
};

task* creator(int& size) {
	char inputValidation[1000];
	task* library = new task[size];
	for (int i = 0; i < size; i++) {
		library[i].tNum = i + 1;
		library[i].num = library[i].tNum;
		std::cout << "Enter the registration number of book " << i + 1 << ": ";
		checkIntNatural1(inputValidation);
		library[i].registrationNumber = atoi(inputValidation);
		std::cout << "Enter the surname of author: ";
		//(std::cin >> library[i].author).get();
		rewind(stdin);
		getline(std::cin, library[i].author);
		std::cout << "\nEnter the title: ";;
		rewind(stdin);
		getline(std::cin, library[i].title);
		std::cout << "\nEnter the year of publication: ";
		checkIntYears(inputValidation);
		library[i].year = atoi(inputValidation);
		std::cout << "\nEnter the publisher: ";
		rewind(stdin);
		getline(std::cin, library[i].publisher);
		std::cout << "\nEnter the num of pages: ";
		checkIntNatural1(inputValidation);
		library[i].pages = atoi(inputValidation);
		std::cout << "\n\n";
	}
	return library;
}
void printer(task* library, int& size) {
	std::string s;
	std::ofstream out;
	out.open("D:\\all labs\\lab8\\task3output.bin", std::ios::binary);
	std::cout << "\n";
	for (int i = 0; i < size; i++) {
		/*out << "Book " << library[i].num << '\n';
		out << "Registration number: " << library[i].registrationNumber << '\n';
		out<< "Author - " << library[i].author << '\n';
		out << "Title - " << library[i].title << '\n';
		out << "Year of publication: " << library[i].year << '\n';
		out << "Publisher - " << library[i].publisher << '\n';
		out << "Total pages - " << library[i].pages;
		out << "\n\n";*/
		//out << library[i].num << '\n';
		out << library[i].registrationNumber;
		s = std::to_string(library[i].registrationNumber);
		for (int j = s.length(); j < 30; j++) {
			out << " ";
		}
		out << '\n';
		out << library[i].author;
		for (int j = library[i].author.length(); j < 30; j++) {
			out << " ";
		}
		out << '\n';
		out << library[i].title;
		for (int j = library[i].title.length(); j < 30; j++) {
			out << " ";
		}
		out << '\n';
		out << library[i].year;
		s = std::to_string(library[i].year);
		for (int j = s.length(); j < 30; j++) {
			out << " ";
		}
		out << '\n';
		out << library[i].publisher;
		s = library[i].publisher;
		for (int j = s.length(); j < 30; j++) {
			out << " ";
		}
		out << '\n';
		out << library[i].pages;
		s = std::to_string(library[i].pages);
		for (int j = s.length(); j < 30; j++) {
			out << " ";
		}
		out << '\n';
		std::cout << "Book " << library[i].num << '\n';
		std::cout << "Registration number: " << library[i].registrationNumber << '\n';
		std::cout << "Author - " << library[i].author << '\n';
		std::cout << "Title - " << library[i].title << '\n';
		std::cout << "Year of publication: " << library[i].year << '\n';
		std::cout << "Publisher - " << library[i].publisher << '\n';
		std::cout << "Total pages - " << library[i].pages;
		std::cout << "\n\n";
	}
}
void printerInFile(task* library, int& size) {
	std::string s;
	std::ofstream out;
	out.open("D:\\all labs\\lab8\\task3output.tx");
	for (int i = 0; i < size; i++) {
		out << library[i].registrationNumber;
		s = std::to_string(library[i].registrationNumber);
		for (int j = s.length(); j < 30; j++) {
			out << " ";
		}
		out << '\n';
		out << library[i].author;
		for (int j = library[i].author.length(); j < 30; j++) {
			out << " ";
		}
		out << '\n';
		out << library[i].title;
		for (int j = library[i].title.length(); j < 30; j++) {
			out << " ";
		}
		out << '\n';
		out << library[i].year;
		s = std::to_string(library[i].year);
		for (int j = s.length(); j < 30; j++) {
			out << " ";
		}
		out << '\n';
		out << library[i].publisher;
		s = library[i].publisher;
		for (int j = s.length(); j < 30; j++) {
			out << " ";
		}
		out << '\n';
		out << library[i].pages;
		s = std::to_string(library[i].pages);
		for (int j = s.length(); j < 30; j++) {
			out << " ";
		}
		out << '\n';
	}
}
task* removeElement(task* library, int index, int& size) {
	if (index == size) size--;
	else {
		for (int i = index; i < size; i++) {
			library[i - 1] = library[i];
		}
		size--;
	}
	return library;
}
task* addBook(task* library, int& size) {
	char inputValidation[1000];
	size++;
	task* temp = new task[size];
	for (int i = 0; i < size - 1; i++) {
		temp[i] = library[i];
	}
	temp[size - 1].num = size;
	std::cout << "Enter the registration number of book: ";
	checkIntNatural1(inputValidation);
	temp[size - 1].registrationNumber = atoi(inputValidation);
	std::cout << "Enter the surname of author: ";
	(std::cin >> temp[size - 1].author).get();
	std::cout << "\nEnter the title: ";;
	(std::cin >> temp[size - 1].title).get();
	std::cout << "\nEnter the year of publication: ";
	checkIntYears(inputValidation);
	temp[size - 1].year = atoi(inputValidation);
	std::cout << "\nEnter the publisher: ";
	(std::cin >> temp[size - 1].publisher).get();
	std::cout << "\nEnter the num of pages: ";
	checkIntNatural1(inputValidation);
	temp[size - 1].pages = atoi(inputValidation);
	std::cout << "\n\n";
	library = temp;
	return library;
}

task* changeElement(task* library, int index) {
	std::string s;
	const char* PATH = "D:\\all labs\\lab8\\task3output.bin";
	FILE* out;
	fopen_s(&out, PATH, "rb+");
	int n; char inputValidation[1000];
	printf("Choose the field you want to change:\n");
	printf("1 - Reg number\n2 - Author\n3 - Title\n4 - Year of publication\n5- Total pages\n6 - Publisher\n\n");
	checkIntChoice(inputValidation);
	n = atoi(inputValidation);
	if (n == 1) {
		std::cout << "Enter the registration number of book: ";
		checkIntNatural1(inputValidation);
		library[index - 1].registrationNumber = atoi(inputValidation);
		s = std::to_string(library[index - 1].registrationNumber);
		char* chars = new char[s.length() + 1];
		s.copy(chars, s.length());
		fseek(out, (index - 1) * 32 * 6 + 3 * 32 - 1, std::ios::beg);
		fwrite(chars, 1, s.length(), out);
		for (int i = s.length() + 1; i < 26; i++) {
			fwrite(" ", 1, 1, out);
		}

	}
	if (n == 2) {
		std::cout << "Enter the surname of author: ";
		rewind(stdin);
		getline(std::cin, library[index - 1].author);
		s = library[index - 1].author;
		char* chars = new char[s.length() + 1];
		s.copy(chars, s.length());
		fseek(out, (index - 1) * 32 * 6 + 1 * 32 - 1, std::ios::beg);
		fwrite(chars, 1, s.length(), out);
		for (int i = s.length() + 1; i < 26; i++) {
			fwrite(" ", 1, 1, out);
		}
	}
	if (n == 3) {
		std::cout << "\nEnter the title: ";
		rewind(stdin);
		getline(std::cin, library[index - 1].title);
		s = library[index - 1].title;
		char* chars = new char[s.length() + 1];
		s.copy(chars, s.length());
		fseek(out, (index - 1) * 32 * 6 + 2 * 32 - 1, std::ios::beg);
		fwrite(chars, 1, s.length(), out);
		for (int i = s.length(); i < 26; i++) {
			fwrite(" ", 1, 1, out);
		}
	}
	if (n == 4) {	
		std::cout << "\nEnter the year of publication: ";
		checkIntYears(inputValidation);
		library[index - 1].year = atoi(inputValidation);
		s = std::to_string(library[index - 1].year);
		char* chars = new char[s.length() + 1];
		s.copy(chars, s.length());
		fseek(out, (index - 1) * 32 * 6 + 3 * 32 - 1, std::ios::beg);
		fwrite(chars, 1, s.length(), out);
		for (int i = s.length() + 1; i < 26; i++) {
			fwrite(" ", 1, 1, out);
		}
	}
	if (n == 5) {
		std::cout << "\nEnter the num of pages: ";
		checkIntNatural1(inputValidation);
		library[index - 1].pages = atoi(inputValidation);
		s = std::to_string(library[index - 1].pages);
		char* chars = new char[s.length() + 1];
		s.copy(chars, s.length());
		fseek(out, (index - 1) * 32 * 6 + 2 * 32 - 1, std::ios::beg);
		fwrite(chars, 1, s.length(), out);
		for (int i = s.length(); i < 26; i++) {
			fwrite(" ", 1, 1, out);
		}
	}
	if (n == 6) {
		std::cout << "\nEnter the publisher: ";
		rewind(stdin);
		getline(std::cin, library[index - 1].publisher);
		s = library[index - 1].publisher;
		char* chars = new char[s.length() + 1];
		s.copy(chars, s.length());
		fseek(out, (index - 1) * 32 * 6 + 2 * 32 - 1, std::ios::beg);
		fwrite(chars, 1, s.length(), out);
		for (int i = s.length(); i < 26; i++) {
			fwrite(" ", 1, 1, out);
		}
	}
	fclose(out);
	return library;
}

void finder(task* library, int& size) {
	std::string check;
	char input[1000];
	int choose, regNumb, year;
	printf("Choose the searching element:\n1)Author / Publisher\n2) Num of pages\n3) Registration number\n4)Year of publication\n5)Title\n\n");
	scanf_s("%s", input, 2);
	while (isInt1(input) != 1 || (atoi(input) != 1 && atoi(input) != 2 && atoi(input) != 3 && atoi(input) != 4 && atoi(input) != 5)) {
		printf("Choose only 1 - 3. Incorrect input\n");
		scanf_s("%s", input, 3);
		fflush(stdin);
	}
	choose = atoi(input);
	if (choose == 3) {
		bool flag = 0;
		printf("Enter the registration number: ");
		checkIntNaturalSize1(input);
		regNumb = atoi(input);
		printf("\n\n");
		for (int i = 0; i < size; i++) {
			if (library[i].registrationNumber == regNumb) {
				std::cout << "Book " << library[i].num << '\n';
				std::cout << "Registration number: " << library[i].registrationNumber << '\n';
				std::cout << "Author - " << library[i].author << '\n';
				std::cout << "Title - " << library[i].title << '\n';
				std::cout << "Year of publication: " << library[i].year << '\n';
				std::cout << "Total pages - " << library[i].pages;
				std::cout << "\n\n";
				flag = 1;
			}
		}
		if (flag == 0) {
			printf("\nThere are no elements with such parameter\n");
		}
	}
	else if (choose == 1) {
		bool flag = 0;
		printf("Enter the Author / Publisher: ");
		(std::cin >> check).get();
		printf("\n\n");
		for (int i = 0; i < size; i++) {
			if (library[i].author == check) {
				std::cout << "Book " << library[i].num << '\n';
				std::cout << "Registration number: " << library[i].registrationNumber << '\n';
				std::cout << "Author - " << library[i].author << '\n';
				std::cout << "Title - " << library[i].title << '\n';
				std::cout << "Year of publication: " << library[i].year << '\n';
				std::cout << "Total pages - " << library[i].pages;
				std::cout << "\n\n";
				flag = 1;
			}
		}
		if (flag == 0) printf("\nThere are no elements with such parameter\n");
	}
	else if (choose == 2) {
		bool flag = 0;
		printf("Enter the number of pages: ");
		checkIntNatural1(input);
		regNumb = atoi(input);
		printf("\n\n");
		for (int i = 0; i < size; i++) {
			if (library[i].pages == regNumb) {
				std::cout << "Book " << library[i].num << '\n';
				std::cout << "Registration number: " << library[i].registrationNumber << '\n';
				std::cout << "Author - " << library[i].author << '\n';
				std::cout << "Title - " << library[i].title << '\n';
				std::cout << "Year of publication: " << library[i].year << '\n';
				std::cout << "Total pages - " << library[i].pages;
				std::cout << "\n\n";
				flag = 1;
			}
		}
		if (flag == 0) {
			printf("\n\nThere are no elements with such parameter\n\n");
		}
	}
	else if (choose == 5) {
		bool flag = 0;
		printf("Enter the Title: ");
		(std::cin >> check).get();
		printf("\n\n");
		for (int i = 0; i < size; i++) {
			if (library[i].title == check) {
				std::cout << "Book " << library[i].num << '\n';
				std::cout << "Registration number: " << library[i].registrationNumber << '\n';
				std::cout << "Author - " << library[i].author << '\n';
				std::cout << "Title - " << library[i].title << '\n';
				std::cout << "Year of publication: " << library[i].year << '\n';
				std::cout << "Total pages - " << library[i].pages;
				std::cout << "\n\n";
				flag = 1;
			}
		}
		if (flag == 0) printf("\nThere are no elements with such parameter\n");
	}
	else if (choose == 4) {
		bool flag = 0;
		printf("Enter the year: ");
		checkIntYears(input);
		year = atoi(input);
		printf("\n\n");
		for (int i = 0; i < size; i++) {
			if (library[i].registrationNumber == year) {
				std::cout << "Book " << library[i].num << '\n';
				std::cout << "Registration number: " << library[i].registrationNumber << '\n';
				std::cout << "Author - " << library[i].author << '\n';
				std::cout << "Title - " << library[i].title << '\n';
				std::cout << "Year of publication: " << library[i].year << '\n';
				std::cout << "Total pages - " << library[i].pages;
				std::cout << "\n\n";
				flag = 1;
			}
		}
		if (flag == 0) {
			printf("\nThere are no elements with such parameter\n");
		}
	}
}

task* quickSort(task* library, int left, int right) {
	int i = left, j = right;
	char y = library[(right + left) / 2].author[0];
	do {
		while (library[i].author[0] < y && i < right) i++;
		while (library[j].author[0] > y && j > left) j--;
		if (i <= j) {
			std::swap(library[i], library[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > left) quickSort(library, left, j);
	if (i < right) quickSort(library, i, right);
	return library;
}

task* creatorSorted(task* library, int size){
	std::ofstream out;
	out.open("D:\\all labs\\lab8\\task3.txt");
	char inputValidation[1000];
	int year, a = 0;
	std::cout << "\nEnter the year of publication: ";
	checkIntYears(inputValidation);
	year = atoi(inputValidation);
	for (int i = 0; i < size; i++) {
		if (library[i].year >= year) {
			a++;
		}
	}
	sizeSort = a;
	if (sizeSort == 0) {
		std::cout << "\nThere are no elements with such parameter\n";
		out << "\nThere are no elements with such parameter\n";

		return 0;
	}
	task* sortedLib = new task[sizeSort];
	for (int i = 0, j = 0; i < size; i++) {
		if (library[i].year >= year) {
			sortedLib[j] = library[i];
			j++;
		}
	}
	return quickSort(sortedLib, 0, sizeSort - 1);
}
void printerSorted(task* library, int& size) {
	std::ofstream out;
	out.open("D:\\all labs\\lab8\\task3outputreq.txt");
	std::cout << "\n";
	for (int i = 0; i < size; i++) {
		out << "Book " << library[i].num << '\n';
		out << "Registration number: " << library[i].registrationNumber << '\n';
		out << "Author - " << library[i].author << '\n';
		out << "Title - " << library[i].title << '\n';
		out << "Year of publication: " << library[i].year << '\n';
		out << "Publisher - " << library[i].publisher << '\n';
		out << "Total pages - " << library[i].pages;
		out << "\n\n";
		std::cout << "Book " << library[i].num << '\n';
		std::cout << "Registration number: " << library[i].registrationNumber << '\n';
		std::cout << "Author - " << library[i].author << '\n';
		std::cout << "Title - " << library[i].title << '\n';
		std::cout << "Year of publication: " << library[i].year << '\n';
		std::cout << "Publisher - " << library[i].publisher << '\n';
		std::cout << "Total pages - " << library[i].pages;
		std::cout << "\n\n";
	}
}

bool isEmpty() {
	bool checker;
	std::fstream input;
	input.open("D:\\all labs\\lab8\\task3input.txt");
	if (input.peek() == EOF) checker = false;
	else checker = true;
	return checker;
}
task* creatorWithFile(int& n) {
	std::ifstream entering;
	entering.open("D:\\all labs\\lab8\\task3input.txt", std::ios::in);
	entering >> n;
	char tmp[101];
	bool flag = 0;
	task* library = new task[n];
	for (int i = 0; i < n; i++) {
		library[i].tNum = i + 1;
		library[i].num = library[i].tNum;
		entering >> library[i].registrationNumber;
		entering >> library[i].author;
		entering >> library[i].title;
		entering >> library[i].year;
		entering >> library[i].publisher;
		entering >> library[i].pages;
	}
	return library;
}