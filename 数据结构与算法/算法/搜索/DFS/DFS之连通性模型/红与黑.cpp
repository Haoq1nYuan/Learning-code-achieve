// https://www.acwing.com/problem/content/1115/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 25;

int r, c, xs, ys;
int dx[] = {0, 0, 1, 0, -1}, dy[] = {0, 1, 0, -1, 0};
bool st[N][N];
char g[N][N];

int dfs (int x, int y)
{
    int cnt = 1;
    
    for (int k = 1; k <= 4; k ++)
    {
        int a = x + dx[k], b = y + dy[k];
        
        if (a <= 0 || a > r || b <= 0 || b > c || st[a][b] || g[a][b] != '.') continue;

        st[a][b] = true;
        
        cnt += dfs(a, b);
    }
    
    return cnt;
}

int main ()
{
    while (cin >> c >> r, c || r)
    {
        memset(st, 0, sizeof st);
        
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
            {
                cin >> g[i][j];
                
                if (g[i][j] == '@') xs = i, ys = j;
            }
        
        st[xs][ys] = true;

        cout << dfs(xs, ys) << endl;
    }
    
    return 0;
}