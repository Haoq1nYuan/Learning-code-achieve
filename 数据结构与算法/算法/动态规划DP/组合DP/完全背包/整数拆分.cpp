//https://www.acwing.com/problem/content/description/3385/

//朴素写法，爆内存
#include <iostream>

using namespace std;

const int N = 10010, Mod = 1e9;

int n;
int w[21], dp[N][N];

void init ()
{
    w[1] = 1;
    for (int i = 2; i < 21; i++) w[i] = 2 * w[i - 1];
}

int main ()
{
    cin >> n;
    init();
    
    dp[0][0] = 1;
    for (int i = 1; i <= 20; i++)
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) dp[i][j] = (dp[i][j] + dp[i][j - w[i]]) % Mod;
        }
        
    cout << dp[20][n];
    
    return 0;
}

//转一维优化
#include <iostream>

using namespace std;

const int N = 1000010, Mod = 1e9;

int n;
int dp[N];

int main ()
{
    cin >> n;
    
    dp[0] = 1;
    for (int i = 1; i <= n; i *= 2)
        for (int j = i; j <= n; j++)
            dp[j] = (dp[j] + dp[j - i]) % Mod;
        
    cout << dp[n] << endl;
    
    return 0;
}
