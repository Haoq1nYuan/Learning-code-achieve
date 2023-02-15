//https://www.acwing.com/problem/content/844/

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
typedef long long ll;
typedef unsigned long long ull;

int n, ans[10], d[10], k;

void dfs ( int num )
{
    if ( num == n ) 
    {
        for ( int i = 1; i <= k; i++ ) cout << ans[i] << ' ';
        cout << endl;
        return;
    }

    for ( int i = 1; i <= n; i++ )
    {
        if ( d[i] == 0 )
        {
            d[i] = 1;
            ans[++k] = i;
            dfs(num+1);
            d[i] = 0;
            k--;
        }
        else continue;
    }
}

int main ()
{
    cin >> n;

    dfs(0);

    return 0;
}