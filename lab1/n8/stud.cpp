#include <iostream>

int main()
{
  int min2, min1, h1, h2, a_t1, a_t2, dif;
   std:: cin >> h1 >> min1 >> h2 >> min2;
   a_t1 = h1 * 60 + min1;
   a_t2 = h2 * 60 + min2;
   dif = (a_t2 - a_t1 + 60 * 24) % (60 * 24);

   std:: cout << "Total hours " << dif/60  << " and minutes " << dif % 60 << '\n';  
    return 0;
}