// https://www.acwing.com/problem/content/1118/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 30;

int t, n, m, x, y, cnt, ans;
bool st[N][N];
int dx[] = {0, 1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};

void dfs (int x, int y)
{
    if (cnt == n * m) 
    {
        ans ++;
        return;
    }
    
    for (int k = 1; k <= 8; k ++)
    {
        int a = x + dx[k], b = y + dy[k];
        
        if (a <= 0 || a > n || b <= 0 || b > m) continue;
        if (st[a][b]) continue;
        
        st[a][b] = true;
        cnt++;
        dfs(a, b);
        st[a][b] = false;
        cnt--;
    }
}

int main ()
{
    cin >> t;
    
    while (t--)
    {
        cin >> n >> m >> x >> y;
        x++, y++;
        
        memset(st, 0, sizeof st);
        st[x][y] = true;
        cnt = 1, ans = 0;
        
        dfs(x, y);
        
        cout << ans << endl;
    }
    
    return 0;
}