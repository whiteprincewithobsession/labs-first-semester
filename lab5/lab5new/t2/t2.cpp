#include "/all labs/lab4/bestcheck/top.h"
#include "Windows.h"
#include <iostream>

void (*T2)() = (void(*)())GetProcAddress(LoadLibrary(L"D:\\all labs\\lab5\\dynlib\\x64\\Debug\\dynlib.dll"), "t2");

int main() {
	T2();
	//HINSTANCE load;
	//load = LoadLibrary(L"D:\\all labs\\lab5\\dynlib\\x64\\Debug\\dynlib.dll");
	//typedef void (*qCheck) ();
	//qCheck T2;
	//T2 = (qCheck)GetProcAddress(load, "t2");
	//FreeLibrary(load);
}
