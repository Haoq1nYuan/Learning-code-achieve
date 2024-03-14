// https://www.acwing.com/problem/content/1120/

// 朴素写法：3143ms
#include <iostream>
#include <vector>

using namespace std;

const int N = 15;

int n, x[N], ans, res = N;
vector<int> p[N];
bool st[N];

int gcd(int a, int b)
{
    if (a < b) swap(a, b);
    return b ? gcd(b, a % b) : a;
}

void dfs(int cnt)
{
    if (cnt == n)
    {
        res = min(res, ans);
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (st[i]) continue;
        
        bool flag = false;
        for (int k = 1; k <= ans; k++)
        {
            int j;
            for (j = 0; j < p[k].size(); j++)
                if (gcd(p[k][j], x[i]) != 1) break;
            
            if (j == p[k].size())
            {
                flag = true;
                
                p[k].push_back(x[i]);
                st[i] = true;
                
                dfs(cnt + 1);

                p[k].erase(p[k].end() - 1);
                st[i] = false;
                
                break;
            }
        }
        
        if (!flag)
        {
            p[++ans].push_back(x[i]);
            st[i] = true;
            dfs(cnt + 1);
            p[ans--].clear();
            st[i] = false;
        }
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    
    st[1] = true;
    p[++ans].push_back(x[1]);
    dfs(1);
    
    cout << res << endl;
    
    return 0;
}

// 优化：将vector替换为二维数组，2332ms
#include <iostream>
#include <vector>

using namespace std;

const int N = 15;

int n, x[N], ans, res = N;
int p[N][N];
bool st[N];

int gcd(int a, int b)
{
    if (a < b) swap(a, b);
    return b ? gcd(b, a % b) : a;
}

void dfs(int cnt)
{
    if (cnt == n)
    {
        res = min(res, ans);
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (st[i]) continue;
        
        bool flag = false;
        for (int k = 1; k <= ans; k++)
        {
            int j;
            for (j = 0; p[k][j]; j++)
                if (gcd(p[k][j], x[i]) != 1) break;
            
            if (!p[k][j])
            {
                flag = true;
                
                p[k][j] = x[i];
                st[i] = true;
                
                dfs(cnt + 1);

                p[k][j] = 0;
                st[i] = false;
                
                break;
            }
        }
        
        if (!flag)
        {
            p[++ans][0] = x[i];
            st[i] = true;
            dfs(cnt + 1);
            p[ans--][0] = 0;
            st[i] = false;
        }
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    
    st[1] = true;
    p[++ans][0] = x[1];
    dfs(1);
    
    cout << res << endl;
    
    return 0;
}

// 优化：加上剪枝，1836ms
#include <iostream>
#include <vector>

using namespace std;

const int N = 15;

int n, x[N], ans, res = N;
int p[N][N];
bool st[N];

int gcd(int a, int b)
{
    if (a < b) swap(a, b);
    return b ? gcd(b, a % b) : a;
}

void dfs(int cnt)
{
    if (ans >= res) return;
    
    if (cnt == n)
    {
        res = min(res, ans);
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (st[i]) continue;
        
        bool flag = false;
        for (int k = 1; k <= ans; k++)
        {
            int j;
            for (j = 0; p[k][j]; j++)
                if (gcd(p[k][j], x[i]) != 1) break;
            
            if (!p[k][j])
            {
                flag = true;
                
                p[k][j] = x[i];
                st[i] = true;
                
                dfs(cnt + 1);

                p[k][j] = 0;
                st[i] = false;
                
                break;
            }
        }
        
        if (!flag)
        {
            p[++ans][0] = x[i];
            st[i] = true;
            dfs(cnt + 1);
            p[ans--][0] = 0;
            st[i] = false;
        }
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    
    st[1] = true;
    p[++ans][0] = x[1];
    dfs(1);
    
    cout << res << endl;
    
    return 0;
}