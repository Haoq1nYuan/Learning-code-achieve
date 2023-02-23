//https://www.acwing.com/problem/content/860/

#include <iostream>
#include <cstring>

using namespace std;
const int N = 510;

int n, m;
int g[N][N]; 
int dist[N];
bool st[N];

int prim ()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        
        //此处特判第i层循环出现不连通点的情况，即在上一轮的点进入集合后
        //其他未进入集合的点全都和集合不连通，那么此时最小生成树中
        //的点数显然少于n，不符合最小生成树的定义，所以需要特判。
        //另外，res 最大为 1000000000 < 00x3f3f3f3f，所以无需担心答案相同的情况
        if (i && dist[t] == 0x3f3f3f3f)  return 0x3f3f3f3f;
        
        st[t] = true;
        //此处特判，如果为第一轮循环，此时树为空，
        //没有所谓的点与集合的距离，也就不存在树中权值更新的情况
        //或者也可以将判断去掉，理解为创建了一个以点1为唯一元素的集合
        //此时树中权值为0，即加上了dist[1]
        if (i) res += dist[t];
        
        for (int j = 1; j <= n; j++) 
            dist[j] = min(dist[j], g[t][j]);
    }
    
    return res;
}

int main ()
{
    cin >> n >> m;
    
    memset(g, 0x3f, sizeof(g));
    
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        //因为是无向图，所以需要同时更新两个方向
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    
    int t = prim();
    
    if (t == 0x3f3f3f3f) puts("impossible");
    else cout << t;
    
    return 0;
}