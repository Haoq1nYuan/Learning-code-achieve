//https://www.acwing.com/problem/content/849/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 100010, M = N * 2;

int n, m;
//存储图
int h[N], e[M], ne[M], idx;
//d[i]存储编号为1的节点到i的距离
int d[N];

queue<int> q;

void add (int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs ()
{
    q.push(1);    
    
    d[1] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        
        for ( int i = h[t]; i != -1; i = ne[i] )
            //此处也要保证每个节点只遍历一次
            if (d[e[i]] == -1) 
            {
                d[e[i]] = d[t] + 1;
                q.push(e[i]);
            }
    }
    
    return d[n];
}

int main ()
{
    cin >> n >> m;
    
    //初始化距离数组为-1，既方便判重，又方便输出无解的情况
    memset(d, -1, sizeof(d));
    //邻接表的头节点初始值都是-1
    memset(h, -1, sizeof(h));
    
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    
    cout << bfs();
    
    return 0;
}