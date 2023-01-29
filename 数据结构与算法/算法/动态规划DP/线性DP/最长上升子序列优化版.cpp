//https://www.acwing.com/problem/content/898/

//贪心优化
//对于dp[j],存储j前面每种长度的最长上升子序列的末尾最小的值，
//并将这些值按照子序列长度由小到大存放在单调递增栈中
//因为结尾越小，后面添加元素时的范围就更大。
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

int le[N];
int n, x[N], len;

int main ()
{
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> x[i];

    for ( int i = 1; i <= n; i++ )
    {
        int l = 0, r = len;
        while ( l < r )
        {
            int mid = ( l + r + 1 ) / 2;
            if ( le[mid] < x[i] ) l = mid;
            else r = mid - 1;
        }

        len = max( len, r+1 );
        le[r+1] = x[i];
    } 

    cout << len;

    return 0;
}