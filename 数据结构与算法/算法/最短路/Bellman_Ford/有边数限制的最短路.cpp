//https://www.acwing.com/problem/content/855/

#include <iostream>
#include <cstring>

using namespace std;
const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];

struct 
{
    int a, b, w;
} edges[M];

void bellman_ford ()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    //遍历k次表示经过不超过k条边到达终点的最短距离
    //经过k次操作，k个点的最短距离也就确定了
    for ( int i = 0; i < k; i++ )
    {
        //每次k遍历中都是所有点同时向相邻的点出发，所以要存储上一次k循环后的dist数组结果
        memcpy(backup, dist, sizeof(dist));
        
        for ( int j = 0; j < m; j++ )
        {
            auto q = edges[j];
            dist[q.b] = min(dist[q.b], backup[q.a] + q.w);
        }
    }
}

int main ()
{
    cin >> n >> m >> k;
    
    for ( int i = 0; i < m; i++ )
    {
        int x, y, z;
        cin >> x >> y >> z;
        //存储x到y的一条长为z的边
        edges[i] = {x, y, z};
    }
    
    bellman_ford();
    
    //此处-1也可能是答案，所以不能在函数中直接判断 dist[n]，所以不能用 -1 作为有无解的判断依据
    //此处的判断临界条件就是最短路的最大值
    if (dist[n] > 0x3f3f3f3f - N * M) puts("impossible");
    else cout << dist[n];
    
    return 0;
}