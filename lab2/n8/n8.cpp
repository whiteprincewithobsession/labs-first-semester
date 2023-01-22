#include <iostream>
#include <cmath>
int main()

{
    long double a, b, c, x, p, q, D, x1, x2, x3, x4, x11, x22, t1, t2, d1, d2, corner, pi = 3.1415, part;
    long long choice;
    std:: cout << "Which equation you want to solve?" << '\n';
    std:: cout << "1. ax^4 + bx^2 + c = 0" << '\n' << "2. ax^4 + bx^3 + cx^2 + bx + a = 0" << '\n' << "3. x^3 + px + q = 0" << '\n';
    std:: cin >> choice;
    switch(choice)
    {
        case (1):
        std:: cin >> a >> b >> c;
        if (a > 0 || a < 0 )
        {
         D = b * b - 4 * a * c;
        if(D < 0)
        {
            std:: cout << "No solution";
        }
        else 
        {
            x11 = (-b + sqrt(D))/(2*a);
            x22 = (-b - sqrt(D))/(2*a);
            if(x11 < 0 && x22 < 0)
            {
                std:: cout << "No solution";
            }
            else if(x11 >= 0 && x22 < 0)
            {
                x1 = sqrt(x11);
                x2 = sqrt(x11) * (-1);
                std:: cout << "x1 = " << x1 << '\n' << "x2 = " << x2;
            }
            else if(x11 >= 0 && x22 >= 0)
            {
                std:: cout << x11 << x22;
                x1 = sqrt(x11);
                x2 = sqrt(x11) * (-1);
                x3 = sqrt(x22);
                x4 = sqrt(x22) * (-1);
            }
            else if(x11 < 0 && x22 >= 0)
            {
                x1 = sqrt(x22);
                x2 = sqrt(x22) * (-1);
                std:: cout << "x1 = " << x1 << '\n' << "x2 = " << x2;  
            }        
        }
        }
        else 
        {
        std:: cout << "INVALID TYPE";
        }
        break;
        case(2):
        std:: cin >> a >> b >> c;
        D = b * b + 8 * a * a - 4 * a * c;
        t1 = (-1 * b + sqrt(D))/(2*a);
        t2 = (-1 * b - sqrt(D))/(2*a);
        if (a == 0)
        {
            std:: cout << "ERROR";
        }
        else
        {
        if(D < 0)
        {
            std:: cout << "No solution";
        }
        else if(t1 < 0 && t2 < 0)
        {
            std:: cout<< "No solution";              
        }
        else
        {
            d1 = t1 * t1 - 4;
            d2 = t2 * t2 - 4;
        if(d1 >= 0 && d2 < 0)
        {
            x1 = (t1 * (-1) + sqrt(d1))/2;
            x2 = (t1 * (-1) - sqrt(d1))/2;
            std:: cout << x1 << " " << x2;
        }     
        else if(d1 < 0 && d2 >= 0)
        {
            x1 = (t2 * (-1) + sqrt(d2))/2;
            x2 = (t2 * (-1) - sqrt(d2))/2;
            std:: cout << x1 << " " << x2;
        }   
        else if(d1 >= 0 && d2 >= 0)
        {
            x1 = (t1 * (-1) + sqrt(d1))/2;
            x2 = (t1 * (-1) - sqrt(d1))/2;
            x3 = (t2 * (-1) + sqrt(d2))/2;
            x4 = (t2 * (-1) - sqrt(d2))/2;
            std:: cout << -1 * x1 << " " << -1 * x2 << " " << -1 * x3 << " " << -1 * x4;
        }
        else
        {
            std:: cout << "No solutions with this coefs";
        }
        }
        }
        break;
        case (3):
        std::cin >> p >> q;
        D = powl(p / 3, 3) + powl(q / 2, 2);
        if (D < 0) {
            corner = acos(-(q / 2) * powl(3 / (-p), 3.0 / 2.0));
            x1 = 2 * sqrtl(-p / 3) * cos(corner / 3);
            x2 = 2 * sqrtl(-p / 3) * cos(corner / 3 + 2 * pi / 3);
            x3 = 2 * sqrtl(-p / 3) * cos(corner / 3 - 2 * pi / 3);

                std::cout << x1 << " " << x2 << " " << x3;
            }
        else if(D > 0) 
        {
            x1 = cbrt(-q / 2 + sqrtl(D)) + cbrt(-q / 2 - sqrtl(D));
            std::cout << x1;
        }
        else if(D==0) {
            if((-q/2)>=0) {
            x1= cbrt(-q/2);
            }
            else
            {
            x1 = - cbrt(-q/2);
            }
            std::cout<< 2 * x1 <<" "<< -x1 <<'\n';
            break;
            }
        break;
        default:
        std:: cout << "Incorrect choice";
}
return 0;
}