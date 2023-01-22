#include <iostream>
int main()
{
    double x, y;
    bool inequality;
    std:: cin >> x >> y;
    if(x > y)
    {
        inequality = true;
    }
    else
    {
        inequality = false;
    } 
    std:: cout << (inequality ? x : y) << " is the biggest";
}    