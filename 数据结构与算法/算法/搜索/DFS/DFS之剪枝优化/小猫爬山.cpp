// https://www.acwing.com/problem/content/167/

// 朴素写法：5/17
#include <iostream>

using namespace std;

const int N = 20;

int n, m, w[N], e[N], num, ans, res = 20;
bool st[N];

void dfs (int cnt)
{
    if (ans >= res) return;
    
    if (cnt == n)
    {
        res = min(ans, res);
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (st[i]) continue;
        
        bool flag = false;
        for (int k = 1; k <= num; k++)
            if (w[i] + e[k] <= m)
            {
                flag = true;
                
                st[i] = true;
                e[k] += w[i];
                dfs(cnt + 1);
                e[k] -= w[i];
                st[i] = false;
            }
        
        if (!flag) 
        {
            ans++;
            e[++num] = w[i];
            st[i] = true;
            dfs(cnt + 1);
            ans--;
            st[i] = false;
            e[num--] = 0;
        }
    }
}

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    
    st[1] = true;
    e[++num] = w[1];
    ans ++;
    dfs(1);
    
    cout << res << endl;
    
    return 0;
}

// 去除贪心，优化搜索顺序
/*
本题的贪心思路无法证明正确性，举例即可
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;

int n, m, w[N], e[N], res = 20;

void dfs (int cnt, int ans)
{
    if (ans >= res) return;
    
    if (cnt == n)
    {
        res = ans;
        return;
    }
    
    for (int k = 1; k <= ans; k++)
        if (w[cnt + 1] + e[k] <= m)
        {
            e[k] += w[cnt + 1];
            dfs(cnt + 1, ans);
            e[k] -= w[cnt + 1];
        }

    // 即考虑放入已有游览车的情况，也考虑放入新缆车的情况
    e[ans + 1] = w[cnt + 1];
    dfs(cnt + 1, ans + 1);
    e[ans + 1] = 0;
}

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];

    // 优化搜索顺序
    sort(w + 1, w + 1 + n);
    reverse(w + 1, w + 1 + n);
    
    e[1] = w[1];
    dfs(1, 1);  // 从重猫遍历到轻猫，且必先放重猫后放轻猫，因此无需判重数组。
    
    cout << res << endl;
    
    return 0;
}