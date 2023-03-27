//https://www.acwing.com/problem/content/1216/

/*
由于这道题不同方案之间是通过数列中第一个元素x决定的，所以就需要推导x的公式
公式推导：
1.我们令d要么为-a要么为+b，所以数列就可以表示为x,x+b1,x+b1+b2,……,x+b1+b2+……+bn-1.
  得到：x = ( s - (n-1)b1 - (n-2)b2 - …… - bn-1 ) / n.
2.由于数列是整数数列，则 ( s - (n-1)b1 - (n-2)b2 - …… - bn-1 ) % n == 0，
  即 ( (n-1)b1 + (n-2)b2 + …… + bn-1 ) mod n 与 s mod n 结果相同 -> 组合问题 -> 类背包问题

状态表示：
集合含义：对于dp[i][j]，所有只考虑前i项(最多为n-1项，因为减去了第一项x)，且前i项多项式 ( (n-1)b1 + (n-2)b2 + …… + (n-i)bi ) mod n = j 的方案的集合

状态计算：
划分集合：
1.最后一项bi是+a的所有方案
2.最后一项bi是-b的所有方案
*/

#include<stdio.h>
#define N 1010
#define mod 100000007  

int n, s, a, b;
int dp[N][N];

int get_mod ( int a, int b )
{   
    return ( a % b + b ) % b;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d%d%d", &n ,&s, &a, &b );

    dp[0][0] = 1;
    for ( int i = 1; i < n; i++ )
        for ( int j = 0; j < n; j++ )   //任何数模上n结果一定<n
            dp[i][j] = ( dp[i-1][get_mod(j - a * (n - i), n)] + dp[i-1][get_mod(j + b * (n - i), n)] ) % mod;

    printf( "%d\n", dp[n-1][get_mod(s, n)] );

    return 0;
}