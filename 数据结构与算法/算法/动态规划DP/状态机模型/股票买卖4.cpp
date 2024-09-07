// https://www.acwing.com/problem/content/description/1059/

// 规定j维：一次买入卖出后+1
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100005, K = 105;

int n, w, k;
int f[N][K][2];

int main ()
{
    cin >> n >> k;
    
    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= n; i++) f[i][0][0] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> w;
        
        f[i][0][1] = f[i - 1][0][0] - w;  // 初次买入的特殊情况
        
        for (int j = 1; j <= k; j++)
        {
            f[i][j][0] = max(f[i - 1][j][1] + w, f[i - 1][j][0]);
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= k; i++) ans = max(ans, f[n][i][0]);
    
    cout << ans << endl;
    
    return 0;
}

// 规定j维：一次买入后就+1
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100005, K = 105;

int n, w, k;
int f[N][K][2];

int main ()
{
    cin >> n >> k;
    
    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= n; i++) f[i][0][0] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> w;
        
        for (int j = 1; j <= k; j++)
        {
            f[i][j][0] = max(f[i - 1][j][1] + w, f[i - 1][j][0]);
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= k; i++) ans = max(ans, f[n][i][0]);
    
    cout << ans << endl;
    
    return 0;
}