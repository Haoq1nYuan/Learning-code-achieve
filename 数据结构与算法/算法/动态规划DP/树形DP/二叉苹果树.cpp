// https://www.acwing.com/problem/content/1076/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;

int n, m, h[N], e[2 * N], w[2 * N], ne[2 * N], idx;
int f[N][N];   // 从根节点i出发且长度为j的路径集合

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs (int u, int father)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (e[i] == father) continue;
        dfs(e[i], u);
        
        for (int k = m; k >= 0; k--)    
            for (int l = 0; l <= k - 1; l++)
                f[u][k] = max(f[u][k], f[e[i]][l] + f[u][k - 1 - l] + w[i]);
    }
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        add(a, b, c);
        add(b, a, c);
    }
    
    dfs(1, -1);
    
    cout << f[1][m] << endl;
    
    return 0;
}