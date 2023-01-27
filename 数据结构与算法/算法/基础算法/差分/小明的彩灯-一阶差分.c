/*
-------题目-------
小明拥有 N 个彩灯，第 i 个彩灯的初始亮度为 ai?。
小明将进行 Q 次操作，每次操作可选择一段区间，并使区间内彩灯的亮度 +x（x 可能为负数）。
求 Q 次操作后每个彩灯的亮度（若彩灯亮度为负数则输出 0）。
-------输入-------
第一行包含两个正整数 N，Q，分别表示彩灯的数量和操作的次数。
第二行包含 N 个整数，表示彩灯的初始亮度。
接下来 Q 行每行包含一个操作，格式如下：
l r x，表示将区间 l~r 的彩灯的亮度 +x。
1 ≤ N, Q ≤ 500000
0 ≤ ai ≤ 10^9 
1 ≤ l ≤ r ≤ N 
?10^9 ≤ x ≤ 10^9
-------输出-------
输出共 1 行，包含 N 个整数，表示每个彩灯的亮度。
*/
#include<stdio.h>
#define M 500010

long l, r, i, j;
long N, Q, x;
long a[M], b[M];   

int main ( int argc, char *argv[] ) 
{
    scanf( "%ld %ld", &N, &Q );
    for ( i = 1; i <= N; i++ ) {
        scanf( "%ld", &a[i] );
        b[i] = a[i] - a[i-1];    //b为差分数组
    }   
    for ( i = 0; i < Q; i++ ) {
        scanf( "%ld %ld %ld", &l, &r, &x );
        b[l] += x;
        b[r+1] -= x;
    }

    for ( i = 1; i <= N; i++ ) {
        a[i] = b[i] + a[i-1];
        if ( a[i] >= 0 ) 
            printf( "%ld ", a[i] );
        else
            printf( "0 " );
    }

    return 0;
}