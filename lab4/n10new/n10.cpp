#include <iostream>
int main() {
    long long N;
    long long sum;
    std::cin >> N;
    if(N > 90){
    long long N1, numLength = 0, tempLength = 0, tempN;
	long long arr[50]{};
	long long arr2[50]{};
	if (N % 2 == 1) {
		N1 = (N - 1) / 2;
		for (numLength = 0; N != 0; numLength++) {
			arr[numLength] = N % 10;
			N /= 10;
			//std::cout << arr[numLength];
		}
		//std::cout << '\n';
		if (arr[numLength - 1] == 1) {
			tempLength = numLength - 1;
		}
		else {
			tempLength = numLength;
		}
		for (int i = 0; i <= tempLength - 1; i++) {
			arr2[i] = N1 % 10;
			N1 /= 10;
			//std::cout << arr2[i];
		}
	}
	else if (N % 2 == 0) {
		N1 = N - 1;
		for (numLength = 0; N1 != 0; numLength++) {
			arr[numLength] = N1 % 10;
			N1 /= 10;
			//std::cout << arr[numLength];
		}
		if (arr[numLength - 1] == 1 &&	arr[numLength - 2] != 9) {
			tempLength = numLength - 1;
		}
		else {
			tempLength = numLength;
		}
		N /= 2;
		//std::cout << '\n';
		for (int i = 0; i <= tempLength - 1; i++) {
			arr2[i] = N % 10;
			N /= 10;
			//std::cout << arr2[i];
		}
	}
	//std::cout << '\n';
	int mult = 0, rank = 0, count = 0, tempMult, composition;
	int multiply[80]{};
	for (int i = 0; i <= numLength; i++) {
		count = rank;
		for (int q = 0; q <= numLength; q++) {
			composition = arr[i] * arr2[q];
			multiply[count] += composition % 10;
			//std::cout << "mult[count] = " << mult[count] << '\n';
			if (multiply[count] > 9) {
				tempMult = multiply[count];
				multiply[count] %= 10;
				multiply[count + 1] += tempMult / 10;
			}
			multiply[count + 1] += composition / 10;

			count++;
		}
		rank++;
	}
	/*std::cout << '\n';
	for (int i = count + 1; i >= 0; i--) {
		if ((i == count + 1 || i == count || i == count - 1 || i == count - 2) && multiply[i] == 0) {
			continue;
		}
		else {
			std::cout << multiply[i];
		}
	}
	
	std::cout << '\n';*/

	multiply[0] += 1;
	if (multiply[0] == -1) {
		for (int i = 0; i <= count + 1; i++) {
			if (multiply[i] == -1) {
				multiply[i] += 10;
				multiply[i + 1] -= 1;
			}
			else {
				break;
			}
		}
	}
	for (int i = count + 1; i >= 0; i--) {
		if ((i == count + 1 || i == count || i == count - 1 || i == count - 2) && multiply[i] == 0) {
			continue;
		}
		else {
			std::cout << multiply[i];
		}
	}
    }
    else{
    sum = N*(N + 1) / 2 - N + 1;
    std::cout << sum;
    }
    // put your code here
    return 0;
}