#include <iostream>
#include<cmath>
#include<iomanip>
int main() {
    double h, g = 9.8, t;
    std::cin >> h;
    t = sqrt(2 * h / g);
    std::cout << std::setprecision(9) << t;
    return 0;
}