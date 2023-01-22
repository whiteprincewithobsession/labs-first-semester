#include <iostream>
int main()
{
 long double a, b, c, Y;
 long long N;
 std:: cout << "Enter the numbers N a b c" << '\n';
 std:: cin >> N >> a >> b >> c;
 switch(N)
{
 case 2:
 Y = b * c - a * a;
 break;
 case 56:
 Y = b * c;
 break;
 case 7:
 Y = a * a + c;
 break;
 case 3: 
 Y = a - b * c;
 break;
 default:
 Y = (a+b) * (a+b) * (a+b);
 break;
 
}
std:: cout << Y;
}