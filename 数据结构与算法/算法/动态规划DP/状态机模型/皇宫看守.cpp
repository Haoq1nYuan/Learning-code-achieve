// https://www.acwing.com/problem/content/1079/

// 限制条件：节点
/*
注意状态划分：不重不漏
f[i][3]:
j=0：根节点不放置守卫，且被父节点看到。
j=1：根节点不放置守卫，且被子节点看到。
j=2：根节点放置守卫。

与“战略游戏”的本质区别在于此题限制在点，“战略游戏”限制在边。

“战略游戏”中，根节点与每个子节点之间的边只能通过两个端点实现“被看到”的目标，与根节点的父节点无关。
只要父节点存在守卫，则所有字节点都可放可不放守卫；如果父节点不存在守卫，则所有子节点都需要防止守卫。状态转移规则是统一的。

在本题中，由于是规定每个节点都被看到，根节点既可以通过其父节点看到也可以通过其子节点看到，这与“战略游戏”完全不同，自然也就提升了状态表示的难度
当根节点存在守卫时，其子节点的状态不重要，都可以出现。
    f[u][2] += min(f[son][0], min(f[son][1], f[son][2]));
当根节点不存在守卫，且被子节点看到时，只需要有某一个子节点放置守卫即可满足题意，这个子节点具体是哪个需要讨论，其他子节点除了不能被父（根）节点看到外，其他状态都可能出现。
    f[u][1] = min(f[u][1], f[son][2] + sum(min(f[other_son][1], f[other_son][2])));
当根节点不存在守卫，且被父节点看到时，根节点的子节点除了不能被根节点看到外，其他状态都可能出现。
    f[u][0] += min(f[son][1], f[son][2]);
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1505;

int n, h[N], e[N], w[N], ne[N], idx, root;
int f[N][3];
bool has_father[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs (int u)
{
    f[u][2] = w[u];
    
    int sum = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int son = e[i];
        dfs(son);
        
        f[u][0] += min(f[son][2], f[son][1]);
        f[u][2] += min(min(f[son][0], f[son][1]), f[son][2]);
        sum += min(f[son][1], f[son][2]);
    }
    
    f[u][1] = 0x3f3f3f3f;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int son = e[i];
        f[u][1] = min(f[u][1], sum - min(f[son][2], f[son][1]) + f[son][2]);
    }
}

int main ()
{
    cin >> n;
    
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, num;
        cin >> a >> c >> num;
        w[a] = c;
        
        for (int j = 1; j <= num; j++)
        {
            cin >> b;
            has_father[b] = true;
            add(a, b);
        }
    }
    
    for (int i = 1; i <= n; i++) 
        if (!has_father[i]) root = i;
    
    dfs(root);
    
    cout << min(f[root][1], f[root][2]) << endl;
    
    return 0;
}