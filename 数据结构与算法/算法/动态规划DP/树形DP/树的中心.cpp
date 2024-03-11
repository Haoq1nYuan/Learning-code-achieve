// https://www.acwing.com/problem/content/1075/

// 注意题意，这里要求的是某个点到其他点所有最长路径中的最小值。

// 朴素写法，直接暴力遍历每一个点，并求出当前点在树中的最长距离，并不断与ans比较。6/11
#include <iostream>
#include <cstring>

using namespace std;

const int N = 10005;

int n, h[N], e[2 * N], ne[2 * N], w[2 * N], idx;
int dist;

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs (int u, int father)
{
    int dist = 0;
    
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        
        if (j == father) continue;
        
        int d = dfs(j, u) + w[i];
        
        dist = max(dist, d);
    }
    
    return dist;
}

int main ()
{
    cin >> n;
    
    memset(h, -1, sizeof h);
    
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        add(a, b, c);
        add(b, a, c);
    }
    
    int ans = 0x3f3f3f3f; 
    for (int i = 1; i <= n; i++) ans = min(ans, dfs(i, -1));  // 这里的dfs必须放在循环内，每次求出一个节点的最长距离。
    // 至于为什么不能像“树的最长路径”一样只深搜一次，是因为每次深搜都会将初始传入的那个节点规定为树的根节点，换言之就是只能完全求出该点的一个最长距离。
    // 至于其余节点，由于在dfs过程中规定不能向上遍历父节点，只能求出这些节点在以其为根节点的子树中的一个最长距离，这显然不能作为最终的答案。

    cout << ans << endl;
    
    return 0;
}

// 优化写法：
/*
为了弥补朴素写法中二层循环导致的超时问题，这里采用一种换根DP的思想：
朴素解法中的dfs不能遍历父节点，为了解决这个问题，可以在做一遍往下的dfs后再做一遍往上遍历父节点的dfs
往下的dfs负责求出所有节点在以自身为根节点的子树中的最长距离d
往上的dfs负责求出所有结点的父节点在以其为根节点的子树中的最长距离u（与b区分）
为了防止d与u重合的情况，需要在往下dfs时维护三个数组：当前结点i往下的最长距离和次长距离，以及最长距离所对应的起点编号（i的某个子节点）
在往上dfs时，只需要判断i的父节点j在以其为根节点的子树中的最长距离是否以i为起点
如果是，只能将j的次长距离作为i往上的最长距离；反之就直接将j的最长距离赋给i往上的最长距离。
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100005;

int n, h[N], e[2 * N], ne[2 * N], w[2 * N], idx;
int d1[N], d2[N], p1[N], up[N];
bool is_leaf[N];

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs_down (int u, int father)
{
    d1[u] = d2[u] = -0x3f3f3f3f;   
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == father) continue;
        
        int d = dfs_down(j, u) + w[i];
        
        if (d >= d1[u])
        {
            d2[u] = d1[u], d1[u] = d;
            p1[u] = j;
        }
        else if (d > d2[u]) d2[u] = d;
    }
        
    if (d1[u] == -0x3f3f3f3f)
    {
        d1[u] = d2[u] = 0;
        is_leaf[u] = true;
    }
    
    return d1[u];
}

void dfs_up (int u, int father)
{
    for (int i = h[u]; i != -1; i = ne[i])   // 求根节点u的每一个子节点j的最长up距离。
    {
        int j = e[i];
        if (j == father) continue;
        
        if (p1[u] == j) up[j] = max(up[u], d2[u]) + w[i];
        else up[j] = max(up[u], d1[u]) + w[i];
        
        dfs_up(j, u);
    }
}

int main ()
{
    cin >> n;
    
    memset(h, -1, sizeof h);
    
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        add(a, b, c);
        add(b, a, c);
    }
    
    // 求出由某节点往下走的最长距离和次长距离
    dfs_down(1, -1);
    
    // 求出由某节点往上走的最长距离
    dfs_up(1, -1);
    
    int ans = d1[1];
    for (int i = 2; i <= n; i++) 
    {
        if (is_leaf[i]) ans = min(ans, up[i]);
        else ans = min(ans, max(d1[i], up[i]));
    }
    
    cout << ans << endl;
    
    return 0;
}