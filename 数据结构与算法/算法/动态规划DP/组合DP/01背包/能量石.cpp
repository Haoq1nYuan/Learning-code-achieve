// https://www.acwing.com/problem/content/description/736/

// 贪心+01背包DP
/*
本题的朴素解法为dfs遍历所有的吃能量石的方案，其中最优解只对应着一种能量石的排列方案。
对于这种方案，相邻的任意两个能量石在交换顺序后必然会使总体能量减少或者不变。
对于相邻的任意两个能量石a1、a2，交换前后它们提供的能量总值为：
E1：e1 - l1 * j + e2 - l2 * (j + s1)
E2：e2 - l2 * j + e1 - l1 * (j + s2)
由于题意要求E1 <= E2，因此化简得：
l1 * s2 >= l2 * s1
只需要按照上式对所有能量石进行排序即可。
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105, M = 10005;

struct stone
{
    int s, e, l;
    
    bool operator< (const stone &p)const
    {
        return p.s * l >= s * p.l;
    }
} S[N];

int t, n, sum;
int f[N][M];

int main ()
{
    cin >> t;
    
    for (int k = 1; k <= t; k++)
    {
        sum = 0;
        memset(f, 0, sizeof f);
        
        cin >> n;
        
        for (int i = 1; i <= n; i++) 
        {
            cin >> S[i].s >> S[i].e >> S[i].l;
            sum += S[i].s;
        }
        
        sort(S + 1, S + 1 + n);    
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= sum; j++)
            {
                f[i][j] = f[i - 1][j];
                
                if (j >= S[i].s) 
                    f[i][j] = max(f[i][j], f[i - 1][j - S[i].s] + max(S[i].e - S[i].l * (j - S[i].s), 0));
            }

        int ans = 0;
        for (int j = 1; j <= sum; j++) ans = max(ans, f[n][j]);
        
        cout << "Case #" << k << ": " << ans << endl;
    }
    
    return 0;
}