//https://www.acwing.com/problem/content/description/862/

//dfs版
#include <iostream>
#include <cstring>

using namespace std;
const int N = 100010, M = 2*N;  
//此处一定要开2倍的e数组和ne数组，因为无向边需要我们同时存储两个方向

int n, m;
int h[N], e[M], ne[M], idx;
//color数组1和2表示两种颜色
int color[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs (int u, int c)
{
    //首先染色
    color[u] = c;
    
    //遍历和u这个点连通的点并给未染色的点染色
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        //判断是否已被染色
        //如果是，则判断是否改颜色编号与u的颜色编号相重
        //如果相重，则说明矛盾，返回false
        //如果不是，则染色3 - c的编号，继续递归
        //并且，如果下一层递归返回上来的是负值，则也返回负值
        if (!color[j])
        {
            //判断j点的连通块中是否存在矛盾，同时未染色的染色
            if (!dfs(j, 3 - c)) return false;
        }
        else if (color[j] == c) return false;
    }
    
    return true;
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    
    bool flag = true;
    //遍历所有点，如果没染色，则染色，这里统一从编号1开始染色
    //因为如果这个点没有被染色，那么它肯定和前面遍历的点
    //及其连通块不连通，所以直接从1 或 2开始染色即可
    for (int i = 1; i <= n; i++)
        if (!color[i])
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
    
    if (flag) puts("Yes");
    else puts("No");
    
    return 0;
}

//bfs版
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 100010, M = 2*N;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool bfs (int u)
{
    queue<int> q;
    q.push(u);
    color[u] = 1;
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
        
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!color[j])
            {
                color[j] = 3 - color[t];
                q.push(j);
            }
            else if (color[j] == color[t]) return false;
        }
    }
    
    return true;
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    
    bool flag = true;
    
    for (int i = 1; i <= n; i++)
        if (!color[i] && !bfs(i))
        {    
            flag = false;
            break;
        }
            
    if (flag) puts("Yes");
    else puts("No");
    
    return 0;
}