//https://www.acwing.com/problem/content/description/4410/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 50010, M = 999997;

int n, m;

//定义雷的坐标和半径
struct circle 
{
    int x, y, r;
} cir[N];

ll h[M];  //定义哈希表，这里采用开放寻址法
int id[M];  //定义每一个最优炸弹对应的 h 数组下标
bool st[M];  //判重数组保证每一个引爆的炸弹只会被计算一次

//以 x * (1e9 + 1) + y 的形式得到每一个坐标的哈希值
//因为坐标最大为 1e9，而大于 1e9 的最小质数就是 1e9 + 1
ll get_key (int x, int y)
{
    return (ll)x * 1000000001 + y;
}

//哈希表的寻找操作
int find (int x, int y)
{
    ll key = get_key(x, y);
    int t = (key % M + M) % M;
    
    while (h[t] != -1 && h[t] != key)
    {
        t++;
        if (t == M) t = 0;
    }
        
    return t;
}

//搜索每一个被火箭引爆的炸弹所能够波及的其他炸弹
void dfs (int x, int y, int r)
{
    st[find(x, y)] = true;
    
    for (int i = x - r; i <= x + r; i++)
        for (int j = y - r; j <= y + r; j++)
            if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r)
            {
                int t = find(i, j);
                if (id[t] && !st[t]) dfs(i, j, cir[id[t]].r);
            }
}

int main()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    for (int i = 1; i <= n; i++)
    {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        cir[i] = {x, y, r};
        
        //得到当前炸弹哈希值在 h 数组中的下标
        int t = find(x, y);
        //如果 h[t] 还没有元素，则更新
        if (h[t] == -1) h[t] = get_key(x, y);
        //如果是当前坐标还没有炸弹，或当前位置上的炸弹半径比较小的话，更新当前位置的炸弹id
        if (!id[t] || cir[id[t]].r < r) id[t] = i;
    }
    
    while (m--)
    {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        
        //遍历当前火箭引爆范围内的所有整数坐标
        for (int i = x - r; i <= x + r; i++)
            for (int j = y - r; j <= y + r; j++)
                if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r)
                {
                    //如果当前坐标有炸弹且未被引爆，则以该炸弹为起点搜索其他可能被连锁引爆的炸弹
                    int t = find(i, j);
                    if (id[t] && !st[t]) dfs(i, j, cir[id[t]].r);
                }
    }
    
    //计算有多少炸弹被引爆
    //因为 st 数组的下标为哈希表中每一个炸弹哈希值所对应的下标
    //所以需要先求到当前炸弹哈希值的对应下标：哈希表查找操作
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (st[find(cir[i].x, cir[i].y)]) res++;
        
    cout << res << endl;
    
    return 0;
}