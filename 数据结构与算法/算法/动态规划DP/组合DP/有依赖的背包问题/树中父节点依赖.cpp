// https://www.acwing.com/problem/content/10/

// 树形DP+分组背包DP

// 三维解法
#include <iostream>
#include <vector>

using namespace std;

const int N = 105;

int n, m, v[N], w[N], p, root;
vector<int> son[N];
int f[N][N][N];   // 以i为根节点，从根节点的前j个子树中选，总体积最大为k的集合

void dfs (int u)
{
    // 如果子树中可分配总体积大于根节点u的体积，则将根节点体积分配进去
    // 因为要想分配子树中的其他节点，就必须分配父节点。
    for (int j = v[u]; j <= m; j++) f[u][0][j] = w[u];   // 注意，第二维元素无需全部初始化，只需要初始化入口0即可
    
    // 遍历根节点u的所有子节点，i为已经遍历的子节点个数
    for (int i = 1; i < son[u].size(); i++)
    {
        int s = son[u][i];              // 当前子节点的编号
        int s_num = son[s].size() - 1;  // 当前子节点在以其为根节点的子树中的子节点个数
        dfs(s);                         // 先求出以当前子节点为根节点的子树中的所有价值选择状态
        
        // 分组背包模板：从u的前i个子树（前i个物品组）中选，且总体积不超过j的所有方案
        for (int j = v[u]; j <= m; j++)
            for (int k = 0; k <= j - v[u]; k++) // 在第i组中选择的体积为k，上限为 j - v[u]，因为根节点必选
                f[u][i][j] = max(f[u][i][j], f[u][i - 1][j - k] + f[s][s_num][k]);
    }
}

int main ()
{
    cin >> n >> m;
    
    // 要求son数组从下标1开始记录子节点，这也符合分组背包中组数的含义
    for (int i = 1; i <= n; i++) son[i].push_back(0);
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> p;
        
        if (p == -1) root = i;
        else son[p].push_back(i);
    }
    
    dfs(root);
    
    cout << f[root][son[root].size() - 1][m] << endl;
    
    return 0;
}

// 二维优化解法：与分组背包的二维优化完全一致
#include <iostream>
#include <vector>

using namespace std;

const int N = 105;

int n, m, v[N], w[N], p, root;
vector<int> son[N];
int f[N][N];   // 以i为根节点，从根节点的前j个子树中选，总体积最大为k的集合

void dfs (int u)
{
    // 如果子树中可分配总体积大于根节点u的体积，则将根节点体积分配进去
    // 因为要想分配子树中的其他节点，就必须分配父节点。
    for (int j = v[u]; j <= m; j++) f[u][j] = w[u];   // 注意，第二维元素无需全部初始化，只需要初始化入口0即可
    
    // 遍历根节点u的所有子节点，i为已经遍历的子节点个数
    for (int i = 1; i < son[u].size(); i++)
    {
        int s = son[u][i];              // 当前子节点的编号
        dfs(s);                         // 先求出以当前子节点为根节点的子树中的所有价值选择状态
        
        // 分组背包模板：从u的前i个子树（前i个物品组）中选，且总体积不超过j的所有方案
        for (int j = m; j >= v[u]; j--)
            for (int k = 0; k <= j - v[u]; k++) // 在第i组中选择的体积为k，上限为 j - v[u]，因为根节点必选
                f[u][j] = max(f[u][j], f[u][j - k] + f[s][k]);
    }
}

int main ()
{
    cin >> n >> m;
    
    // 要求son数组从下标1开始记录子节点，这也符合分组背包中组数的含义
    for (int i = 1; i <= n; i++) son[i].push_back(0);
    
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> p;
        
        if (p == -1) root = i;
        else son[p].push_back(i);
    }
    
    dfs(root);
    
    cout << f[root][m] << endl;
    
    return 0;
}

// 用连接表存储树
#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;

int n, m, v[N], w[N], p, root;
int h[N], e[N], ne[N], idx;
int f[N][N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs (int u)
{
    for (int j = v[u]; j <= m; j++) f[u][j] = w[u];
    
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int son = e[i];
        dfs(son);
        
        for (int j = m; j >= v[u]; j--)
            for (int k = 0; k <= j - v[u]; k++)
                f[u][j] = max(f[u][j], f[son][k] + f[u][j - k]);
    }
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> p;
        
        if (p == -1) root = i;
        else add(p, i);
    }
    
    dfs(root);
    
    cout << f[root][m] << endl;
    
    return 0;
}