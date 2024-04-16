// https://www.acwing.com/problem/content/1100/

// 朴素写法：11/11
#include <iostream>
#include <queue>
#include <unordered_map> 

using namespace std;

typedef pair<int, int> PII;

const int N = 55;

int n, m, g[2 * N][2 * N];
int cnt, msize;
bool st[2 * N][2 * N];
int dx[] = {0, 0, 2, 0, -2}, dy[] = {0, 2, 0, -2, 0};
unordered_map<int, string> state;

void init ()
{
    state[1] = "w";
    state[2] = "n";
    state[3] = "wn";
    state[4] = "e";
    state[5] = "we";
    state[6] = "ne";
    state[7] = "wne";
    state[8] = "s";
    state[9] = "ws";
    state[10] = "ns";
    state[11] = "wns";
    state[12] = "es";
    state[13] = "wes";
    state[14] = "nes";
    state[15] = "wnes";
}

void bfs (int x, int y)
{
    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;
    
    int size = 1;
    
    while (q.size())
    {
        auto p = q.front();
        int a = p.first, b = p.second;
        q.pop();
        
        for (int k = 1; k <= 4; k++)
        {
            int nx = a + dx[k], ny = b + dy[k];
        
            if (nx <= 1 || nx >= 2 * n + 1 || ny <= 1 || ny >= 2 * m + 1) continue;
            if (st[nx][ny]) continue;
            if (g[a + dx[k] / 2][b + dy[k] / 2]) continue;
            
            if (!g[nx][ny])
            {
                size++;
                q.push({nx, ny});
                st[nx][ny] = true;
            }
        }
    }
    
    msize = max(msize, size);
}

int main ()
{
    init();
    
    cin >> n >> m;
    for (int i = 2; i <= n * 2; i += 2)
        for (int j = 2; j <= m * 2; j += 2)
        {
            int x;
            cin >> x;
            
            for (char ch : state[x])
            {
                if (ch == 'w') g[i][j - 1] = g[i + 1][j - 1] = g[i - 1][j - 1] = 1;
                if (ch == 'n') g[i - 1][j] = g[i - 1][j - 1] = g[i - 1][j + 1] = 1;
                if (ch == 'e') g[i][j + 1] = g[i - 1][j + 1] = g[i + 1][j + 1] = 1;
                if (ch == 's') g[i + 1][j] = g[i + 1][j - 1] = g[i + 1][j + 1] = 1;
            }
        }
        
    for (int i = 2; i <= n * 2; i += 2)    
        for (int j = 2; j <= m * 2; j += 2)
            if (!st[i][j] && !g[i][j])
            {
                bfs(i, j);
                cnt ++;
            }
            
    cout << cnt << endl << msize << endl;
    
    return 0;
}

// 优化写法：使用位运算符判断墙壁
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 55;

int n, m, g[N][N], cnt, msize;
bool st[N][N];
int dx[] = {0, 1, 0, -1, 0}, dy[] = {0, 0, 1, 0, -1};

void bfs (int x, int y)
{
    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;
    
    int size = 1;
    
    while (q.size())
    {
        auto p = q.front();
        int a = p.first, b = p.second;
        q.pop();
        
        for (int k = 1; k <= 4; k++)
        {
            int nx = a + dx[k], ny = b + dy[k];
            
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (st[nx][ny]) continue;
        
            if (dx[k] == 1 && dy[k] == 0 && (g[a][b] >> 3) & 1) continue;
            if (dx[k] == 0 && dy[k] == 1 && (g[a][b] >> 2) & 1) continue;
            if (dx[k] == -1 && dy[k] == 0 && (g[a][b] >> 1) & 1) continue;
            if (dx[k] == 0 && dy[k] == -1 && g[a][b] & 1) continue;
            
            q.push({nx, ny});
            st[nx][ny] = true;
            size ++;
        }
    }
    
    msize = max(msize, size);
}

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
            
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!st[i][j])
            {
                bfs(i, j);
                cnt ++;
            }
            
    cout << cnt << endl << msize << endl;
    
    return 0;
}

// 再次精简
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 55;

int n, m, g[N][N], cnt, msize;
bool st[N][N];
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

void bfs (int x, int y)
{
    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;
    
    int size = 1;
    
    while (q.size())
    {
        auto p = q.front();
        int a = p.first, b = p.second;
        q.pop();
        
        for (int k = 0; k < 4; k++)
        {
            int nx = a + dx[k], ny = b + dy[k];
            
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (st[nx][ny]) continue;
            if ((g[a][b] >> k) & 1) continue;
            
            q.push({nx, ny});
            st[nx][ny] = true;
            size ++;
        }
    }
    
    msize = max(msize, size);
}

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
            
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!st[i][j])
            {
                bfs(i, j);
                cnt ++;
            }
            
    cout << cnt << endl << msize << endl;
    
    return 0;
}