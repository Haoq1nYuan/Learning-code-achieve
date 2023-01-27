//https://www.acwing.com/problem/content/2/

//朴素闫氏分析法(暴力分析)
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, num, v[N], w[N];
int dp[N][N];  
//dp[i][j]表示从前i个物品中选，且总体积不超过j的所有方案的集合中总价值最大的情况
//dp数组的计算分为两类，一类是不选第i个物品，此时dp[i][j] = dp[i-1][j]。
//第二类是选第i个物品，此时就需要保证前面i-1个物品的价值最大，即dp[i-1][j-v[i]]最大，然后再加上不变的w[i]
//最终表示为：dp[i][j] = dp[i-1][j-v[i]] + w[i].

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &num );
    for ( int i = 1; i <= n; i++ )
        scanf( "%d%d", &v[i], &w[i] );

    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= num; j++ )
        {
            //不选第i个物品，代码在先，以便后面取两种情况的最大值
            dp[i][j] = dp[i-1][j];

            //选第i个物品，并取选或不选两种情况的最大值
            if ( j >= v[i] ) dp[i][j] = max( dp[i][j], dp[i-1][j-v[i]] + w[i] );
        }

    printf( "%d\n", dp[n][num] );
    
    return 0;
} 

//一维dp数组优化
//所有dp优化都是代码的等价替换
//代换思路
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, num, v[N], w[N];
int dp[N];  //滚动数组

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &num );
    for ( int i = 1; i <= n; i++ )
        scanf( "%d%d", &v[i], &w[i] );

    /*j需要从大到小遍历，因为省略掉的是dp[i-1][j-v[i]]，用到的是上一层的值
    当计算dp[j]的时候，j-v[i]肯定比j小，故而从大到小遍历能够保证第i层循环用到的一定是还未被更新过的数据，即前面一轮循环的数据，
    如果j从小到大遍历就有可能出现j下标相同的情况并覆盖掉第i-1层的正确值。
    比如：j = k 时 j - v[i] 恰好等于 j = n (n < k) 时的 j ,那么 j = n 时的max操作就相当于把第i-1层的 j = n 的情况覆盖掉了
    在 j = k 时计算用到的是第i层的值，则显然是错误的*/
    for ( int i = 1; i <= n; i++ )
        for ( int j = num; j >= 0; j-- )   
        {
            //dp[j] = dp[j];   //不选第i个物品的情况，可以省略
            //dp[i][j] = dp[i-1][j];

            if ( j >= v[i] )    //选第i个物品的情况
                dp[j] = max( dp[j], dp[j-v[i]] + w[i] );
                //dp[i][j] = max( dp[i][j], dp[i-1][j-v[i]] + w[i] );
        }

    return 0;
}

//代换结果
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, num, v[N], w[N];
int dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &num );
    for ( int i = 1; i <= n; i++ )
        scanf( "%d%d", &v[i], &w[i] );

    for ( int i = 1; i <= n; i++ )
        for ( int j = num; j >= v[i]; j-- )
            dp[j] = max( dp[j], dp[j-v[i]] + w[i] );
    
    printf( "%d\n", dp[num] );

    return 0;
}