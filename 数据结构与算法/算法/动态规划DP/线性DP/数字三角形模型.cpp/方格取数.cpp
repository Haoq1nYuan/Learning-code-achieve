//https://www.acwing.com/problem/content/1029/
// 朴素解法
#include <iostream>

using namespace std;

int n, r, c, x, g[15][15], dp[15][15][15][15]; 
// dp[x1][y1][x2][y2] 表示从(0, 0)到(x1, y1)和(x2, y2)的两条路径中，数字和最大的那条

int main()
{
    cin >> n;
    
    while (cin >> r >> c >> x, r || c || x) g[r][c] = x;
    
    for (int i1 = 1; i1 <= n; i1++)
        for (int j1 = 1; j1 <= n; j1++)
            for (int i2 = 1; i2 <= n; i2++)
                for (int j2 = 1; j2 <= n; j2++)
                {
                    dp[i1][j1][i2][j2] = max(max(dp[i1 - 1][j1][i2 - 1][j2], dp[i1 - 1][j1][i2][j2 - 1]), 
                                             max(dp[i1][j1 - 1][i2 - 1][j2], dp[i1][j1 - 1][i2][j2 - 1]));
                                             
                    if (i1 == i2 && j1 == j2) dp[i1][j1][i2][j2] += g[i1][j1];
                    else dp[i1][j1][i2][j2] += g[i2][j2] + g[i1][j1];
                }
                
    cout << dp[n][n][n][n] << endl;
    
    return 0;
}

//本题可以看作两条线路同时进行，因为取完变为0就相当于不再经过这一个位置
#include <iostream>

using namespace std;

//注意：这里讲数组长度开大一倍，因为 f 数组的第一维是两倍长度
const int N = 25;

int n, x, y, c, g[N][N];
int f[N][N][N];
//状态表示：f[k][i][j]表示经过k步，a走到(i, k - i)处，b走到(j, k - j)处
//状态转移：如果下标不越界，那么直接从i - 1， i， j - 1, j四个方向上取最大值

int get (int k, int i, int j)
{
    int ans = max(max(f[k - 1][i - 1][j], f[k - 1][i - 1][j - 1]), max(f[k - 1][i][j], f[k - 1][i][j - 1]));
    return ans;
}

int main ()
{
    cin >> n;
    
    while (cin >> x >> y >> c, x || y || c) g[x][y] = c;
    
    for (int k = 2; k <= n * 2; k++)
        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= k; j++)
            {  
                f[k][i][j] = get(k, i, j) + g[i][k - i];
                if (i != j) f[k][i][j] += g[j][k - j];
            }
            
    cout << f[n * 2][n][n] << endl;
            
    return 0;
}