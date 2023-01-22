#include <iostream>

int main()
{
    int a, S;
    std::cin >> a;
    if(a % 2 == 0)
    {
        S = (2 + a) / 2 * a / 2;  
        std::cout << S;

    }
        else if(a % 2 == 1)
    {
        S = (1 + a) / 2 * (a - 1) / 2;
        std::cout << S;
 
    }
    else
    {
        std::cout << "ERROR";
    }
}