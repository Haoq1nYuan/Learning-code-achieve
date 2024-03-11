// https://www.acwing.com/problem/content/1074/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 10005;

int n, h[N], e[2 * N], w[2 * N], ne[2 * N], idx, ans;

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs (int u, int father)
{
    int dist = 0;        // 从当前点开始往下遍历的最长距离
    int d1 = 0, d2 = 0;  // 从当前点开始往下遍历的最长距离和次长距离
    
    for (int i = h[u]; i != -1; i = ne[i])  // 遍历所有与节点u相连的节点
    {
        int j = e[i];
        if (j == father) continue;          // 如果遍历到父节点则跳过
        
        int d = dfs(j, u) + w[i];           // 求出从子节点j开始往下遍历的最长距离
        
        dist = max(dist, d);                
        
        if (d > d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;
    }
    
    ans = max(ans, d1 + d2);                // 将最长距离和次长距离相加即可得到经过节点i的最长距离
    
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

    dfs(1, -1);  // 从任意一个节点开始遍历，第二个参数表示父节点编号，用于防止向上遍历的情况
    
    cout << ans << endl;
    
    return 0;
}