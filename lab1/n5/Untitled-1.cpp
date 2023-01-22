#include<iostream>
#include<iomanip>
int main()
{
    long long a1, a100;
    long double d, s;
    std::cin>>a1;
    std::cin>>a100;
    d=(a100-a1)/99;
    s=(2*a1+d*22)*23/2;
    std::cout<< std:: setprecision(10) <<d<<'\n'<<s;
    return 0;
}