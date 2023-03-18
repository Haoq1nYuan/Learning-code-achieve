#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int n, m;
int g[N][N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int dis[N][N];
int ans;

int dfs (int i, int j)
{
    if (dis[i][j]) return dis[i][j];

    dis[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k], y = j + dy[k];

        if (x < 1 || x > n || y < 1 || y > m) continue;

        if (g[i][j] > g[x][y]) dis[i][j] = max(dis[i][j], dfs(x, y) + 1);
    }

    return dis[i][j];
}

int main ()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, dfs(i, j));

    cout << ans << endl;

    return 0;
}