//https://www.acwing.com/problem/content/5/

//多重背包dp：每种物品有数量限制
/*
状态分析：dp[i][j]表示所有满足“只在前i个物品中选，总价值不超过j”的方案的物品总价值的集合，属性是max
状态划分：
    1.第i个物品选0个
    2.第i个物品选1个
    …………
    n.第i个物品选n-1个
*/
//朴素写法---TLE
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 105

int n, V, s[N], v[N], w[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    for ( int i = 1; i <= n; i++ ) 
        scanf( "%d%d%d", &v[i], &w[i], &s[i] );

    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= V; j++ )
            for ( int k = 0; k*v[i] <= j && k <= s[i]; k++ )
                dp[i][j] = max( dp[i][j], dp[i-1][j-k*v[i]] + k*w[i] );

    printf( "%d\n", dp[n][V] );

    return 0;
}

//二维转一维优化---TLE
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, s, v, w;
int dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );

    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d%d%d", &v, &w, &s );
        for ( int j = V; j >= 0; j-- )
            for ( int k = 0; k*v <= j && k <= s; k++ )
                dp[j] = max( dp[j], dp[j-k*v] + k*w );
    }

    printf( "%d\n", dp[V] );

    return 0;
}

//二次幂分组+二维转一维优化
/*
注意：
    多重背包问题无法用完全背包问题对于k循环的优化方式进行优化,
    因为每一种物品的数量不同，将k全部展开之后最后一项不同，无法整体代换
优化方法：
    1.举例；
        1.假设某种物品共有1023个.
        2.打包成10组：1,2,4,8,……,512，将这10组看成10个新物品，每个物品只能用一次
    2.方法：一种物品有s个，先按照2的整次幂分组：1,2,4,……,2^k,c  ( 2^k <= s, 0 <= c < s - 2^k )
           然后将这些物品拿取数量按照上面的分组打包成另外((int)logk)+1个物品，最后多出来的要补全
           同时需要拷贝每组物品的总体积和总价值。然后用这((int)logk)+1个物品做一遍01背包问题即可
*/
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define M 25000  //原先最多有1000个物品，每个物品最多要分成 ((int)log2000)+1 件新物品，所以新开的数组大小要大于1000*(((int)log2000)+1)

int n, V, v[M], w[M], count;  //v和w分别储存打包出来的新物品的体积和价值,count记录新物品数量
int dp[M];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );

    for ( int i = 1; i <= n; i++ )   //原先的每种物品都要重新分成新的物品，这些新物品各不相同，且都只有一个
    {
        int a, b, s;   //a表示每种物品的价值，b表示每种物品的体积，s表示每种物品的数量
        scanf( "%d%d%d", &a, &b, &s );
        int k = 1;   //k每次存储过后*2，划定分组界限
        //其实就是将所有处在[k,k*2)之间的所有拿取数打包起来看成一种新的物品，
        //因为每种原物品只可能有一种取法，所以只需要将这种取法大致划在某一区间内
        while ( k <= s )
        {
            count++;
            v[count] = a*k;     
            w[count] = b*k;
            s -= k;
            k *= 2;
        }
        //如果没有分干净，则将剩下的分成1组
        if ( s )  
        {
            count++;
            v[count] = a*s;
            w[count] = b*s;
        }
    }

    n = count; //更新物品种类
    //01背包一维优化模板
    for ( int i = 1; i <= n; i++ )
        for ( int j = V; j >= v[i]; j-- )
            dp[j] = max( dp[j], dp[j-v[i]] + w[i] );

    printf( "%d\n", dp[V] );

    return 0;
}