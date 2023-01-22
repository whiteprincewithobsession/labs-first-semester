#include <iostream>

int main()
{
   long long a, b = 1, S = 0;
   b -= 1;
   std::cin >> a;
   while(b <= a)
   {
    S += b;
    b += 2;
   }
   std::cout << S;
   
}