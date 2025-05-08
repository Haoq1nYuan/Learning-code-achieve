//https://www.acwing.com/problem/content/843/

#include <iostream>

using namespace std;

const int N = 100010, P = 131;
typedef unsigned long long ull;

int n, m;
string str;
//p数组存储对应前缀长度p的次幂，前缀长度为1则P为1次幂
ull h[N], p[N];
int x, y, a, b;

int main ()
{
    cin >> n >> m >> str;

    str = ' ' + str;

    p[0] = 1;

    for ( int i = 1; i <= n; i++ )
    {
        p[i] = p[i-1] * P;  
        h[i] = h[i-1] * P + str[i]; //直接用ASCII码值表示p进制数
    }

    while ( m-- )
    {
        cin >> x >> y >> a >> b;
        ull ans = h[y] - h[x-1] * p[y-x+1];
        ull res = h[b] - h[a-1] * p[b-a+1];
        if ( ans == res ) puts("Yes");
        else puts("No");
    }

    return 0;
}