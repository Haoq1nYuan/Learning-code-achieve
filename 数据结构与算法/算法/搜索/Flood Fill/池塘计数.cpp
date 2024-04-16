// https://www.acwing.com/problem/content/description/1099/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1005;

typedef pair<int, int> PII;

int n, m, cnt;
char g[N][N];
bool st[N][N];
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

void bfs (int x, int y)
{
    queue<PII> q;   
    q.push({x, y});
    st[x][y] = true;

    while (q.size())
    {
        auto p = q.front();
        int a = p.first, b = p.second;
        q.pop();
        
        for (int i = 1; i <= 8; i++)
        {
            int nx = a + dx[i], ny = b + dy[i];
            
            if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if (st[nx][ny]) continue;
            
            if (g[nx][ny] == 'W')
            {
                q.push({nx, ny});
                st[nx][ny] = true;
            }
        }
    }
}

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            cin >> g[i][j];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!st[i][j] && g[i][j] == 'W')
            {
                bfs(i, j);
                cnt ++;
            }
    
    cout << cnt << endl;
    
    return 0;
}