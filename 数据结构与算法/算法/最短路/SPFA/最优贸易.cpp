//https://www.acwing.com/problem/content/343/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 100010, M = 2000010;

int n, m;
bool st[N];
int hs[N], he[N], e[M], ne[M], w[N], idx;
int maxe[N], mine[N];
int q[N], hh, tt = -1;

void add (int *h, int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void spfa (int *h, int *dist, int type)
{
    if (type == 1)
    {
        dist[1] = w[1];
        q[++tt] = 1;
        st[1] = true;
    }
    else
    {
        dist[n] = w[n];
        q[++tt] = n;
        st[n] = true;
    }
    
    while (hh <= tt)
    {
        int t = q[hh++];
        st[t] = false;
        
        //遍历所有与 t 节点间只有一条有向边连通的所有点 k1, k2, k3,…
        //且 t 节点为前驱结点，边为 t -> k
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            
            if ((type == 2 && dist[j] < max(dist[t], w[j])) || (type == 1 && dist[j] > min(dist[t], w[j])))
            {
                if (type == 2) dist[j] = max(dist[t], w[j]);
                else dist[j] = min(dist[t], w[j]);
            }
            
            if (!st[j])
            {
                q[++tt] = j;
                //此处需要考虑到模拟队列容量限制
                if (tt == N) tt = 0;
                st[j] = true;
            }
        }
    }
}

int main ()
{
    cin >> n >> m;
    
    memset(hs, -1, sizeof(hs));
    memset(he, -1, sizeof(he));
    
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        
        add(hs, x, y), add(he, y, x);
        
        if (z == 2) add(hs, y, x), add(he, x, y);
    }
    
    //找最小值
    memset(mine, 0x3f, sizeof(mine));
    spfa(hs, mine, 1);
    
    memset(st, 0, sizeof(st));
    memset(q, 0, sizeof(q));
    hh = 0, tt = -1;
    
    //找最大值
    spfa(he, maxe, 2);
    
    int maxs = 0;
    for (int i = 1; i <= n; i++) maxs = max(maxs, maxe[i] - mine[i]);
    
    cout << maxs << endl;
    
    return 0;
}