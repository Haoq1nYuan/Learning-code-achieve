//https://www.acwing.com/problem/content/description/861/

#include <iostream>
#include <algorithm>

using namespace std;
const int N = 200010;

int n, m;
int p[N];

//结构体内嵌运算符重载
struct Edge
{
    //表示边 a->b 权值为 c
    int a, b, c;
    
    bool operator< (const Edge &w)const
    {
        return c < w.c;
    }
} edges[N];

//并查集加路径优化
int find (int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int Kruskal ()
{
    //首先升序排列所有边，可以使先加入的边较短
    sort(edges + 1, edges + m + 1);
    
    //初始化并查集，每个点在一个集合中
    for (int i = 1; i <= n; i++) p[i] = i;
    
    int res = 0, cnt = 0;
    
    //遍历所有边
    for (int i = 1; i <= m; i++)
    {
        auto t = edges[i];
        //判断每条边两端的点是否有相同的祖宗节点，
        //如果是，则不加入这条边，因为该两个节点
        //已经在树中了，再添加边就会出现环
        //至于为什么要直接赋值，还是为了减少运算次数，
        //因为find函数就是为了找到根节点
        t.a = find(t.a), t.b = find(t.b);
        if (t.a != t.b)
        {
            //如果未连通，则将a接入b的祖宗节点后
            p[t.a] = t.b;
            //更新最短路和边数
            res += t.c;
            cnt++;
        }
    }
    
    //如果边数小于 n - 1，说明有孤立点，不存在最小生成树
    if (cnt < n-1) return 0x3f3f3f3f;
    else return res;
}

int main ()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    
    int t = Kruskal();
    
    if (t == 0x3f3f3f3f) puts("impossible");
    else cout << t;
    
    return 0;
}