//https://www.acwing.com/problem/content/1309/

/*
状态表示：dp[i] 表示第 i 个位置是牝牛的所有方案
状态计算：两只牝牛之间最少存在 k 只牡牛：
    dp[i] = dp[i - 1] + dp[i - 2] + … + dp[i - k - 1]
*/

#include <iostream>

using namespace std;

const int N = 100010, Mod = 5000011;

int n, k;
int f[N], s[N];

int main ()
{
    cin >> n >> k;
    
    //初状态：一只牝牛都不放也是一种方案
    f[0] = 1, s[0] = 1;
    for (int i = 1; i <= n; i++) 
    {
        //i- k - 1 可能是负数，即第一只牛到第 i 只牛之间牛顿数量还未到 k 只，此时也是一种方案
        f[i] = s[max(i - k - 1, 0)];
        s[i] = (f[i] + s[i- 1]) % Mod;
    }
    
    cout << s[n] << endl;
    
    return 0;
}