//https://www.acwing.com/problem/content/4499/

// dp 做法
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 2010, Mod = 998244353;

int n, m, k;
//dp[i][j] 表示在前 i 个小朋友中，有 j 个小朋友和其左侧的小朋友吃的水果不同的方案数
int dp[N][N];

int main ()
{
    cin >> n >> m >> k;
    
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) dp[i][0] = m;
    
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= min(i, k); j++)
            dp[i][j] = ((ll)dp[i - 1][j - 1] * (m - 1) % Mod + dp[i - 1][j]) % Mod;
        
    cout << dp[n][k] << endl;
    
    return 0;
}

//组合数
//https://www.acwing.com/solution/content/126205/

#include <iostream>

using namespace std;

typedef long long ll;

const int N = 2010, Mod = 998244353;

int n, m, k;
int fact[N], infact[N];

int qmi (int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = (ll)res * a % Mod;
        a = (ll)a * a % Mod;
        b >>= 1;
    }
    return res;
}

void init ()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N - 10; i++)
    {
        fact[i] = (ll)fact[i - 1] * i % Mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, Mod - 2) % Mod;
    }
}

int main ()
{
    cin >> n >> m >> k;
    
    init();
    
    cout << (ll)fact[n - 1] * infact[n - 1 - k] % Mod * infact[k] % Mod * (ll)m % Mod * qmi(m - 1, k) % Mod << endl; 
    
    return 0;
}