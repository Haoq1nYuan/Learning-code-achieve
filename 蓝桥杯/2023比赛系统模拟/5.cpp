#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll, int> PII;

const int N = 2030, M = 4060;

int h[N], e[M], ne[M], w[M], idx;
ll dist[N];
bool st[N];

int gcd (int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

ll dijkstra ()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        ll distance = t.first;
        int ver = t.second;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];

            if (dist[j] > distance + (ll)w[i])
            {
                dist[j] = distance + (ll)w[i];
                heap.push({dist[j], j});
            }
        }
    }

    return dist[2021];
}

int main ()
{
    memset(h, -1, sizeof(h));

    for (int i = 1; i <= 2020; i++)
        for (int j = i + 1; j <= i + 21 && j <= 2021; j++)
        {
            int k = i * j / gcd(i, j);
            add(i, j, k), add(j, i, k);
        }
        
    printf("%lld", dijkstra());

    return 0;
}
