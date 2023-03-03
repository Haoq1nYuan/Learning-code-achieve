//https://www.acwing.com/problem/content/895/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;
const int N = 110, M = 10010;

int n, k;
//s数组存取拿取数
//f数组存储每张图的SG值
int s[N], f[M];

int sg (int x)
{
    //记忆化搜索
    if (f[x] != -1) return f[x];
    
    //set容器自动排序，且每个图的set容器各不相同
    set<int> S;
    for (int i = 0; i < k; i++)
    {
        int sum = s[i];
        //先不断递归到图的终点，再往前回溯
        if (x >= sum) S.insert(sg(x - sum));
    }
    
    //从小到大循环，在每一层递归中都可以找出集合中不存在的最小数
    for (int i = 0;; i++)
        if (!S.count(i)) 
        {
            f[x] = i;
            return f[x];
        }
}

int main ()
{
    cin >> k;
    for (int i = 0; i < k; i++) scanf("%d", &s[i]);
    cin >> n;
    
    memset(f, -1, sizeof(f));
    
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }
    
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}