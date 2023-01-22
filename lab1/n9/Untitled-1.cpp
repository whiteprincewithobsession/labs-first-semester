#include <iostream>
#include <iomanip>
int main()
{
    int x, y;
    std:: cin >> x >> y;
    x = x ^ y;
    std:: cout << x <<" " << y << '\n';
    y = y ^ x;
    std:: cout << y << " " << x << '\n';
    x = x ^ y;
    std:: cout << x <<" " << y;
 return 0;
}