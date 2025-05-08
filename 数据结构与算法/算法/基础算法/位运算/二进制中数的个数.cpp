//https://www.acwing.com/problem/content/803/

//容器
#include <iostream>
#include <bitset>
using namespace std;
const int N = 100010;

int n, x[N], ans[N];
bitset<10000> a;

int main ()
{
    cin >> n;
    for ( int i = 1; i <= n; i++ ) 
    {
        cin >> x[i];
        a = x[i];
        ans[i] += a.count();
    }
    
    for ( int i = 1; i <= n; i++ ) cout << ans[i] << ' ';

    return 0;    
}

//位运算
#include <iostream>
using namespace std;
const int N = 100010;

int n, x[N], ans[N];

int main ()
{
    cin >> n;
    for ( int i = 1; i <= n; i++ ) 
    {
        cin >> x[i];
        for ( int j = 0; j <= 30; j++ )
            ans[i] += x[i] >> j & 1;
    }
    
    for ( int i = 1; i <= n; i++ ) cout << ans[i] << ' ';

    return 0;    
}
