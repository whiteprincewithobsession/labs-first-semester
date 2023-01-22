#pragma once
#include <iostream>
#include <string>
#include "checkers.h"
extern int sizeSort;
class task;
task* creator(int& size);
void printer(task* library, int& size);
task* removeElement(task* library, int index, int& size);
task* addBook(task* library, int& size);
void finder(task* library, int& size);
task* changeElement(task * library, int index);
task* quickSort(task* library, int left, int right);
task* creatorSorted(task* library, int size);
void printerSorted(task* library, int& size);
void printerInFile(task* library, int& size);
bool isEmpty();
task* creatorWithFile(int& n);