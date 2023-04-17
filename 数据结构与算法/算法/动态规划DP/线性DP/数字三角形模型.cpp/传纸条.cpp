//https://www.acwing.com/problem/content/277/

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 55, M = 105;

int n, m, g[N][N];
int f[M][N][N];

int get (int k, int i, int j)
{
    int ans = max(max(f[k - 1][i][j], f[k - 1][i - 1][j - 1]), max(f[k - 1][i - 1][j], f[k - 1][i][j - 1]));
    return ans;
}

int main ()
{
    cin >> n >> m;
    for (int i = 1;i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &g[i][j]);
    
    for (int k = 2; k <= n + m; k++)
        for (int i = 1; i < k && i <= n; i++)
            for (int j = 1; j < k && j <= n; j++)
            {
                f[k][i][j] = g[i][k - i];
                
                if (i != j) f[k][i][j] += g[j][k - j];
                
                f[k][i][j] += get(k, i, j);
            }
            
    cout << f[n + m][n][n] << endl;
    
    return 0;
}