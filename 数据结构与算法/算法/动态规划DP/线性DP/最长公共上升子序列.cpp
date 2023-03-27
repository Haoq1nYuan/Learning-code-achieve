//https://www.acwing.com/problem/content/274/

/*
状态表示：dp[i][j] 表示在序列 a 中前 n 个元素和序列 b 中前 j 个元素中的公共上升子序列，属性是最大长度
状态转移：
1.不选 a[i]：dp[i][j] = dp[i - 1][j]
2.选 a[i] 和 b[j]：dp[i][j] = max(dp[i][j], 当前 i 循环中 dp 的最大值);
3.
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3010;

int n, m, a[N], b[N];
int dp[N][N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    
    for (int i = 1; i <= n; i++)
    {
        int maxn = 1;
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            
            if (a[i] == b[j]) dp[i][j] = max(dp[i][j], maxn);
            
            if (a[i] > b[j]) maxn = max(maxn, dp[i - 1][j] + 1);
        }
    }
        
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dp[n][i]);
        
    cout << res << endl;
    
    return 0;
}