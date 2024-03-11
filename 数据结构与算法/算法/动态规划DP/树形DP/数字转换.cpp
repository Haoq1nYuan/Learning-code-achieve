// https://www.acwing.com/problem/content/1077/

// 不一定只有一棵树，需要将每棵树的根节点存下来

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 50005;

int n, h[N], e[2 * N], ne[2 * N], idx, ans;
bool st[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int get_prime (int n)
{
    int sum = 0;
    vector<int> a;
    int len = sqrt(n);
    for (int i = 1; i <= len; i++)
    {
        if (n % i == 0 && i * i == n) a.push_back(i);
        else if (n % i == 0)
        {
            a.push_back(i);
            a.push_back(n / i);
        }
    }
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < a.size(); i++) 
        if (a[i] != n) sum += a[i];

    return sum;
}

int dfs (int u)
{
    int d1 = 0, d2 = 0;
    
    for (int i = h[u]; ~i; i = ne[i])
    {
        int son = e[i];
        
        int d = dfs(son) + 1;
    
        if (d >= d1) d2 = d1, d1 = d;
        else if (d >= d2) d2 = d;
    }
    
    ans = max(ans, d2 + d1);
    
    return d1;
}

int main ()
{
    cin >> n;
    
    memset(h, -1, sizeof h);
    for (int i = 2; i <= n; i++)  // i从2枚举，因为1的sum为0，但树中不会有0号点
    {
        int sum = get_prime(i);
        
        if (sum < i && !st[i])
        {
            st[i] = true;  // 如果st[i]为true，则表示i不是根节点
            add(sum, i);  
            // 每个约数之和对应的i不一定唯一，因此不能将边从sum连至i，否则会导致一个子结点有多个父节点
        } 
    }
    
    for (int i = 1; i <= n; i++)   // 遍历所有树的数根
        if (!st[i]) dfs(i); 
    
    cout << ans << endl;
    
    return 0;
}