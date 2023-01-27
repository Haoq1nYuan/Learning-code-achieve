//https://www.acwing.com/problem/content/1232/

//直接套模板会超时
/*
#include<stdio.h>

long n, k, a[100010], count, i, j;

int main ( int argc, char *argv[] )
{
    scanf( "%ld%ld", &n, &k );
    for ( i = 1; i <= n; i++ ) {
        scanf( "%ld", &a[i] );
        a[i] += a[i-1];
    }

    for ( i = 1; i <= n; i++ ) 
        for ( j = i; j <= n; j++ ) 
            if ( (a[j]-a[i-1]) % k == 0 ) 
                count++;

    printf( "%ld\n", count );

    return 0;
}
*/

//标答
//新建一个数组，下标存储每个前缀和与k的模
#include<stdio.h>

long a[100010];
long n, k, i;
long ans[100010];

int main ( int argc, char *argv[] ) 
{
    scanf( "%ld %ld", &n, &k );
    for ( i = 1; i <= n; i++ ) {
        scanf( "%ld", &a[i] );
        a[i] += a[i-1];
    }

    ans[0]++;   
    //此处需要事先把余数为0的情况设为1，
    //因为如果余数为0就说明该前缀和自身就是一个k倍区间，无需再找另外的端点.
    long count = 0;
    for ( i = 1; i <= n; i++ ) {
        count += ans[ a[i] % k ];
        ans[ a[i] % k ]++;
    }

    printf( "%ld\n", count );

    return 0;
}

