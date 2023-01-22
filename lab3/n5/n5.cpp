#include <iostream>
#include <cmath>

int main()
{
    long double x, ln, tempRow;
    int countRoots, endRow = 4;
    std::cin >> countRoots;
    if(std::cin.fail())
    {
        std::cout << "Failed";
    }
    for(int i = 0; i < countRoots; i++){
        std::cin >> x; 
        ln = log(1 / (2 + 2 * x + x * x));
        long double lnRow = -1 * (1 + x) * (1 + x);
        for(int q = 2; q <= endRow; q++ ){
            tempRow = -1 * (1 + x) * (1 + x);
            lnRow += -1 * (1 + x) * (1 + x) / q * tempRow;

        }
        if(std::cin.fail() ||   x < 0.099999999 || x > 1 ){
            std::cout << "Failed. Input x from 0.1 to 1" << '\n';
            i -= 1;
            std::cin.clear();
            std::cin.ignore(2);
            continue;
        }
        else{
            std::cout << "ln = " <<  ln << " lnRow = " << lnRow << '\n';
        }
    }
}