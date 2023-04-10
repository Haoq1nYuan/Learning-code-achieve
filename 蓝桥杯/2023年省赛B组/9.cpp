#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, k, a[N], g[N];
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra (int b, int ee)
{
    memset(st, 0, sizeof(st));
    memset(dist, 0x3f, sizeof(dist));
    dist[b] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, b});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int distance = t.first, ver = t.second;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];

            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    return dist[ee];
}

int main ()
{
    cin >> n >> k;

    memset(h, -1, sizeof(h));

    for (int i = 1; i < n; i++)
    {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);    
        add(u, v, t), add(v, u, t);
    }

    for (int i = 1; i <= k; i++) cin >> g[i];

    for (int i = 1; i <= k; i++)
    {
        if (i == 1) cout << dijkstra(g[2], g[k]) << ' ';
        else if (i == k) cout << dijkstra(g[1], g[k - 1]) << ' ';
        else cout << dijkstra(g[1], g[i - 1]) + dijkstra(g[i + 1], g[k]) << ' ';
    }

    return 0;
}