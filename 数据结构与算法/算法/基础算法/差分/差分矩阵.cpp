//https://www.acwing.com/problem/content/800/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <bitset>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
using namespace std;

const int N = 100010;

int n, m, q, x[N][N], k[N][N];

int main ()
{   
    cin >> n >> m >> q;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ ) 
        {
            cin >> x[i][j]; 
            k[i][j] = x[i][j] - x[i][j-1];
        }

    while ( q-- )
    {
        int l1, r1, l2, r2, c;
        cin >> l1 >> r1 >> l2 >> r2 >> c;
        for ( int i = l1; i <= l2; i++ ) k[i][r1] += c, k[i][r2+1] -= c;
    }

    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= m; j++ )
        {
            x[i][j] = k[i][j] + x[i][j-1];
            cout << x[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}