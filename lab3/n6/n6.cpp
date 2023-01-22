#include <iostream>
#include <cmath>

int main()
{
long double step, y, n, minimalRoot;
std::cout << "Enter the number of checking interval ";
std::cin >> n;
if(n == 0){ 
std::cout << "ERROR";
}
step = 2.0 / n;

minimalRoot = y = sin(-1 + step) + tan(-1 + step) - 1 / (1 + (-1 + step) * (-1 + step));
for (long double x = -1 + step; x <= 1; x += step) {
    y = sin(x) + tan(x) - 1 / (1 + x * x);
    if(x == 0){
    std::cout << "ERROR in tan";
    return 0;
    }
    if(fabs(minimalRoot) > fabs(y)){
        minimalRoot = y;   
    }
    std::cout << minimalRoot << " " << x <<'\n';
}
std::cout << "Minimal root = " << minimalRoot;
}