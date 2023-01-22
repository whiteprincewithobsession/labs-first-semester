#include <iostream>
#include <iomanip>

int main() {
    long double Z, a, b, c, d;
    std:: cin >> a >> b >> c >> d;
    if (c == 0)
    {
        std:: cout << "ERROR";
        return 0;
    }
    else if (c >= d && a < d)
    {
        Z = a + b/c;
    }
    else if (c < d && a >= d)
    {
        Z = a - b / c;
    }
    
    else
    {
     Z = 0;
    }
    std:: cout << std:: setprecision(20) << Z;
    // put your code here
    return 0;
}