//https://www.acwing.com/problem/content/94/

//何为指数型枚举？这题要求一个从n个数中选择1~n个数的选法的和，
//即选择排列，Cn1 + Cn2 + …… + Cnn = 2^n，为指数型

//以下均为头递归解法

//递归结束后集中输出结果
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 32800     

int judge[16], n, i, j, k;   //judge(状态)的值为0表示还没考虑，为1表示选，为2表示不选

struct guide           //定义一个结构体以存储最后结果
{
    int number[16];    //number数组存储每一位上的非0数字
    int count;         //count记录这些数字的数量，方便最后输出
} G[N];

void ans ( int u )
{
    if ( u > n ) {
        k++;
        for ( i = 1; i <= n; i++ ) 
            if ( judge[i] == 1 ) 
                G[k].number[++G[k].count] = i;
        return;
    }

    judge[u] = 2;   //第u位：不选
    ans( u + 1 );
    //judge[u] = 0;   //恢复现场       //如果该节点只有一个儿子，则可以省略恢复现场的操作
                                      //如果有多个儿子，有些变量需要恢复(一般是一些判断条件所涉及的变量)，有些不用
    judge[u] = 1;   //第u位：选
    ans( u + 1 );
    //judge[u] = 0;   //恢复现场

    //return;    //运行到这里自动回溯到上一层递归中去，无需return
}

int main ( int argc, char *argv[] ) 
{   
    scanf( "%d", &n );

    for ( i = 1; i <= n; i++ ) {
        G[i].count = 0;
        memset( G[i].number, 0, sizeof( G[i].number ) );
    }
    
    ans(1);

    for ( j = 1; j <= k; j++ ) {
        for ( i = 1; i <= G[j].count; i++ ) 
            printf( "%d ", G[j].number[i] );
        printf( "\n" );
    }

    return 0;
}

//在递归过程中输出
#include<stdio.h>

int judge[20], n, i;   //judge的值为0表示还没考虑，为1表示选，为2表示不选

void ans ( int u )
{
    if ( u > n ) 
    {
        for ( i = 1; i <= n; i++ ) 
            if ( judge[i] == 1 ) 
                printf( "%d ", i );
        printf( "\n" );
        return;
    }

    judge[u] = 2;
    ans( u + 1 );
    //judge[u] = 0;

    judge[u] = 1;
    ans( u + 1 );
    //judge[u] = 0;

    //return;
}

int main ( int argc, char *argv[] ) 
{   
    scanf( "%d", &n );

    ans(1);

    return 0;
}