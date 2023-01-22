#include <iostream>
#include <clocale> 


int main() {
    std:: setlocale(LC_ALL, "Rus");
    long long K;
    std:: cin >> K;
    if(K % 10 == 0)
    {
    std:: cout << "мы нашли " << K << " gribov";
    }
    else if(K >= 11 && K <= 20)
    {
    std:: cout << "Mi nashli " << K << " gribov";
    }
    else if(K % 100 >= 11 && K % 100 <= 20)
    {
    std:: cout << "Mi nashli " << K << " gribov";
    }
    else if(K % 10 == 1)
    {
    std:: cout << "Mi nashli " << K << " grib";
    }
    else if(K % 10 >= 2 && K % 10 <= 4)
    {
    std:: cout << "Mi nashli " << K << " griba";
    }
    else if(K % 10 >= 5 && K % 10 <= 9)
    {
    std:: cout << "Mi nashli " << K << " gribov";
    }
    return 0;
}