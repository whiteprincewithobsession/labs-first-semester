#include <iostream>
#include <cmath>
int main() {
    long double Q, S, Y, A, b, B, x, D, C, p, K, n, T, z, m, k, d, h, y ;


    std:: cin >> x >> D;
    
    b = x + D; 
    A = D * x / b;
    S = (powl(A, 2) + b * cos(x)) / (powl(D, 3) + (A + D - b));
    if (b == 0 || powl(D, 3) + (A + D - b) == 0)
    {
      std:: cout << " incorrect type " << '\n';
    }
    else{
    std:: cout <<" S1 = "<< S << '\n';
    }
   

    std:: cin >> K >> p >> C;
    A = x + sin(p); 
    B = exp(K);
    Y = 1 + powl(K, 2)/(2 * A * B) - B + D * C;
    if (2 * A * B == 0)
    {
     std:: cout << " incorrect type " << '\n';
    }
    else
    {
        std :: cout << " Y2 = " << Y <<'\n';
    }
    
  

    std:: cin>>n;
    B = cos(x); 
    C = p - n;
    Q = powl(B, 2) / K * D + B * powl(C, 3);
    if(K == 0)
    {
     std:: cout << " incorrect type " << '\n';
    }
    else
    {
     std:: cout << " Q3 = "<< Q << '\n';
    }
    

    std:: cin >> z >> y;
    A = x - y;
    B = sqrt(z);
    T = cos(x) + powl(A, 2)/(K - C * D) - B;
    if (K - C * D == 0)
    {
     std:: cout << " incorrect type " << '\n';
    }
    else
    {
        std:: cout << " T4 = "<< T << '\n';
    }


    std:: cin >> m >> n;
    A = abs(n + m);
    D = tan(x);
    Y = 1.29 + K / A + powl(D, 2);
    if(A == 0)
    {
     std:: cout << " incorrect type " << '\n';
    }
    else
    {
        std:: cout << " Y5 = " << Y << '\n';
    }

    A = x + y;
    D = abs(C - A);
    S = 10.1 + A / C + D / powl(K, 2);
    if(C == 0)
    {
     std:: cout << " incorrect type " << '\n';
    }
    else
    {
    std:: cout << " S6 = " << S << '\n';
    }
    
    std:: cin >> h;
    A = x - p;
    B = log(h);
    Y = 0.78 * B + powl(A, 3)/ (K * C * D);
    if(h <= 0 || K * C * D == 0)
    {
     std:: cout << " incorrect type " << '\n';
    }
    else
    {
    std:: cout << " Y7 = " << Y << '\n';
    }

    std:: cin >> d >> k;
    A = log10(abs(x));
    B = x + exp(d);
    Y = (A + B) - powl(C, 2) / k;
    if (d == 0 || k == 0)
    {
     std:: cout << " incorrect type " << '\n';
    }
    else
    {
     std:: cout << " Y8 = " << Y << '\n';
    }
    
    A = sin(x) - z;
    B = abs(p - x);
    Y = powl(A + B, 2) - K / (C * D);
    if (C * D == 0)
    {
     std:: cout << " incorrect type " << '\n';
    }
    else
    {
    std:: cout << " Y9 = " << Y << '\n';
    }

    A = log(x) - k;
    B = sqrt(z);
    Y = powl(D, 2) + powl(C, 2) / (0.75 * A) + B;
    if (A == 0)
    {
     std:: cout << " incorrect type " << '\n';
    }
    else
    {
    std:: cout << " Y10 = " << Y << '\n';
    }
    return 0;
}