#include "pch.h"
long long oddInEven(long long** array, long long rows, long long cols);
long double oddInEvenAverageSum(long long** array, long long rows, long long cols);
long long* oddMassive(long long** array, long long m, long long n);



TEST(test_task5_intmaxmore) {
	long long** a = new long long* [3];
	a[0] = new long long [3] {999999999999999999, 400000000, 999999999999999999};
	a[1] = new long long [3] {2999990, 500000000, 999999999999999999};
	a[2] = new long long [3] {999999999999999999, 800000000, 999999999999999999};
	ASSERT_EQ(oddInEvenAverageSum(a, 3, 3), 99999999999999999);

}

TEST(test_task5_typical) {
	long long** a = new long long* [3];
	a[0] = new long long [3] {11, 400000000, 11};
	a[1] = new long long [3] {2999990, 500000000, 11};
	a[2] = new long long [3] {11, 800000000, 11};
	ASSERT_EQ(oddInEvenAverageSum(a, 3, 3), 11);
}

TEST(test_task5_2) {
	int f = 0;
	long long** a = new long long* [3];
	a[0] = new long long [3] {65432, 21356, 985643};
	a[1] = new long long [3] {42371, 1234567, 985643};
	a[2] = new long long [3] {1461, 4138724, 73223};
	long long* b = new long long[5];
	int counter = oddInEven(a, 3, 3);
	for (int j = 0; j < 3; j++) {
		if (j % 2 == 0) {
			for (int q = 0; q < 3; q++) {
				if (a[q][j] % 2 == 1) {
					b[f] = a[q][j];
					f++;
				}
			}
		}
	}
	long long* array = oddMassive(a, 3, 3);
	for (int i = 0; i < counter; i++) {
		ASSERT_EQ(*(array + i), *(b + i));
	}
}

TEST(test_task5_1) {
	int f = 0;
	long long** a = new long long* [3];
	a[0] = new long long [3] {1, 2, 3};
	a[1] = new long long [3] {4, 5, 6};
	a[2] = new long long [3] {7, 8, 9};
	long long* b = new long long [3];
	int counter = oddInEven(a, 3, 3);
	for (int j = 0; j < 3; j++) {
		if (j % 2 == 0) {
			for (int q = 0; q < 3; q++) {
				if (a[q][j] % 2 == 1) {
					b[f] = a[q][j];
					f++;
				}
			}
		}
	}

	long long* array = oddMassive(a, 3, 3);
	for (int i = 0; i < counter; i++) {
		ASSERT_EQ(*(array + i), * (b + i));
	}
}


TEST(test_task5_3) {
	long long temp = 1;
	long long** ptrarray = new long long* [3];
	for (int count = 0; count < 3; count++)
		ptrarray[count] = new long long[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ptrarray[i][j] = temp;
			temp ++;
		}
	}
	ASSERT_EQ(oddInEven(ptrarray, 3, 3), 4);
}
TEST(test_task5_4) {
	long long temp = 0;
	long long** ptrarray = new long long* [3];
	for (int count = 0; count < 3; count++)
		ptrarray[count] = new long long[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ptrarray[i][j] = temp;
		}
	}
	ASSERT_EQ(oddInEven(ptrarray, 3, 3), -1);
}




long long oddInEven(long long** array, long long rows, long long cols) {
	long long sum = 0, oddCounter = 0;
	for (int j = 0; j < cols; j++) {
		if (j % 2 == 0) {
			for (int q = 0; q < cols; q++) {
				if (array[q][j] % 2 == 1) {
					oddCounter++;
					sum += array[q][j];
				}
			}
		}
	}
	if (oddCounter != 0) return oddCounter;
	else return -1;
}

long double oddInEvenAverageSum(long long** array, long long rows, long long cols) {
	long double sum = 0, oddCounter = 0;
	for (int j = 0; j < cols; j++) {
		if (j % 2 == 0) {
			for (int q = 0; q < rows - 1; q++) {
				if (array[q][j] % 2 == 1) {
					oddCounter++;
					sum += array[q][j];
				}
			}
		}
	}
	if (oddCounter != 0) return sum /= oddCounter;
	else return -1;
}

long long* oddMassive(long long** array, long long m, long long n) {
	long long f = 0; long long sum = 0;
	if (oddInEven(array, m, n) == -1) {
		return nullptr;
	}
	else {
		long long* array2 = new long long[oddInEven(array, m, n)];
		for (int j = 0; j < n; j++) {
			if (j % 2 == 0) {
				for (int q = 0; q < n; q++) {
					if (array[q][j] % 2 == 1) {
						array2[f] = array[q][j];
						f++;
					}
				}
			}
		}
		return array2;
	}

}