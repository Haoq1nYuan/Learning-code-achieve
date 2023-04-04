//https://www.acwing.com/problem/content/description/4411/

#include <iostream>

using namespace std;

typedef long long ll;

const int N = 110, Mod = 1000000007;

int n, m;
//状态表示：
//f[i][j][k]表示遇到i次店，j次花且此时有酒k斗的所有方案数
//状态转移：
//1.当前遇到的是店：dp[i][j][k] = dp[i - 1][j][k / 2];
//2.当前遇到的是花：dp[i][j][k] = dp[i][j - 1][k + 1];
//结合起来看就是dp[i][j][k] = ap[i - 1][j][k / 2] + dp[i][j - 1][k + 1];
ll dp[N][N][N];

int main ()
{
    cin >> n >> m;
    
    //状态出口
    dp[0][0][2] = 1;
    //注意，有的时候状态出口可能会比较多，此时下面的循环可以从0开始，
    //而对于数组越界只需要在转移之前加个判断
    
    //状态转移
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= m; k++)
            {
                if (j) dp[i][j][k] = dp[i][j - 1][k + 1];
                if (k % 2 == 0 && i) dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k / 2]) % Mod;
            }
    
    //满足题意的倒数第二次一定是 dp[n][m][1]
    cout << dp[n][m - 1][1] << endl;
    
    return 0;
}