//https://www.acwing.com/problem/content/1228/

//注意这里的状态表示：能凑成表示为true，不能凑成表示为false，且转移过程只需要用或运算即可

//对于不能凑出的数目是无限的情况：当所有笼子的最大公约数为 k != 1 时，只有 k 的倍数才能被凑出，其他所有数都是不能被凑出的
//而对于不能凑出的数目是有限的情况：根据裴蜀定理，扩展到有限个数的gcd，满足 a * x1 + b * x2 + …… + n * xn = (a, b, … , n) = 1
//我们将等式整体扩大 p 倍，那么就可以凑出任何一个数，当然其中某些 x 是负数
//不过没有关系，假设 x1 < 0 且 x2 > 0，那么我们变形：a * (b + x1) + b * (x2 - a) + ……
//必然存在某个系数 k 满足 k + x1 > 0，也必然存在某个 t 满足 x2 - t > 0

//对于本题不能凑出的数是有限个的情况，我们只需要找到一个不能凑出来的最大上界即可
//而对于多个数的裴蜀定理衍生上界，没有明确的证明，不过我们知道任意两对数的上界必定大于所有数的共同上界
//所以直接用小于数据范围的最大的两个数的上界当作所有数的即可
#include <iostream>

using namespace std;

const int N = 10010;

int n;
int v[110];
bool dp[N];

int gcd (int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main ()
{
    cin >> n;
    int d;
    for (int i = 1; i <= n; i++) 
    {
        cin >> v[i];
        if (i == 1) d = v[1];
        else d = gcd(d, v[i]);
    }
    
    if (d != 1)
    {
        puts("INF");
        return 0;
    }
    
    dp[0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j < N; j++)
            dp[j] |= dp[j - v[i]];
    
    int res = 0;
    for (int i = 0; i < N; i++)
        if (!dp[i]) res ++;
        
    cout << res << endl;
    
    return 0;
}