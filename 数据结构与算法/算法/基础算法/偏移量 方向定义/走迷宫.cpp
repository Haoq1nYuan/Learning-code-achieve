//https://www.acwing.com/problem/content/846/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110;

int n, m;
int a[N][N], d[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

queue<pair<int, int>> k;

int bfs ()
{
    memset(d, -1, sizeof(d));
    d[1][1] = 0;
    
    k.push({1, 1});
    
    while (k.size())
    {
        auto t = k.front();
        k.pop();
        
        for ( int i = 0; i < 4; i++ )
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            
            if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                k.push({x, y});
            }
        }
    }
    
    return d[n][m];
}

int main ()
{
    cin >> n >> m;
    for ( int i = 1;i <= n; i++ )
        for ( int j = 1; j <= m; j++ ) cin >> a[i][j];
    
    cout << bfs();
    
    return 0;
}