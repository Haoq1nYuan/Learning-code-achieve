//https://www.acwing.com/problem/content/4656/

//数位和小的在前，数位和相等时数值小的在前

//C语言限制，排序无法做到很好的优化，过50%数据
/* #include<stdio.h>
#define N 1000010

long n, m;
long sum[N], w[N];

int main ( int argc, char *argv[] )
{   
    scanf( "%ld", &n );
    getchar();
    scanf( "%ld", &m );
    getchar();

    for ( long i = 1; i <= n; i++ )
    {
        w[i] = i;
        long box = i;
        while ( box )
        {
            sum[i] += box % 10;
            box /= 10;
        } 
    }

    for ( int i = 1; i < n; i++ )   
        for ( int j = i + 1; j <= n; j++ )
        {
            if ( sum[i] > sum[j] )
            {
                long box = sum[i];
                sum[i] = sum[j];
                sum[j] = box;
                box = w[i];
                w[i] = w[j];
                w[j] = box;
            }
            if ( sum[i] == sum[j] && w[i] > w[j] )
            {
                long box = sum[i];
                sum[i] = sum[j];
                sum[j] = box;
                box = w[i];
                w[i] = w[j];
                w[j] = box;
            }
        }

    printf( "%ld\n", w[m] );

    return 0;
} */

//单链表优化(类似于哈希表)
#include<stdio.h>
#include<string.h>
#define N 1000010

int head[N], e[N], ne[N], idx;   //此处的head[N]表示一个存放所有链表第一个节点下标的数组
int num[N], count;
int n, m;

//每一个数位和（key）都代表着一个链表，
//并且是以原数值（value）从大到小的顺序存入的，所以在遍历的时候原数值小的先遍历。
void add ( int key, int value )   
{
    e[idx] = value;
    ne[idx] = head[key];
    head[key] = idx;
    idx++;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );
    memset( h, -1, sizeof(h) );  //初始化所有的头节点指向

    //此处循环的方式就决定了每个数位和对应的链表中从第一个节点开始原数值从小到大排列的顺序
    for ( int i = n; i >= 1; i-- )  
    {
        int box = i;
        int sum = 0;   //sum表示数i的位数和
        while ( box )
        {
            sum += box % 10;
            box /= 10;
        }
        add( sum, i );
    }

    for ( int i = 1; i <= n; i++ )   //遍历数位和
        for ( int j = head[i]; j != -1; j = ne[j] )  //遍历每个链表中的节点
            num[++count] = e[j];

    printf( "%d\n", num[m] );

    return 0;
}