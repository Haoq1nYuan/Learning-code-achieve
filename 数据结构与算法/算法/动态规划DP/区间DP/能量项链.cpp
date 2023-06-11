//https://www.acwing.com/problem/content/322/

#include <iostream>

using namespace std;

const int N = 205;

int n, m[N];
int dp[N][N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> m[i];
        m[i + n] = m[i];
    }
    
    //本题将数列扩增一倍，但是始终限制最大长度为n + 1，这就保证了不会重复计算已经合并的点
    //相当于一个滑动窗口，无形中就把第n个珠子和第一个珠子的所有合并时机都包含进去了
    for (int num = 3; num <= n + 1; num++) //num表示珠子数+1，即除去相同的所有头标记和尾标记
        for (int i = 1; i + num - 1 <= n * 2; i++)
        {
            int j = i + num - 1;
            dp[i][j] = 0;  //计算max的初始化
            
            for (int k = i + 1; k < j; k++) 
                dp[i][j] = max(dp[i][j], dp[i][k] + m[k] * m[i] * m[j] + dp[k][j]);
        }   
    
    //将所有窗口中所有全域情况娶个最大值
    int res = 0;
    for (int l = 1; l <= n; l++) res = max(res, dp[l][l + n]);
    
    cout << res << endl;
    
    return 0;
}