// https://www.acwing.com/problem/content/325/

// 和“没有上司的舞会”很像
// 与“皇宫看守”不同的是，本题限制条件是边

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1505;

int n, h[N], e[N], ne[N], idx, root;
int f[N][2];  
// 以i为根节点的子树中放置士兵的最少数量，
// j = 1表示在节点i放置士兵，j = 0表示不放置，本题限制最多只能隔一个节点不放置。
bool has_father[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs (int u)
{
    f[u][1] = 1, f[u][0] = 0;
    
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int son = e[i];
        dfs(son);
        
        f[u][1] += min(f[son][1], f[son][0]);
        f[u][0] += f[son][1];
    }
}

int main ()
{
    while (cin >> n)
    {
        idx = 0;
        memset(h, -1, sizeof h);
        memset(has_father, 0, sizeof has_father);
        
        for (int i = 1; i <= n; i++)
        {
            int f, num, s;
            scanf("%d:(%d)", &f, &num);
            
            for (int j = 1; j <= num; j++) 
            {
                cin >> s;
                has_father[s] = true;
                add(f, s);
            }
        }
        
        for (int i = 0; i < n; i++) 
            if (!has_father[i]) root = i;
        
        dfs(root);
        
        cout << min(f[root][1], f[root][0]) << endl;
    }
    
    return 0;
}