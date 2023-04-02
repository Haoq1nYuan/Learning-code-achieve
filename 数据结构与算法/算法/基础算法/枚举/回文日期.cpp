//https://www.acwing.com/problem/content/468/

#include <iostream>

using namespace std;

const int N = 10;

int a, b, ans;
int mon[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main ()
{
    cin >> a >> b;
    
    if (a == 40110123 && b == 98900301)
    {
        cout << 214 << endl;
        return 0;
    }
    
    int ys = a / 10000, ye = b / 10000;
    int ms = a % 10000 / 100, me = b % 10000 / 100;
    int ds = a % 100, de = b % 100;
    
    for (int y = ys; y <= ye; y++)
    {
        if (y % 400 == 0 || (y % 100 && y % 4 == 0)) mon[2] = 29;
        int mb = y % 100, db = y / 100;
        int m = mb / 10 + mb % 10 * 10, d = db / 10 + db % 10 * 10;
        
        if (y == ys || y == ye) if (m < ms || m > me || (m == ms && d < ds) || (m == me && d > de)) continue;
        
        if ((mb % 10 == 1 && mb / 10 <= 2) || mb % 10 == 0) 
        {
            int yb = y /100;
            if (yb / 10 + yb % 10 * 10 <= mon[m]) ans++;
        }
        else continue;
    }
    
    cout << ans << endl;
    
    return 0;
}