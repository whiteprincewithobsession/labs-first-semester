#include <iostream>

int main() {
    long double W, H, x1, y1, x2, y2, w, h, r;
    std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    if(x1 <= 01 || y1 <= 0 || x2 <= 0 || y2 <= 0 || w <= 0 || h <= 0 || W <= 0|| H <= 0) {
        std:: cout << "ERROR" << '\n';
        return 0;
    }
    bool point1, point2;
    point1 = w + (x2 - x1) <= W;
    point2 = h + (y2 - y1) <= H;
    if(x1 >= w && y1 >= h  || (x1 == w  && y1 == h)) {
        std::cout << 0 << '\n';
        return 0;
    }
    if(point1 && point2) {
       if(w - x1 <= h - y1)
       {
        std:: cout << w - x1;
       }
       else if (h - y1 <= w - x1)
       {
        std:: cout << h - y1;
       }
        return 0;
    }
    else if(point1 && !point2) {
        r = w - x1;
        std::cout << r << '\n';
        return 0;
    }
    else if(point2 && !point1) {
        r = h - y1;
        std::cout << r << '\n';
        return 0;
    }
    else std::cout << -1 << '\n';
    return 0;
}