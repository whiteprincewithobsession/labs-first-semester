#include <iostream>

int main() {
    int x, y;
    std :: cin >> x >> y;
    if(x != 0 && y != 0)
    {
    if(x % y == 0 || y % x == 0)
    {
        std:: cout << "YES";
    }
    else
    {
        std:: cout << "NO";
    }
    }
    if ( x == 0 && y != 0 || x != 0 && y == 0)
    {
        std:: cout << "YES";
    }
    else if (x == 0 && y == 0)
    {
        std:: cout << "ERROR";
    }
           
    // put your code here
    return 0;
}