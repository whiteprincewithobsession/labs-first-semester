#include <iostream>
#include <cmath>    
int main()
{
 long double y, n, x, z, k, m, fx;
 long long a;
 std:: cout << "Enter z ";
 std:: cin >> z;
if(z > 1)
{
    x = 1 / sqrt(z - 1);
}
else if(z <= 1)
{
    x = z * z + 1;                                        
}
else
{
    std:: cout << "Incorrect type of input";
}

 std:: cout << "Choose the type of function" << '\n';
 std:: cout << "1.f(x) = 2x " << '\n' << "2.f(x) = x * x * x" << '\n' << "3.f(x) = x/3" << '\n';
 std:: cin >> a;
 switch(a)
 {
    case(1):
    fx == 2 * x;
    break;

    case(2):
    fx = x * x * x;
    break;

    case(3):
    fx = x / 3;
    break;

    default:
    std:: cout <<'\n' << "Incorrect choice";
    
    break;

}
std:: cout << "Enter n k m " << "\t";
std:: cin >> n >> k >> m;
if (x == 0 || m == 0)
{
    std:: cout << "Mathematical ERROR";
}
else{
y = sin(n * fx) + cos(k * x) + log(m* x);
std:: cout << y;
}
return 0;

}