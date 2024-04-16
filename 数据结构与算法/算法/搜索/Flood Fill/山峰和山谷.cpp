// https://www.acwing.com/problem/content/1108/

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1005;

int n, g[N][N], up, down;
int dx[] = {0, -1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {0, -1, 0, 1, -1, 1, -1, 0, 1};
bool st[N][N];

void bfs (int x, int y, bool &is_up, bool &is_down)
{
    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;
    
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        int a = p.first, b = p.second;
        
        for (int k = 1; k <= 8; k++)
        {
            int nx = a + dx[k], ny = b + dy[k];
            
            if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
            //if (st[nx][ny]) continue;  这里判断不能写，否则会跳过很多边界判断（比如某个点左右各有山峰或山谷，当左侧的山峰或山谷遍历后该点就不会被遍历了）
            
            if (g[a][b] != g[nx][ny])   // 先判断是否为边界，边界就算被遍历过也要考虑
            { 
                if (g[a][b] > g[nx][ny]) is_up = true;  // 这里如果是山峰，并且之后所有边界判断都是山峰，那么is_down必为false，否则这个连通块就什么都不是
                else is_down = true;
            }
            else if (!st[nx][ny])
            {
                st[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!st[i][j])
            {
                bool is_up = false, is_down = false;
                bfs(i, j, is_up, is_down);
                
                if (is_up && !is_down) up ++;
                if (is_down && !is_up) down ++;
                if (!is_up && !is_down) up++, down++;
            }
            
    cout << up << ' ' << down << endl;
    
    return 0;
}