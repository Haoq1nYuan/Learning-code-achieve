// https://www.acwing.com/problem/content/1083/

/*
    本题由2-10进制组成，数位的划分根据具体进制来决定。
    如：B=3时，X或Y划分成3的若干次幂P=(p1, p2, ……)之和，P中的各个次幂就是候选项，与组合数关联。
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 35;

int n, x, y, k, b;
int c[N][N];        // 存放组合数
vector<int> nums;

void init ()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
}

int DP (int u)
{
    if (!u) return 0;
    
    nums.clear();
    while (u) 
    {
        nums.push_back(u % b);   
        u /= b;
    }
    /* 
        num中存储的数值表示：
        k = 3, u = 35时，u的三进制表示为：1022 -> 1(3^3), 0(3^2), 2(3^1), 2(3^0)
        1022分别表示对应次幂的出现次数，即: 35 = 1 * 3^3 + 0 * 3^2 + 2 * 3^1 + 2 * 3^0 
    */
    
    int ans = 0;
    int last = 0;   // 表示前面数位已经用掉了几位
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];   // 得到当前次幂出现的次数
        if (x)  // 当前次幂可供选择
        {
            ans += c[i][k - last];   // 不选择当前次幂
            if (x > 1)   // 选择当前次幂，直接可以得到之后的所有方案
            {
                if (k - last - 1 >= 0) ans += c[i][k - last - 1];
                break;
            }
            else 
            {
                last ++;
                if (last > k) break;
            }
        }
        
        if (!i && last == k) ans ++;    // 最右侧分支上的方案
    }
    
    return ans;
}

int main ()
{
    init();
    
    cin >> x >> y >> k >> b;
    
    int ans_x = DP(x - 1);
    int ans_y = DP(y);
    
    cout << abs(ans_x - ans_y) << endl;
    
    return 0;
} 