#pragma once
struct statement;
extern int sizearray;
long double averageInUn(statement* applicants, int& size);
statement* creator(int& n);
statement* addApplicant(statement* applicants, int& size);
void printerArray(statement* applicants, int n);
statement* changeElement(statement* applicants, int index);
void selectionSort(statement* applicants, int& size);
statement* creatorSorted(statement* applicants, int& size, long double supp);
statement* removeElement(statement* applicants, int index, int& size);
void finder(statement* applicants, int& size);