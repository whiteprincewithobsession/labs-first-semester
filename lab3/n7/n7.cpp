#include <iostream>
#include <iomanip>

long double Pow(long double a, long double b)
{
    long double temp = a;
    if (b == 0)
        return 1;
       long double sum = 0;
    for (int i = 1; i < b; i++)
    {
        a *= temp;      
    }    
    return a;
}

long double Fabs(long double a)
{
    if(a < 0)
        return -a;
    return a;
}

long double Min(long double a, long double b, long double c)
{
    if( a <= b && a <= c){
        return a;
    }
    else if( b <= a && b <= c){
        return b;
    }
    else if( c <= b && c <= a){
        return c;
    }
}
int main(){
    std::cout << std::setprecision(12);
long double a, b, c = 0, x, y, n = 10000, tempsin, xSin, tempcos, xCos, xExp, tempExp;
long long countPi, countExp, numExp = 0;
const long double doublepi = 6.283185307179586476;
const long double exponent = 2.718281828459045235;
std::cin >> x;
if(x == 0){
    std::cout << "ERROR";
}
else{
    //sinus
    xSin = x;
        while(xSin > 1e15){
    xSin -= doublepi * 1e12;
}
    if(xSin >= doublepi){
        countPi = xSin / doublepi;
        xSin -= countPi * doublepi;
    }
    else if(xSin < -1 * doublepi){
        countPi = Fabs(xSin / doublepi);
        xSin += countPi * doublepi;
    }
    a = xSin, tempsin = xSin;
    for (int i = 1; i <= n; i++){
        tempsin = tempsin * -1 * Pow(xSin, 2) / (2 * i *(2 * i + 1));
        a += tempsin;
    }
    std::cout << "xSin = " << xSin << " sinus = " << a;

    //cosine

    xCos = x;
        while(xCos > 1e16){
    xCos -= doublepi * 1e12;
}
    if(xCos >= doublepi){
        countPi = xCos / doublepi;
        xCos -= countPi * doublepi;
    }
    else if(xCos < -1 * doublepi){
        countPi = Fabs(xCos / doublepi);
        xCos += countPi * doublepi;
    }
    b = 0.999999, tempcos = 1;

    for(int i = 1; i <= n; i++ ){
        tempcos = tempcos * -1 * Pow(xCos, 2) / (2 * i *(2 * i - 1));
        b += tempcos;
    }
    std::cout << '\n' << "xCos = " << xCos << " cosine = " << b;

    //logarithm

    xExp = Fabs(x);
    bool expPow;
    if(xExp > 2) expPow = true;
    else expPow = false;
    while (xExp > 2 && expPow == true){
        xExp /= exponent; numExp++;
    }
    while (xExp < 2 && expPow == false){
        xExp *= exponent; numExp--;
    }
    for(int i = 1; i <= n; i++){
        c += Pow((xExp -1) / (xExp + 1), 2 * i - 1) / (2 * i - 1);
    }
    std::cout << '\n' << "xExp = " << xExp << " ln = " << 2 * c + numExp;
}
std::cout <<'\n' << Min(a, b, 2 * c + numExp);
}


