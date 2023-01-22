#include <iostream>

int main() {
 double x, y, z;
 std:: cin >> x >> y >> z;
  if ( x + y > z && x + z > y && y + z > x)
  {
      std:: cout << "YES";
  }
    else if ( x <= 0 || y <= 0 || z <= 0)
    {
        std:: cout << "ERROR";
    }
    else 
    {
        std:: cout << "NO";
    }
    
    
    // put your code here
    return 0;
}