//https://www.acwing.com/problem/content/853/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 100010;

int n, m;
int dist[N], st[N];
int h[N], w[N], e[N], ne[N], idx;

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa ()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    queue<int> q;
    q.push(1);
    st[1] = true;
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        for ( int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j]) 
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    return dist[n];
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    for ( int i = 1; i <= m; i++ )
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    
    int t = spfa();
    
    if (t == 0x3f3f3f3f) puts("impossible");
    else cout << t;
    
    return 0;
}