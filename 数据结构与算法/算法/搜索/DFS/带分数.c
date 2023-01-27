//https://www.acwing.com/problem/content/1211/

//找出递归的影子：即打乱的数字顺序->全排列

//暴力：先枚举全排列，再枚举位数，最后判断等式是否成立(无法剪枝)---8574ms
/* #include<stdio.h>
#include<math.h>

long n, box, result;
double a, b, c;
long long state[10];
int used[10], length;

long carryout ( long long *num )
{
    long count = 0;
    for ( int i = 1; i <= 6; i++ )     //此处i最大为6，因为正整数最大为999999，拆分成带分数后整数位肯定小于999999
    {
        for ( int j = i+1; j <= 8; j++ )
        {
            a = num[i];
            b = num[j] - num[i]*pow(10.0, j-i);
            c = num[9] - num[j]*pow(10.0, 9-j);
            if ( a + b / c == n*1.0 ) count++;
        }
    }
    return count;
}

void ans ( int u )
{
    if ( u > 9 ) 
    {
        result += carryout(state);
        return;
    }

    for ( int i = 1; i <= 9; i++ ) 
    {
        if ( !used[i] )
        {
            used[i] = 1;
            state[u] = i;
            state[u] += state[u-1]*10;
            ans( u+1 );
            used[i] = 0;
        }
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%ld", &n );
    box = n;
    length = 0;
    while ( box ) 
    {
        box /= 10;
        length++;
    }

    ans(1);

    printf( "%ld\n", result );

    return 0;
} */

//先枚举a，再枚举c，最后判断b是否成立+剪枝---1081ms
//使剪枝的可能尽可能多，需要首先分析哪一步剪枝的情况多
#include<stdio.h>

long n;
int used[10], tem[10];
long result;

int check (long a, long c)
{
    long b = n * c - a * c;     //此处通过题目条件反推到b的值，之后再去判断b是否满足题设条件即可。

    //拷贝一个判重数组，不影响其他分支的进行
    int j = 1;
    while ( j < 10 ) 
    {
        tem[j] = used[j];
        j++;
    }

    //判断b的每一位是不是都不为0，并且判断每一位是否被用过
    int x;
    do {       
        x = b % 10;
        b /= 10;
        if ( !x || tem[x] ) return 0;
        tem[x] = 1;
    } while ( b );

    //判断1~9这9个数字是否都被使用
    for ( int i = 1; i <= 9; i++ ) 
        if ( !tem[i] ) 
            return 0;

    //如果以上检验都通过，则说明b满足题意，a, b, c是一个解  
    return 1;

}

void dfs_c ( int u, long a, long c )
{
    if ( u == 9 ) return;     //这个条件是必要的，这样在check函数中就不会出现爆long的情况。

    if ( check( a, c ) ) result++;

    for ( int i = 1; i <= 9; i++ ) 
    {
        if ( !used[i] )
        {
            used[i] = 1;
            dfs_c( u + 1, a, c * 10 + i );
            used[i] = 0;
        }
    }

}

void dfs_a ( int u, long a )
{
    if ( a > n ) return;    //此处剪枝,因为a一定不大于n

    if ( a ) dfs_c( u, a, 0 ); 

    for ( int i = 1; i <= 9; i++ ) 
    {
        if ( !used[i] )  
        {
            used[i] = 1;
            dfs_a( u + 1, a * 10 + i );
            used[i] = 0;
        }
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%ld", &n );

    dfs_a( 0, 0 );

    printf( "%ld\n", result );

    return 0;
}