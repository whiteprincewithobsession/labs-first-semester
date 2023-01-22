#include <iostream>
#include <cmath>

int main()
{
    long long a, b, sum = 0, i = 1;
    while(i <= 30)
    {
        if(i % 2 == 0)
        {
            a = i / 2;
            b = i * i * i;
        }
        else if(i % 2 != 0)
        {
            a = i;
            b = i * i;
        }
        sum += powl(a - b, 2);
        i++;
    }
    std::cout << sum;
}