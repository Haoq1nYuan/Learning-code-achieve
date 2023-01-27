//https://www.acwing.com/problem/content/156/

//双指针暴力
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 100010;

int n, k, a[N];
int maxn[N], minn[N];

int main ()
{
    cin >> n >> k;
    for ( int i = 0; i < n; i++ ) cin >> a[i];

    memset(minn, 0x3f, sizeof(minn));
    
    memset(maxn, -0x3f, sizeof(maxn));

    for ( int i = 0; i + k <= n; i++ )
    {
        for ( int l = i, r = l + k - 1; r >= l; l++, r-- )
        {
            maxn[i] = max( max( maxn[i], a[l] ), a[r] );
            minn[i] = min( min( minn[i], a[l] ), a[r] );
        }
    }

    for ( int i = 0; i + k <= n; i++ ) cout << minn[i] << ' ';
    cout << endl;
    for ( int i = 0; i + k <= n; i++ ) cout << maxn[i] << ' ';
    cout << endl;

    return 0;
}

//单调队列优化
#include <iostream>
using namespace std;

int q[N], h, t;
int maxn[N], minn[N];
int n, k, x;

int main ()
{
    cin >> n >> k;
    
    memset(minn, 0x3f, sizeof(minn));
    memset(maxn, -0x3f, sizeof(maxn));

    for ( int i = 0; i < n; i++ )
    {
        if ( i < 3 ) 
        {
            cin >> q[++t];
            maxn[2] = max( maxn[2], q[t] );
            minn[2] = min( minn[2], q[t] );
            continue;
        }

        cin >> x;
        h--, q[++t] = x;

        if ( x > maxn[i-1] && ) maxn[i] = x;
        else if ( x < )
    }


    return 0;
}