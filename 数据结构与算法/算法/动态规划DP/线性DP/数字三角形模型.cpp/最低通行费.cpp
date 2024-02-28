// https://www.acwing.com/problem/content/1020/
#include <iostream>

const int N = 105;

using namespace std;

int n, g[N][N], dp[N][N];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1) dp[1][1] = g[1][1];
            else if (i == 1) dp[i][j] = g[i][j] + dp[i][j - 1];
            else if (j == 1) dp[i][j] = g[i][j] + dp[i - 1][j];
            else dp[i][j] = g[i][j] + min(dp[i - 1][j], dp[i][j - 1]); 
        }
    
    cout << dp[n][n] << endl;
    
    return 0;
}