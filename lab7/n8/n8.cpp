#include <iostream>
#include <string>

std::string numToTernary(int a);

int main() {
	long long a;
	std::cin >> a;
    std::string result = numToTernary(a);
    std::string s20 = "13";
    std::string s30 = "23";
    std::string s10 = "03";
    //std::cout << result;
    int countOp = 0;
    for (int i = 0; i < result.length() - 1; i++) {
        if (result[i] == '1' && result[i + 1] == '0') {
            result.replace(i, 2, s10);
            if (i != 0) {
                i -= 2;
            }
        }
        if (result[i] == '2' && result[i + 1] == '0') {
            result.replace(i, 2, s20);
            i--;
        }
        if (result[i] == '3' && result[i + 1] == '0') {
            result.replace(i, 2, s30);
            i--;
        }
    }
   while (result[0] == '0') {
        result.erase(0, 1);
    }
    std::cout << result;
}


std::string numToTernary(int a) {
    std::string s1;
    int temp = a;
    while (temp != 0) {
        s1.insert(0, 1, (temp % 3) + 48);
        temp /= 3;
    }
    return s1;
}