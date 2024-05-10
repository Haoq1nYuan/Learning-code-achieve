// // 朴素解法
// #include <iostream>
// #include <cstring>

// using namespace std;

// typedef long long ll;

// const int N = 255;

// int n, m;
// ll g[N][N], dist[N], ansx, ansy;
// bool st[N];

// int pre[N];

// ll dijkstra (int mode)
// {
//     memset(st, false, sizeof st);
//     memset(dist, 0x3f, sizeof dist);
//     dist[1] = 0;
    
//     for ( int i = 0; i < n; i++ )
//     {
//         int t = -1;

//         for( int j = 1; j <= n; j++ )
//             if (!st[j] && (t == -1 || dist[t] > dist[j]))
//                 t = j;
                
//         if (t == n)  break;

//         st[t] = true;

//         for ( int j = 1; j <= n; j++ )
//             if (dist[j] > dist[t] + g[t][j]) 
//             {
//                 dist[j] = dist[t] + g[t][j];
//                 if (mode) pre[j] = t;
//             }
//     }
    
//     return dist[n];
// }

// int main ()
// {
//     cin >> n >> m;

//     memset(g, 0x3f, sizeof g);

//     while (m--)
//     {
//         int a, b;
//         ll x;
//         cin >> a >> b >> x;

//         g[a][b] = min(g[a][b], x);
//         g[b][a] = min(g[b][a], x);
//     }

//     ansx = dijkstra(1);

//     int idx = n;
//     while (pre[idx])   // 遍历原始最短路径上的所有路径
//     {
//         g[pre[idx]][idx] *= 2;
//         ansy = max(ansy, dijkstra(0));
//         g[pre[idx]][idx] /= 2;

//         idx = pre[idx];
//     }

//     cout << ansy - ansx << endl;

//     return 0;
// }

// 堆优化版
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 255;

typedef long long ll;
typedef pair<ll, int> PII;

int n, m;
int h[N], w[N], e[N], ne[N], idx;

ll dist[N], ansx, ansy;
bool st[N];

int pre[N], mark[N];

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

ll dijkstra (int mode)
{
    memset(st, false, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;
        if (st[ver]) continue;

        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];

            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
                if (mode) 
                {
                    pre[j] = ver;
                    mark[j] = i;
                }
            }
        }
    }

    return dist[n];
}

int main ()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--)
    {
        int a, b;
        ll x;
        
        cin >> a >> b >> x;

        add(a, b, x);
        add(b, a, x);
    }

    ansx = dijkstra(1);

    int idx = n;
    while (pre[idx])
    {
        w[mark[pre[idx]]] *= 2;
        ansy = max(ansy, dijkstra(0));
        w[mark[pre[idx]]] /= 2;
        
        idx = pre[idx];
    }

    cout << ansy - ansx << endl;

    return 0;
}

/*
5 7
2 1 5
1 3 1
3 2 8
3 5 7
3 4 3
2 4 7
4 5 2
*/