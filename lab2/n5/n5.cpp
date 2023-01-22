#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    long double k, x, y, a = 0.0001;
    
    std::cin >> k >> x >> y;
 
    if (k < 0)
    {
        if (x >= k && x <= 0 && y >= k && y <= 0)
        {
            0 - x;
            0 - y;
            y - k;
            x - k;
            if (0 - x <= 0 - y && 0 - x <= y - k && 0 - x <= x - k)
            {
                std::cout << std:: setprecision(22) << 0 - x;
                return 0;
            }
            else if (0 - y <= 0 - x && 0 - y <= y - k && 0 - y <= x - k)
            {
                std::cout << std:: setprecision(22) << 0 - y;
                return 0;
            }
            else if (y - k <= 0 - y && y - k <= 0 - x && y - k <= x - k)
            {
                std::cout << std:: setprecision(22) << y - k;
                return 0;
            }
            else if (x - k <= 0 - y && x - k <= 0 - x && x - k <= y - k)
            {
                std::cout << std:: setprecision(22) << x - k;
                return 0;
            }
            else
            {
                std::cout << "0";
                return 0;
            }
        }
        if (x <= k && y >= k && y <= 0)
        {
            std::cout << std:: setprecision(22) << k - y;
        }
        else if (x >= k && x <= a && y >= 0)
        {
            std::cout << std:: setprecision(22) << y;
        }
        else if (x < k && y > 0)
        {
            std::cout << std:: setprecision(22) << sqrtl(powl(k - x, 2) + y * y);
        }
        else if (x < k && y < k)
        {
            std::cout << std:: setprecision(22) << sqrtl(powl(k - x, 2) + powl(y - k, 2));
        }
        else if (x >= 0 && y < k)
        {
            std::cout << std:: setprecision(22) << sqrtl(x * x + powl(y - k, 2));
        }
        else if (x >= 0 && y <= 0 && y >= k)
        {
            std::cout << std:: setprecision(22) << x;
        }
        else if (x >= 0 && y >= 0)
        {
            std::cout << std:: setprecision(22) << sqrtl(x * x + y * y);
        }
    }
    if (k > 0)
    {
        if (x <= k && x >= 0 && y <= k && y >= 0)
        {
            k - y;
            k - x;
            if (x <= y && x <= k - y && x <= k - x)
            {
                std::cout << std:: setprecision(22) << x << '\n';
            }
            else if (y <= x && y <= k - y && y <= k - x)
            {
                std::cout << std:: setprecision(22) << y;
            }
            else if (k - y <= y && k - y <= x && k - y <= k - x)
            {
                std::cout << std:: setprecision(22) << k - y;
            }
            else if (k - x <= y && k - x <= x && k - x <= k - y)
            {
                std::cout << std:: setprecision(22) << k - x;
            }
            else
            {
                std::cout << std:: setprecision(22) << 0;
            }
        }
        else if (x <= 0 && y <= 0)
        {
            std::cout << std:: setprecision(22) << sqrtl(x * x + y * y);
        }
        else if (x <= 0 && y >= 0 && y <= k)
        {
            std::cout << std:: setprecision(22) << 0 - k;
        }
        else if (y >= k && x <= 0)
        {
            std::cout << std:: setprecision(22) << sqrtl(powl(y - k, 2) + x * x);
        }
        if (x >= 0 && x <= k && y >= k)
        {
            std::cout << std:: setprecision(22) << y - k;
        }
        if (x >= k && y >= k)
        {
            std::cout << std:: setprecision(22) << sqrtl(powl(x - k, 2) + powl(y - k, 2));
        }
        if (y >= 0 && y <= k && x >= k)
        {
            std::cout << std:: setprecision(22) <<  x - k;
        }
        if (x >= 0 && x >= k && y <= 0)
        {
            std::cout << std:: setprecision(22) << sqrt(powl(x - k, 2) + y * y);
        }
        if (x >= 0 && x <= k && y <= 0)
        {
            std::cout << std:: setprecision(22) << 0 - y;
        }
    }
}   