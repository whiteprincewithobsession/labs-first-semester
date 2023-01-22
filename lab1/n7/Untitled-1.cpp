#include<cmath>
#include<iomanip>
#include <iostream>

int isInt(char input[]);
double stringToDouble(char inout[]);
int stringLengthUntilEmptyElement(char string[]);
double power(double a, int b);
int isFloat(char input[]);

int main() {
    std::cout.precision(5);
    const long double pi = acos(-1);
    double x1, y1, x2, y2, x3, y3, AB, BC, AC;
    char x1str[100];
    std::cin >> x1str;
    if(isInt(x1str) == 0){
        std::cout << "Hello, World!";
        return 0;
    }
    x1 = stringToDouble(x1str);
    AB = sqrt((x1 - x2) * ( x1 - x2) + (y1 - y2) * ( y1 - y2 ));
    BC = sqrt((x2 - x3) * ( x2 - x3 ) + ( y2 - y3 ) * ( y2 - y3));
    AC = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    std:: cout << AB << '\n' << BC << '\n' << AC << '\n' ;
    
    long double p, h1, h2, h3, s1;
    p = (AB + BC + AC) / 2;
    s1 = sqrt(p * (p - AB) * (p - AC) * (p - BC));
    h1 = 2 * s1 / AB;
    h2 = 2 * s1 / BC;
    h3 = 2 * s1 / AC;
    std:: cout  << "heightAB = " << h1 << '\n' << "heightBC = " << h2 << '\n' << "heightAC = " << h3 << '\n';
   
    long double m1, m2, m3;
    m1 = sqrt(2 * BC * BC + 2 * AC * AC - AB * AB) / 2;
    m2 = sqrt(2 * AB * AB + 2 * AC * AC - BC * BC) / 2;
    m3 = sqrt(2 * AB * AB + 2 * BC * BC - AC * AC) / 2;
    std:: cout << " med1 = " << m1 << '\n' << " med2 = " << m2 << '\n' << " med3 = " << m3 << '\n';

    long double b1, b2, b3;
    b1 = 2 * sqrt(BC * AC * p * (p - AB)) / (BC + AC);
    b2 = 2 * sqrt(AB * AC * p * (p - BC)) / (AB + AC);
    b3 = 2 * sqrt(AB * BC * p * (p - AC)) / (AB + BC);
    std:: cout << "bis1 = " << b1 << '\n' << " bis2 = " << b2 << '\n' << " bis3 = " << b3 << '\n';

    long double a1, a2, a3, deg1, deg2, deg3, rad1, rad2, rad3;
    a1 = (BC * BC + AC * AC - AB * AB) / (2 * BC * AC);
    a2 = (AB * AB + AC * AC - BC * BC) / (2 * AB * AC);
    a3 = (AB * AB + BC * BC - AC * AC) / (2 * AB * BC);
    rad1 = acos(a1);
    rad2 = acos(a2);
    rad3 = acos(a3);
    deg1 = rad1 * 180 / pi;
    deg2 = rad2 * 180 / pi;
    deg3 = rad3 * 180 / pi;
    std:: cout  << rad1 <<' ' << deg1 << '\n';
    std:: cout  << rad2 <<' ' << deg2 << '\n';
    std:: cout  << rad3 <<' ' << deg3 << '\n';
    
    long double R, sR, r, sr, lr, lR;
    R = AB * BC * AC / 4 / s1;
    sR = R * R * pi;
    r = s1 / p;
    sr = r * r * pi;
    lr = 2 * r * pi;
    lR = 2 * R * pi;
    std:: cout << "R = " << R << '\n' << "r = " << r << '\n';
    std:: cout << "lengthr = " << lr << '\n' << "squarer = " << sr << '\n';
    std:: cout << "lengthR = " << lR << '\n' << "squareR = " << sR << '\n';
    
    long double s2, s3, per;
    s2 = AB * h1 / 2;
    s3 = AB * BC * sin(rad3) / 2;
    per = AB + BC + AC;
    std:: cout <<"Square of triangle = "<<s1<<" or "<<s2<<" or "<<s3<<'\n' << "P = " << per;
   
    return 0;
}



int isInt(char input[]) {
  if (input[0] == '-' || (input[0] >= '0' && input[0] <= '9')) {
    if (stringLengthUntilEmptyElement(input) == 1) {
      return 1;
    }
    else {
      for (int i = 1; i < stringLengthUntilEmptyElement(input); i++) {
        if (input[i] < '0' || input[i] > '9') return 0;
      }
      return 1;
    }
  }
  else return 0;
  return 1;
}

int isFloat(char input[]) {
  int pointCounter = 0;
  if (input[0] == '-'  || (input[0] >= '0' && input[0] <= '9')) {
    if (stringLengthUntilEmptyElement(input) == 1) {
      if (input[0] == '-') return 0;
      else return 1;
    }
    else if (input[0] == '-' && input[1] == '.') return 0;
    else {
      for (int i = 1; i < stringLengthUntilEmptyElement(input); i++) {
        if (input[i] < '0' || input[i] > '9') {
          if (input[i] == '.') {
            pointCounter++;
            if (pointCounter > 1) return 0;
          }
          else return 0;
        }
      }
      return 1;

    }
  }
  else return 0;
  return 1;
}

double stringToDouble(char input[]) {
  int numbers[100];
  double number = 0, minusCounter = 0, pointCounter = 0, pointId;
  int length = stringLengthUntilEmptyElement(input);

  if (input[0] == '-') {
    minusCounter++;
    for (int i = 0; i < length; i++) {
      input[i] = input[i + 1];
    }
    length--;
  }

  for (int i = 0; i < length; i++) {
    if (input[i] == '.') {
      pointCounter++;
      pointId = i;
    }
  }

  if (pointCounter == 0) {
    input[length] == '.';
    pointId = length;
    length++;
  }
  for (int i = 0; i < length; i++) {
    if (i == pointId) continue;
    else numbers[i] = (int)input[i] - 48;
  }

  for (int i = 0; i < pointId; i++) {
    number += numbers[i] * power(10, pointId - i - 1);
  }
  for (int i = pointId + 1; i < length; i++) {
    number += numbers[i] * power(0.1, i - pointId);
  }

  if (minusCounter == 1) return -number;
  else if (minusCounter == 0) return number;
}

int stringLengthUntilEmptyElement(char string[]) {
  int length = 0;
  for (int i = 0; i < 100; i++) {
    if (string[i] == 0) break;
    length++;
  }

  return length;
}

double power(double a, int b) {
  double temp = a;
  if (b == 0) {
    return 1;
  }
  while (b > 1) {
    a *= temp;
    b--;
  }
  return a;
}
