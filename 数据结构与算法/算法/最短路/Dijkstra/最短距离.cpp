//https://www.acwing.com/problem/content/description/1490/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010, M = 300010;

int n, m, a, b, c, x;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijsktra ()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 0});
    
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        
        int a = t.first, b = t.second;
        
        if (st[b]) continue;
        st[b] = true;
        
        for (int i = h[b]; i != -1; i = ne[i])
        {
            int j = e[i];
            
            if (dist[j] > a + w[i])
            {
                dist[j] = a + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    while (m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    
    cin >> m;
    while (m--)
    {
        scanf("%d", &x);
        add(0, x, 0);
    }
    
    dijsktra();
    
    cin >> m;
    while (m--)
    {
        scanf("%d", &x);
        cout << dist[x] << endl;
    }
    
    return 0;
}