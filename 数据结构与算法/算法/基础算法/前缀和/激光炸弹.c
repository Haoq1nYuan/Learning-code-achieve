/*
-------题目-------
一种新型的激光炸弹，可以摧毁一个边长为R的正方形内除边界上所有的目标，且爆破范围与x，y轴平行。
现在地图上有n个目标，用整数Xi，Yi表示目标在地图上的位置，每个目标都有一个价值。
-------输入-------
第一行为正整数n和正整数R，接下来的n行每行有3个正整数，分别为Xi，Yi，Vi。
-------输出-------
一个正整数表示最多能炸掉地图上总价值为多少的目标。
-------数据-------
1<=n<=10000, 0<=Xi,Yi<=5000, 1<=Vi<=100, 1<=R<=5000
*/

#include<stdio.h>
#define N 5002

int a[N][N], sum[N][N];
int n, R, i, j;
int x, y, v;
int S, result;

int main ( int argc, char *argv[] )
{
    scanf( "%d %d", &n, &R );
    for ( i = 0; i < n; i++ ) {
        scanf( "%d %d %d", &x, &y, &v );
        a[x+1][y+1] = v;
    }

    for ( i = 1; i < N; i++ ) {
        for ( j = 1; j < N; j++ ) 
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];  //维护矩阵中左上角(1,1)到右下角(i,j)的矩阵内目标的价值之和
    }

    for ( i = R; i < N; i++ ) {
        for ( j = R; j < N; j++ ) {
            S = sum[i][j] + sum[i-R][j-R] - sum[i][j-R] - sum[i-R][j];  //计算由(i,j)为右下角，边长为R的正方形内所有目标价值的和(不含边界)
            result =  result > S ? result : S ;
        }
    }

    printf( "%d\n", result );

    return 0;
}
