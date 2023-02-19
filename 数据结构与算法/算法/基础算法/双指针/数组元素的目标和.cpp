//https://www.acwing.com/problem/content/802/

#include <iostream>
using namespace std;
const int N = 100010;

int n, m, x, La, Lb;
int a[N], b[N];

int main ()
{
    cin >> n >> m >> x;
    
    for ( int i = 1; i <= n; i++ ) scanf( "%d", &a[i] );
    for ( int i = 1; i <= m; i++ ) scanf( "%d", &b[i] );
    
    for ( int i = 1, j = m; i <= n; i++ )
    {
        //题目规定必有一个解,所以当第一轮 i = 1 时
        //j不可能减到1时还不能满足 a[i] + b[j] <= x 
        //因为 a[1] + b[1] 的和是最小的,必定小于或等于x 
        //所以无需加上 j > 0 的条件判断
        while ( a[i] + b[j] > x ) j--;
        
        if ( a[i] + b[j] == x ) 
        {
            cout << i - 1 << ' ' << j - 1;
            return 0;
        }
    }
}