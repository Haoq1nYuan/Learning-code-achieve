//https://www.acwing.com/problem/content/1024/

/*
本题需要注意一点，就是第二维的费用——伤害量总和不能大于等于皮卡丘的体力。
因此第二维的最大值就是 m - 1
*/

#include <iostream>

using namespace std;

const int N = 1010;

int n, m, k;
int c, h;
int f[N][N];

int main ()
{
    cin >> n >> m >> k;
    
    for (int i = 1; i <= k; i++)
    {
        cin >> c >> h;
        
        for (int j = n; j >= c; j--)
            for (int k = m - 1; k >= h; k--)
                f[j][k] = max(f[j][k], f[j - c][k - h] + 1);
    }
    
    cout << f[n][m - 1] << ' ';
    
    /*
    对于第二问：收服最多小精灵时剩余的最大体力值为多少？

    */
    int cnt = m - 1;  //初始赋值，避免 m = 1 的情况出现
    for (int i = m - 2; i >= 0; i--)  //注意，第二维可以是0，代表不收服任何精灵的情况
        if (f[n][i] == f[n][m - 1]) cnt = i;
    
    cout << m - cnt << endl;
    
    return 0;
}