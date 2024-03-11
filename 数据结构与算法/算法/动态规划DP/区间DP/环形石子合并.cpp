// https://www.acwing.com/problem/content/1070/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 205;

int n, w[2 * N];
int f[2 * N][2 * N], ans;

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        w[i] += w[i - 1];
    }
    
    for (int i = 1 + n; i <= n * 2; i++) w[i] = w[i - n] + w[n];
    
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i <= 2 * n; i++) f[i][i] = 0;
    
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= 2 * n; i++)
        {
            int j = i + len - 1;
            
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + w[j] - w[i - 1]);
        }
    
    ans = f[1][n];
    for (int i = 2; i <= n; i++) ans = min(ans, f[i][i + n - 1]);
    
    cout << ans << endl;
    
    memset(f, 0, sizeof f);
    
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= 2 * n; i++)
        {
            int j = i + len - 1;
            
            for (int k = i; k < j; k++)
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + w[j] - w[i - 1]);
        }
        
    ans = f[1][n];
    for (int i = 2; i <= n; i++) ans = max(ans, f[i][i + n - 1]);
    
    cout << ans << endl;
    
    return 0;
}