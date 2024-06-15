#include <iostream>
#include <cstring>

using namespace std;

const int N = 2505, M = 2 * 6205;

int n, m, s, t, dist[N];
bool st[N];

int h[N], e[M], w[M], ne[M], idx;

void add (int a, int b, int c)
{
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra ()
{
    memset (dist, 0x3f, sizeof dist);
    dist[s] = 0;

    for (int i = 1; i <= n; i++)
    {
        int tem = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (tem == -1 || dist[tem] > dist[j]))
                tem = j;

        if (tem == t) break;

        st[tem] = true;

        for (int i = h[tem]; i != -1; i = ne[i])
        {
            int j = e[i];
            dist[j] = min(dist[j], dist[tem] + w[i]);
        }
    }
    
    if (dist[t] == 0x3f3f3f3f) return -1;
    else return dist[t];
}

int main ()
{
    cin >> n >> m >> s >> t;

    memset (h, -1, sizeof h);

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    
    cout << dijkstra() << endl;

    return 0;
}