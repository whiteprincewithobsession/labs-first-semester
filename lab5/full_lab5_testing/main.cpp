//#include <iostream>
//#include "/tasks35/tasks35.h"
//#include "..\staticLib\n1llib.h";
//#include "/all labs/lab4/bestcheck/top.h"
//#include <Windows.h>
//#include "/all labs/lab5/t1/t1.h"
//#include "/all labs/lab5/t2/t2.h"
//#include "/all labs/lab5/t4/t4.h"
//#include "/all labs/lab5/t3/t3.h"
//#include "/all labs/lab5/t5/t5.h"
//
//int main() {
//	HINSTANCE load;
//	load = LoadLibrary(L"D:\\all labs\\lab5\\n2\\x64\\Debug\\DynamicLiib.dll");
//	char inputValidation[_MAX_INT_DIG];
//	int choice;
//	while (true) {
//		std::cout << "Choose the task you want:\n\n" << "1)Task 1\n\n2)Task 2\n\n3)Task 3\n\n4)Task 4\n\n5)Task 5\n\n";
//		std::cin >> inputValidation;
//		while (stringLength(inputValidation) > 1 || (inputValidation[0] != '1' && inputValidation[0] != '2' && inputValidation[0] != '3' && inputValidation[0] != '4' && inputValidation[0] != '5')) {
//			std::cout << "Wrong input. Try again.\n";
//			rewind(stdin);
//			std::cin >> inputValidation;
//		}
//		choice = atoi(inputValidation);
//		if (choice == 1) {
//			t1();
//		}
//		if (choice == 2) {
//			t2();
//		}
//
//		if (choice == 4) {
//			t4();
//		}
//		if (choice == 5) {
//			t5();
//		}
//		std::cout << '\n' << "Do you want to continue? (y / n) ";
//		char userChoice;
//		int counter = 0;
//		std::cin >> inputValidation;
//		while (stringLength(inputValidation) > 1 || (inputValidation[0] != 'y' && inputValidation[0] != 'n' && inputValidation[0] != 'N' && inputValidation[0] != 'Y')) {
//			std::cout << "Wrong input. Try again.\n";
//			std::cout << '\n' << "Do you want to continue? (y / n) ";
//			rewind(stdin);
//			std::cin >> inputValidation;
//		}
//		userChoice = inputValidation[0];
//		if (userChoice == 'n' || userChoice == 'N') return 0;
//	}
//
//}
