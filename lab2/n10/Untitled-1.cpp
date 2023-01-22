#include <iostream>
#include <cmath>
int main()
{
    double x1, y1, x2, y2, r, R, d;
    std:: cout << "Enter the position of circle 1 and radius, x1 y1 r" << '\n';
    std:: cin >> x1 >> y1 >> r;
    std:: cout << "Enter the position of circle 2, x2 y2 R" << '\n';
    std:: cin >> x2 >> y2 >> R;
    if (r > 0 && R > 0)
    {
        
        d = sqrt(powl(x1 - x2, 2) + powl(y1 - y2, 2));
        if(R > r)
        {
        if(R + r < d)
        {
            std:: cout << "The circles don't cross";
        }
        else if(d < R + r && d > R && d > r)
        {
            std:: cout << "The circles cross 2 times";
        }
        else if(d < R - r && d < R)
        {
            std:: cout << "The circle1 contains in circle 2 ";
        }
        else if(d > R - r && d < R)
        {
            std:: cout << "The circles cross 2 times";
        }
        }
        else if(R < r)
        {
        if(R + r < d)
        {
            std:: cout << "The circles don't cross";
        }
        else if(d < R + r && d > R && d > r)
        {
            std:: cout << "The circles cross 2 times";
        }
        else if(d < r - R)
        {
            std:: cout << "The circle2 contains in circle1";
        }
        else if(d > r - R && d < r)
        {
            std:: cout << "The circles cross 2 times";
        }
        }

    }
    else
    {
        std:: cout << "Incorrect input";
    }
}