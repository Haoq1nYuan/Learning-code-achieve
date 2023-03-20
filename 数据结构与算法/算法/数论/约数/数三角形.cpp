//https://www.acwing.com/problem/content/description/1312/

//底为 i , 高为 j 的三角形斜边上除端点的点个数是：gcd(i, j) - 1;
/*
证明：https://www.acwing.com/solution/content/22893/
*/

#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1010;

int m, n;

int gcd (int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main ()
{
    cin >> m >> n;    
    
    m++, n++;
    //三个点的所有选法
    ll all = (ll)n * m * (n * m - 1) * (n * m - 2) / 6;
    //三个点同在横线上
    ll r = (ll)n * m * (m - 1) * (m - 2) / 6;
    //三个点同在竖线上
    ll l = (ll)m * n * (n - 1) * (n - 2) / 6;
    
    m--, n--;
    ll x = 0;
    // i 和 j 表示枚举的直角三角形的两条直角边，且将直角顶点看作原点
    //这样就可以直接用 gcd(i, j) 了
    //对于每一种直角三角形，直角顶点的选取方式有 (n - i + 1) * (m - j + 1) 种 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            ll t = gcd(i, j) - 1;
            x += (ll)t * (n - i + 1) * (m - j + 1);
        }
        
    //因为上面斜边情况之枚举了斜率为正的情况，而斜率为负的情况和斜率为正的情况 x 相同
    cout << all - l - r - 2 * x << endl;
    
    return 0;
}