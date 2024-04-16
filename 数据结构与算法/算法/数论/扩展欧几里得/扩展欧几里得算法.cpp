//https://www.acwing.com/problem/content/879/

#include <iostream>

using namespace std;

void exgcd (int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return;
    }

    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

int main ()
{
    int n;
    scanf("%d", &n);
    
    while (n--)
    {
        int a, b, x, y;
        scanf("%d%d", &a, &b);
        
        exgcd(a, b, x, y);
        
        printf("%d %d\n", x, y);
    }
    
    return 0;
}