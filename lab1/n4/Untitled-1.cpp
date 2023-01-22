#include <iostream>
#include<iomanip>
using namespace std;
int main() {
   long double b1, s, q=1.0/14;
   std::cin>>b1;
   s=b1/(1-q);
   cout<<setprecision(8)<<s;
    return 0;
}