#include <iostream>
#include<cmath>
int main(){
    int n = 1;
    long double sum = 0, e = 0.001;
    do{
        sum += 1 / powl(2, n) + 1 / powl(3, n);
        n++;  
    }while(1 / powl(2, n) + 1 / powl(3, n) >= e);
    std::cout << sum;
}