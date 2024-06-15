#include <iostream>
#include <cstring>

using namespace std;

const int N = 1005;

int n, m, ans;
int h[N], e[N], ne[N], idx; 

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs (int x, int d)
{
    if (h[x] == -1) 
    {
        ans = max(ans, d);
        return;
    }

    for (int i = h[x]; i != -1; i = ne[i]) dfs(e[i], d + 1);
}

int main ()
{
    while (cin >> n >> m)
    {
        int res = 0;

        memset (h, -1, sizeof h);
        idx = 0;

        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            add(a, b);
        }

        for (int i = 1; i <= n; i++)
        {
            ans = 0;
            dfs(i, 1);
            res = max(res, ans);
        }

        cout << res << endl;
    }

    return 0;
}