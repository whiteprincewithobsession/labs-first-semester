int main() {
    long double W, H, x1, y1, x2, y2, w, h, x11, x22, y11, y22, dist;
    std:: cin >> W >> H;
    std:: cin >> x1 >> x2 >> y1 >> y2;
    std:: cin >> w >> h;
    if((H < y2 - y1 || W < x2 - x1) || y2 <= y1 || x2 <= x1)
    {
      std:: cout << "ERROR";
    }
    else if(x2 - x1 + w > W && y2 - y1 + h > H)
    {
      std:: cout  << "-1";
    }
    else if(x2 - x1 + w < W && y2 - y1 + h < H)
    {
        std:: cout << "0";
    }
    else if( x1 < w && y1 < h && (x2 - x1 + w < W || y2 - y1 + h < H )
    {
        if(w - x1 < h - y1)
        {
            std:: cout << w - x1;
        }   
        else if(w - x1 > h - y1)
        {
            std:: cout << h - y1
        }
    }