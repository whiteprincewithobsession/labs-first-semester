#include <iostream>
 
using namespace std;
 
int main()
{
    long double a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if( a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0)
    {
     std:: cout << "Incorrect input";
    }
    else if( (a <= x && b <= y) || (a <= x && c <= y) || (b <= x && c <= y) ||( a <= y && b <= x) || (a <= y && c <= x) || (b <= y && c <= x))
    {
     std:: cout << "YES";
    }
    
    else 
    {
     std:: cout << "NO";
    }
    return 0;
    }