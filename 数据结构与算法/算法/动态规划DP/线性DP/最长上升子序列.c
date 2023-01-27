//https://www.acwing.com/problem/content/898/

//序列模型---一维dp
//注意：子序列 != 连续序列
/*
集合的含义：
    dp[i]表示以a[i]为最后一个元素的所有上升子序列长度的集合，属性为max.
集合划分：
    将集合按照倒数第二个元素划分（因为第一个元素一定是i，集合中的所有元素没有最后一个不同点）
    倒数第二个元素有0(表示长度为1，只有a[i]),a[1],a[2],a[3]……a[k]……a[i-1]（不重不漏）
    所以以i为末尾的长度为p+1的上升子序列可以表示为：a[1],a[3]……a[p],a[i]
    a[p]前面的所有元素可以任意变化，但是a[p]和a[i]是确定的，而a[p]及其前面这一段任意序列又可以看成dp[p]，
    所以dp[i] = dp[p] + 1.
*/
//朴素写法
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 100010

int n, ans, a[N], dp[N]; 

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );
    for ( int i = 1; i <= n; i++ )
        scanf( "%d", &a[i] );

    for ( int i = 1; i <= n; i++ )
    {
        dp[i] = 1;   //表示只有a[i]一个元素的序列情况                     
        for ( int j = 1; j <= i-1; j++ ) 
            if ( a[i] > a[j] )   //保证子序列中倒数第二个元素<a[i]
                dp[i] = max( dp[i], dp[j] + 1 );   

        ans = max( ans, dp[i] );
    }

    printf( "%d\n", ans );

    return 0;
}

//优化
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 100010

int n, a[N], ans;
int dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );
    for ( int i = 1; i <= n; i++ )
        scanf( "%d", &a[i] );

    


    return 0;
}