#include "pch.h"
long long countZeros(long double** array, long long rows, long long cols);
long long reverseOutput(long long** array, long long m, long long n);


TEST(test_1) {
	long double temp = 0.54;
	long double** array = new long double* [3];
	for (int i = 0; i < 3; i++)
		array[i] = new long double[5];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if (i + j == 1) array[i][j] = 0;
			else array[i][j] = temp;
			temp *= 3;
		}
	}

	ASSERT_EQ(countZeros(array, 3, 5), 2);
}

TEST (test_2) {
	long double** array = new long double* [123];
	for (int i = 0; i < 123; i++)
		array[i] = new long double[54];

	for (int i = 0; i < 123; i++) {
		for (int j = 0; j < 54; j++) {
			array[i][j] = 0;
		}
	}
	ASSERT_EQ(countZeros(array, 123, 54), 123 * 54);
}

TEST(test_3) {
	long double temp = 1.2;
	long double** array = new long double* [5];
	for (int i = 0; i < 5; i++)
		array[i] = new long double[5];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			array[i][j] = temp;
			temp *= temp;
		}
	}
	ASSERT_EQ(countZeros(array, 5, 5), 0);
}

TEST(test_4) {
	long long temp = 9;
	long long** array = new long long* [3];
	for (int i = 0; i < 3; i++)
		array[i] = new long long[3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			array[i][j] = temp;
			temp--;
		}
	}
	ASSERT_EQ(reverseOutput(array, 3, 3), 123456789);
}
TEST(test_5) {
	long long temp = 1;
	long long** array = new long long* [2];
	for (int i = 0; i < 2; i++)
		array[i] = new long long[2];

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			array[i][j] = temp;
		}
	}
	ASSERT_EQ(reverseOutput(array, 2, 2), 1111);
}


long long countZeros(long double** array, long long rows, long long cols) {
	long long counter = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (array[i][j] == 0) {
				counter++;
			}
		}
	}
	return counter;
}
long long reverseOutput(long long** array, long long m, long long n) {
	long long sum = 0, counter = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sum += array[i][j] * powl(10, counter);
			counter++;
		}
	}
	return sum;
}