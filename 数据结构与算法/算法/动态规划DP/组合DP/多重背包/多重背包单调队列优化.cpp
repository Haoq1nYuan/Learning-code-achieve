//https://www.acwing.com/problem/content/6/

//单调队列优化
/*
单调队列中存储的值和它实际表示的值可以是数组下标和数组元素的关系，
也可以是一种x和y的函数关系，比如多重背包问题。
当然，你需要找到每次入队的值a和它实际表示的值f(a)之间的函数或数组关系，
并且根据这种关系得到f(a)，并和f(q[t])比较，结合你之前得出的单调趋势加以判断。
*/
/*
1.首先，需要将二维转化为一维问题：
dp[i][j] = max( dp[i-1][j], dp[i-1][j-v] + w, ………… , dp[i-1][j-k*v] + k*w );
变为：dp[j] = max( dp[j], dp[j-v] + w, ………… , dp[j-k*v] + k*w );

2.得到dp数组的取max规则
此时的j是最大总体积，对于每一种物品，满足：j = k*v + n. 
v是总体积，k是如果只取该物品那么该物品能够取得的最大数量，n是去完之后还剩下的体积
所以，有：dp[k*v + n] = max( dp[k*v + n], dp[(k-1)*v + n] + w, ………… , dp[v + n] + (k-1)*w, dp[n] + k*w ); 
此时 0 <= n < v，我们利用上式的结果还原一遍：
dp[n] = dp[n];                                          
dp[n+v] = max( dp[n] + w, dp[n+v] );                     //dp[n] 和 dp[n+v] 相差 1 个 w
dp[n+2*v] = max( dp[n] + 2*w, dp[n+v] + w, dp[n+2*v] );  //dp[n] 和 dp[n+2*v] 相差 2 个 w
………………
并且我们知道，对于每个物品，数量是有限的(假设数量最多为s)，也就是说 k = s，当n不断加上单个物品体积后，最大不能超过 n + s*v
这就让我们看到了滑动窗口的影子，维护一个长度为s的单调递减队列，队列q存储总体积，即 n + m*v. ( 0 <= m < s )
q[h]可能是小于 n + m*v 的任意一个值，dp[q[h]]和dp[k]相差 k - q[h] 个 w.

3.得到f(a)，便于入队判定
为了得到窗口每一次移动新出现的量，我们这样写：
dp[n] = dp[n];
dp[n+v] = max( dp[n], dp[n+v] - w ) + w;
dp[n+2*v] = max( dp[n], dp[n+v] - w, dp[n+2*v] - 2*w ) + 2*w;  
dp[n+3*v] = max( dp[n], dp[n+v] - w, dp[n+2*v] - 2*w, dp[n+3*v] - 3*w ) + 3*w;
………………
每次新出现的值就是dp[n+m*v] - m*w，便于和 dp[q[t]] - (q[t] - j)/v * w 比较，
队列每个值也就表示 dp[q[n + m*v]] - (q[n + m*v] - n)/v * w. 
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 20010;

//tem拷贝上一个物品计算过后的所有dp值
int q[N], dp[N], tem[N];   
int n, m, v, w, s;

int main ()
{
    cin >> n >> m;

    for ( int i = 0; i < n; i++ )
    {
        memcpy(tem, dp, sizeof(dp));
        cin >> v >> w >> s;
        for ( int j = 0; j < v; j++ )
        {
            int h = 0, t = -1;
            for ( int k = j; k <= m; k += v )
            {
                if ( h <= t && k - s*v > q[h] ) h++;

                while ( h <= t && tem[q[t]] + (q[t])/v * w <= tem[k] - (k - j)/v * w ) t--;

                if ( h <= t ) dp[k] = max( tem[k], tem[q[h]] + (k - q[h])/v * w );

                q[++t] = k;
            }
        }
    }

    cout << dp[m] << endl;

    return 0;
}