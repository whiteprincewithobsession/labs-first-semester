#include <iostream>
#include <cmath>
int main()
{
    long double R, P, Q, r;
    std:: cin >> R >> P >> Q;
    if(R <= 0 || P <= 0 || Q <= 0 || Q >= 1.57)
    {
    std:: cout << "Incorrect input";
    }
    else
    {
    r = P * sin(Q) / 2;
        if(R <= r)
        {
        std:: cout << "Sphere fits in rhombus";
        }
        else if(R > r)
        {
        std:: cout << "Sphere doesn't fit in rhombus";
        }
        else
        {
        std:: cout << "ERROR";
        }
    }
}