//https://www.acwing.com/problem/content/description/850/

#include <iostream>
#include <cstring>

using namespace std;
const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
//q队列依旧存储入度为0的节点，d存储所有点的入度
int q[N], d[N];

void add (int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort ()
{
    int hh = 0, tt = -1;
    
    //先将所有入度为 0 的点送入队列
    for ( int i = 1; i <= n; i++ )
        if (!d[i]) q[++tt] = i;
    
    while (hh <= tt)
    {
        int t = q[hh++];
        
        for ( int i = h[t]; i != -1; i = ne[i] )
        {
            //此时t就在最前面，所以它只有出度，可以删去对拓扑判断无影响的指向
            //具化到数组中就是e[i]的入度-1
            d[e[i]]--;
            //如果此时e[i]的入度减为0，说明此时e[i]也可以移到最前面
            if (d[e[i]] == 0) q[++tt] = e[i];
        }
    }
    
    //此处判断删去前部点的指向后是否队列中都是同向指向的点
    //即是否所有点都被送入了队列中
    return tt == n - 1;
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    for ( int i = 1; i <= m; i++ )
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        d[y]++;
    }
    
    if (topsort())
    {
        for ( int i = 0; i < n; i++ ) cout << q[i] << ' ';
        puts("");
    }
    else cout << -1;
    
    return 0;
}