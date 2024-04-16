// https://www.acwing.com/problem/content/848/

// 朴素解法，针对每一个节点做一遍dfs：8/14
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100005;

int n, ans = 0x3f3f3f3f;
int h[N], e[2 * N], ne[2 * N], idx;

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 返回以u为根节点的子树中点的个数
int dfs (int u, int father)
{
    int count = 0;
    int res = 0;     // 存储当前子树中去除根节点u后所有连通块中节点个数最多的数量
    
    // 遍历节点u的所有子节点
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        
        if (j == father) continue;  // 不往上遍历
        
        int d = dfs(j, u);  // 得到以j为根节点的子树中节点个数
        count += d;
        
        res = max(res, d);   // 不断更新连通块中节点个数的最大值
    }
    
    if (father == -1) ans = min(ans, res);   
    
    return count + 1;
}

int main ()
{
    cin >> n;
    
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        
        add(a, b);
        add(b, a);
    }

    for (int i = 1; i <= n; i++) dfs(i, -1);
    
    cout << ans << endl;
    
    return 0;
}

// 在一次dfs中求出最终答案
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100005;

int n, ans = 0x3f3f3f3f;
int h[N], e[2 * N], ne[2 * N], idx;
bool st[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 返回以u为根节点的子树中点的个数
int dfs (int u)
{
    st[u] = true;  // 每个点只遍历一次
    
    int count = 0;
    int res = 0;     // 存储当前子树中去除根节点u后所有连通块中节点个数最多的数量
    
    // 遍历节点u的所有子节点
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        
        if (st[j]) continue;
        
        int d = dfs(j);  // 得到以j为根节点的子树中节点个数
        count += d;
        
        res = max(res, d);   // 不断更新连通块中节点个数的最大值
    }
    
    res = max(res, n - count - 1);   
    // res为从u节点往下的连通块中节点个数，n - count - 1为从u节点往上的连通块的中的节点个数
    ans = min(ans, res);   
    
    return count + 1;
}

int main ()
{
    cin >> n;
    
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        
        add(a, b);
        add(b, a);
    }

    dfs(1);
    
    cout << ans << endl;
    
    return 0;
}