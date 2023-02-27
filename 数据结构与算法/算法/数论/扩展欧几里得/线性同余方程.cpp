//https://www.acwing.com/problem/content/880/

#include <iostream>

using namespace std;

typedef long long ll;

int exgcd (int a, int m, int &x, int &y)
{
    if (!m)
    {
        x = 1, y = 0;
        return a;
    }
    
    int d = exgcd(m, a % m, y, x);
    y -= a / m * x;
    return d;
}

int main ()
{
    int n;
    scanf("%d", &n);
    
    while (n--)
    {
        int a, m, b;
        scanf("%d%d%d", &a, &b, &m);
        int x, y;
        int d = exgcd(a, m, x, y);
        
        if (b % d) puts("impossible");
        else printf("%d\n", (ll)x * (b / d) % m);
    }
    
    return 0;
}