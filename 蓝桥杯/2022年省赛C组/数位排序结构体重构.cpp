//https://www.acwing.com/problem/content/4656/

//结构体内嵌重构
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000010;

int n, m, x[N];

struct Rec
{
    int x, y;
    bool operator< (const Rec& k )const
    {
        if ( x != k.x ) return x < k.x;
        else return y < k.y;
    }
}a[N];

int main ()
{
    cin >> n >> m;
    
    for ( int i = 1; i <= n; i++ )
    {
        a[i].y = i;
        int j = i;
        while ( j )
        {
            a[i].x += j % 10;
            j /= 10;
        }
    }
    
    sort(a+1, a+n+1);
    
    cout << a[m].y;
    
    return 0;
}
