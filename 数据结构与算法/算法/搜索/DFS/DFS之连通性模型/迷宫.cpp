// https://www.acwing.com/problem/content/1114/

// 朴素写法：2/10
#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;

int t, n, ax, ay, bx, by;
char g[N][N];
int dx[] = {0, 1, 0, -1, 0}, dy[] = {0, 0, 1, 0, -1};
bool flag, st[N][N];

void dfs (int x, int y)
{
    if (flag) return;
    
    if (x == bx && y == by && !flag) 
    {
        cout << "YES" << endl;
        flag = true;
        return;
    }
    
    for (int k = 1; k <= 4; k++)
    {
        int xn = x + dx[k], yn = y + dy[k];
        
        if (xn >= 1 && xn <= n && yn >= 1 && yn <= n && g[xn][yn] == '.' && !st[xn][yn])
        {
            st[xn][yn] = true;
            dfs(xn, yn);
            st[xn][yn] = false;
        }
    }
}

int main ()
{
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        
        flag = false;
        memset(st, 0, sizeof st);
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> g[i][j];
        
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ax = a + 1, ay = b + 1, bx = c + 1, by = d + 1;
        
        if (g[ax][ay] == '#' || g[bx][by] == '#') cout << "NO" << endl;
        else if (ax == bx && ay == by) cout << "YES" << endl;
        else 
        {
            dfs(ax, ay);
            
            if (!flag) cout << "NO" << endl;
        }
    }
    
    return 0;
}

// 优化：由于本题仅要求得出从起点能否走到终点，对路径长度没有要求，
// 因此我们只需要求出第一条满足条件的路径即可，之后的深搜操作都可以省略，即图中每个点只会被遍历一次。
// 求连通块的大小，不需要回溯
#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;

int t, n, ax, ay, bx, by;
char g[N][N];
int dx[] = {0, 1, 0, -1, 0}, dy[] = {0, 0, 1, 0, -1};
bool st[N][N];

bool dfs (int x, int y)
{
    if (x == bx && y == by) return true;
    
    for (int k = 1; k <= 4; k++)
    {
        int xn = x + dx[k], yn = y + dy[k];
        
        if (xn <= 0 || xn > n || yn <= 0 || yn > n || st[xn][yn] || g[xn][yn] == '#') continue;
        
        st[xn][yn] = true;    // 一旦该点满足条件，就确定下来必走该点，由于每个点只会被遍历一次，因此无需恢复现场。
        if (dfs(xn, yn)) return true;   // 只要当前路径能走通，直接一路回溯。
    }
    
    return false;
}

int main ()
{
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        
        memset(st, 0, sizeof st);
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> g[i][j];
        
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ax = a + 1, ay = b + 1, bx = c + 1, by = d + 1;
        
        if (g[ax][ay] == '#' || g[bx][by] == '#') cout << "NO" << endl;
        else if (ax == bx && ay == by) cout << "YES" << endl;
        else if (dfs(ax, ay)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}