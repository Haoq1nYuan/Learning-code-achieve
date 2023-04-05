//https://www.acwing.com/problem/content/description/1091/

//单调队列优化dp
/*
状态表示：dp[i]表示点亮第i个烽火台后前面所有点亮的烽火台代价之和
状态转移：dp[i] = min{dp[i - 1], dp[i - 2], …… , dp[i - m]} + a[i];

单调队列队头存储当前范围内dp的最小值
*/

#include <iostream>
  
using namespace std;

const int N = 200010;

int n, m, a[N];
int q[N], t, h;
int f[N];

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        if (t >= h && i - m > q[h]) h++;
        
        f[i] = f[q[h]] + a[i];
        
        while (h <= t && f[q[t]] >= f[i]) t--;
        
        q[++t] = i;
    }
    
    int ans = 0x3f3f3f3f;
    //从最后 m 个烽火台中选择代价和最小的那个更新答案
    for (int i = n - m + 1; i <= n; i++) ans = min(ans, f[i]);
    
    cout << ans << endl;
    
    return 0;
}