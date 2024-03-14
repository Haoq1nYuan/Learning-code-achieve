// https://www.acwing.com/problem/content/169/

// 朴素写法：排除等效冗余：组合数而非排列数
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 70;

int n, l[N], len;
vector<int> primes;
int e[N], num;

void get_primes (int a)
{
    int len = sqrt(a);
    for (int i = 1; i <= len; i++)
    {
        if (a % i == 0 && i * i == a) primes.push_back(i);
        else if (a % i == 0) 
        {
            primes.push_back(i);
            primes.push_back(a / i);
        }
    }
    
    sort(primes.begin(), primes.end());
}

bool dfs (int u)
{
    if (u == n + 1) 
    {
        for (int k = 1; k <= num; k++)
            if (e[k] != len) return false;
        
        return true;
    }
    
    // 不开
    for (int k = 1; k <= num; k++)
        if (e[k] + l[u] <= len) 
        {
            e[k] += l[u];
            if (dfs(u + 1)) return true;
            e[k] -= l[u];
        }
    
    // 新开
    e[++num] = l[u];
    if (dfs(u + 1)) return true;
    e[num--] = 0;
    
    return false;
}

int main ()
{
    while (cin >> n, n)
    {
        int sum = 0, maxl = 0;
        
        for (int i = 1; i <= n; i++) 
        {
            cin >> l[i];
            maxl = max(maxl, l[i]);
            sum += l[i];
        }
        
        // 得到所有可能的长度，这些长度满足：1.大于最长的短木棍，2.是所有短木棍长度和的约数。
        get_primes(sum);
        
        int idx = 0;
        while (primes[idx] <= maxl) idx++;
        
        for (int i = idx; i < primes.size(); i++)
        {
            len = primes[i];
            
            memset(e, 0, sizeof e);
            num = 0;
            
            if (dfs(1)) 
            {
                cout << len << endl;
                break;
            }
        }
    }
    
    return 0;
} 

// 优化
/*
优化搜索顺序：从大到小遍历短树枝
排除等效冗余2：如果当前木棍a加到当前棒中之后构造失败了，则直接跳过后面所有与木棍a长度相等的木棍。
排除等效冗余3：如果木棍a加到某一木棒的开头之后构造失败了，则这种木棒长度的枚举必定失败。
排除等效冗余4：如果木棍a加到某一木棒的末尾之后构造失败了，则这种木棒长度的枚举必定失败。

具体证明过程：
https://www.acwing.com/solution/content/36030/
要抓住木棍之间的等效性，将其灵活替换
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 70;

int n, l[N], len, sum, maxl;
vector<int> primes;
int e[N], num;
bool st[N];

void get_primes (int a)
{
    int len = sqrt(a);
    for (int i = 1; i <= len; i++)
    {
        if (a % i == 0 && i * i == a) primes.push_back(i);
        else if (a % i == 0) 
        {
            primes.push_back(i);
            primes.push_back(a / i);
        }
    }
    
    sort(primes.begin(), primes.end());
}

bool dfs (int u, int e, int start)  // u：当前构造到的木棒数，e：当前木棒已构造的长度，start：当前枚举到的木棍编号
{
    if (u * len == sum) return true;
    if (e == len) return dfs(u + 1, 0, 0);
    
    for (int i = start; i <= n; i++)
    {
        if (st[i]) continue;
        if (e + l[i] > len) continue;
        
        st[i] = true;
        if (dfs(u, e + l[i], i + 1)) return true;
        st[i] = false;
        
        // 排除等效冗余3，4
        if (!e || e + l[i] == len) return false;
        
        // 排除等效冗余2
        int j = i;
        while (j <= n && l[j] == l[i]) j++;
        i = j - 1;
    }
    
    return false;
}

int main ()
{
    while (cin >> n, n)
    {
        sum = 0, maxl = 0;
        
        for (int i = 1; i <= n; i++) 
        {
            cin >> l[i];
            maxl = max(maxl, l[i]);
            sum += l[i];
        }
        
        sort(l + 1, l + 1 + n);
        reverse(l + 1, l + 1 + n);
        
        primes.clear();
        get_primes(sum);
        
        int idx = 0;
        while (primes[idx] < maxl) idx++;
        
        for (int i = idx; i < primes.size(); i++)
        {
            len = primes[i];
            
            memset(st, 0, sizeof st);
            
            if (dfs(0, 0, 1)) 
            {
                cout << len << endl;
                break;
            }
        }
    }
    
    return 0;
} 
