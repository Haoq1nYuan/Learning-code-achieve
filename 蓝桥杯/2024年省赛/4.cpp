#include <iostream>
#include <map>

using namespace std;

const int N = 10;

int n, K;
int g[N][N], ans[N * N];
bool st[N][N];
bool st2[N * 2][N * 2];

map<pair<int, int>, int> kk;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int dx2[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy2[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool dfs (int x, int y, int state, int cnt)
{
    if (cnt == n * n) return true;
    
    for (int k = 0; k <= 7; k++)
    {
        int a = x + dx2[k], b = y + dy2[k];

        //cout << x << ' ' << y << ' ' << a << ' ' << b << endl;

        if (!st[a][b] && g[a][b] == state && a >= 1 && a <= n && b >= 1 && b <= n && !st2[x + a][y + b])
        {
            ans[cnt] = kk[{dx2[k], dy2[k]}];
            st[a][b] = true;
            st2[x + a][y + b] = true;
            if (dfs(a, b, (state + 1) % K, cnt + 1)) return true;
            st[a][b] = false;
            st2[x + a][y + b] = false;
        }
    }

    return false;
}

int main ()
{
    for (int i = 0; i <= 7; i++) kk[{dx[i], dy[i]}] = i;

    cin >> n >> K;

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) cin >> g[i][j];

    st[1][1] = true;
    if (dfs(1, 1, 1, 1)) for (int i = 1; i < n * n; i++) cout << ans[i];
    else cout << -1;

    return 0;
}