//https://www.acwing.com/problem/content/description/287/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 6010;

int n, ha[N];
int h[N], ne[N], e[N], idx;
//简单状态机！
//f[i][0] 表示所有以 i 为根节点的子树中取法的集合，0 表示不取 i，1 表示取 i
int f[N][2];
bool has_father[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs (int u)
{
    f[u][1] = ha[u];
    
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        
        f[u][1] += f[j][0];
        f[u][0] += max(f[j][1], f[j][0]);
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ha[i];
    
    memset(h, -1, sizeof(h));
    
    for (int i = 1; i < n; i++) 
    {
        int l, k;
        cin >> l >> k;
        //k为父节点，为第一参数
        add(k, l);
        //如果l有上司，即有父亲，记录数组
        has_father[l] = true;
    }
    
    //找顶头上司
    int root = 1;
    while (has_father[root]) root++;
    
    dfs(root);
    
    cout << max(f[root][0], f[root][1]) << endl;
    
    return 0;
}