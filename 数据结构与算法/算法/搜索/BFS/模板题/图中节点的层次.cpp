// https://www.acwing.com/problem/content/849/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 100005;

int n, m, d[N];
int h[N], e[N], ne[N], idx;
queue<int> q;
bool st[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
} 

int bfs ()
{
    q.push(1);
    st[1] = true;
    d[1] = 0;
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
        
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            
            if (st[j]) continue;
            
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q.push(j);
                st[j] = true;
            }
        }
    }
    
    return d[n];
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    
    memset(d, -1, sizeof d);
    cout << bfs() << endl;
    
    return 0;
}