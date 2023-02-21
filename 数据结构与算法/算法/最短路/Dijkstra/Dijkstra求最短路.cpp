//https://www.acwing.com/problem/content/851/

//这里的最短路问题和bfs的最短路有个相同之处，就是先遍历的点最短距离肯定更小
#include <iostream>
#include <cstring>

using namespace std;
const int N = 510;

int n, m;
//g为邻接矩阵，dist存储每个节点到1的距离
int g[N][N], dist[N];
//判重数组，保证每个点之遍历一次
bool st[N];

int dijkstra()
{
    //初始化距离
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    //遍历n次，每次可以确定一个点到1的最短路
    for ( int i = 0; i < n; i++ )
    {
        int t = -1;
        //找到当前未被遍历且距离1最短的点
        for( int j = 1; j <= n; j++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
                
        if (t == n)  break;

        st[t] = true;
        //通过找到的点的最短距离去更新与它相邻的其他点的距离
        for ( int i = 1; i <= n; i++ )
            dist[i] = min(dist[i], dist[t] + g[t][i]);
    }
    
    //如果最后一个点没有被改变，说明不存在最短路
    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main ()
{
    cin >> n >> m;
    
    memset(g, 0x3f, sizeof(g));
    
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        //min操作是为了保存最短的一条边，即为了应对重编的情况
        g[x][y] = min(z, g[x][y]);
    }
    
    cout << dijkstra();
    
    return 0;
}

//堆优化版
//https://www.acwing.com/problem/content/851/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 150010;
typedef pair<int, int> PII;

int n, m;
//用邻接表存储，不过此处多一个距离量
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
//判重数组，保证每个点之遍历一次
bool st[N];

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    //初始化距离
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    //这里需要先存距离，方便排序
    heap.push({0, 1});
    
    //小根堆自动得到当前距离1最近的点
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
                
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        
        st[ver] = true;
        
        for ( int i = h[ver]; i != -1; i = ne[i] )
        {
            int j = e[i];
            //将所有被更新距离的点存到小根堆中，自动排序，
            //下一次取出就是当前距离1最近且未被遍历过的点
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    
    //如果最后一个点没有被改变，说明不存在最短路
    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        //min操作是为了保存最短的一条边，即为了应对重编的情况
        add(x, y, z);
    }
    
    cout << dijkstra();
    
    return 0;
}