#include <iostream>
#include <cmath>
int main(){
    long double t, s0, s1, s2, v1, v2, a, b, c, discr, x1, x2;
    std::cin >> t >> s0 >> s1 >> s2 >> v1 >> v2;
    a = s1 + s0 + s2;
    b = s0 * v1 - s1 * v2 - s0 * v2 + s2 * v1;
    c = -1 * s0 * v1 * v2;
    discr = powl(b, 2) - 4 * (c) * (a);
    x1 = ((-1) * b + sqrtl(discr)) / (2 * a);
    x2 = ((-1) * b - sqrtl(discr)) / (2 * a);
    std::cout << x1 << " " << x2;
    if(x1 > 0 && x2 < 0){
        std::cout << x1;
    }
    else if(x2 > 0 && x1 < 0){
        std::cout << x2;
    }
}