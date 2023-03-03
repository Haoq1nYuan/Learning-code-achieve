//https://www.acwing.com/problem/content/340/

//数位统计DP
/*
状态表示：dp[i][j][u]表示所有满足有i位，最高位是j的数的方案拥有u的个数的集合，属性是count
状态划分：
    1.当第j位不为u：dp[i][j][u] += dp[i][k][u];  //k表示第j-1位的数
    2.当第j位为u：dp[i][j][k] += dp[i-1][k][u] + 
*/
#include<stdio.h>

int a, b;
int dp[];

int main ( int argc, char *argv[] )
{
    
    while ( scanf( "%d%d", &a, &b ), a ) 
    {
        if ( a > b ) 
        {
            int box = a;
            a = b; 
            b = box;
        }

        for ( int i = 0; i < 10; i++ )

        for ( int i = 0; i < 10; i++ ) printf( "%d ", dp[][] );
        printf( "\n" );
    }


    return 0;
}