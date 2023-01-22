#include <iostream>
#include <cmath>

int main()
{
    const long double B = acos(-1) / 2;
    int i;
    long double y, x, A = 0, H, M = 20;
    
     H = (B - A) / M;   

        for(int i = 0; i < 20; i++) {
            x = A + i * H;
            y = sin(x) - cos(x);
            if(y < 1e-8 && y > -1e-8){
                y = 0;
            }
            std::cout <<'\n' << y;
        }
}