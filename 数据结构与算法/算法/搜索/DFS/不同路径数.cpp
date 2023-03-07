//https://www.acwing.com/problem/content/3505/

#include <iostream>
#include <cstdio>
#include <unordered_set>

using namespace std;

int n, m, k;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int s[6][6];
int ans, res;
unordered_set<int> p;

void dfs (int u, int a, int b)
{
    if (u == k + 1)
    {
        if (!p.count(res)) 
        {
            ans++;
            p.insert(res);
        }
        
        return;
    }
    
    int tem = res;
    for (int i = 0; i < 4; i++)
    {
        int x = a + dx[i], y = b + dy[i];
        
        if (x >= 1 && x <= n && y >= 1 && y <= m)
        {
            res = res * 10 + s[x][y];
            dfs(u + 1, x, y);
            res = tem;
        }
    }
}

int main ()
{
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++)    
        for (int j = 1; j <= m; j++) cin >> s[i][j];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) dfs(0, i, j);
    
    cout << ans << endl;
    
    return 0;
}