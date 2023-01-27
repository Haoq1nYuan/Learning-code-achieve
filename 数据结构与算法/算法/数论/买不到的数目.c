//https://www.acwing.com/problem/content/1207/

//会出现无解的情况，如果说a和b的最大公约数大于1，则只能凑成偶数，奇数都不行，但本题规定不会出现无解的情况

//首先打表暴搜（找规律）
#include<stdio.h>

int n, m, res;

int dfs ( int i, int n, int m )   //判断一个数是否能被n和m分配出来
{
    if ( !i ) return 1;

    //我们不知道在某处应该减n还是减m，所以就都列举一遍，先后顺序没有要求
    if ( i >= m && dfs( i-m, n, m ) ) return 1;
    if ( i >= n && dfs( i-n, n, m ) ) return 1;   
    
    return 0;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );

    for ( int i = 1; i <= 1000; i++ )   //就枚举到1000，1000之前有解就好，没有解也认定1000之后都能凑配出来
    {                                    
        if (!dfs( i, n, m )) res = i;   //此处表示1~1000中不能被分配的数
    }

    printf( "%d\n", res );

    return 0;
}
/*
3 2:1
3 4:5
3 5:7
3 7:11
3 8:13
发现：m每+1，res就+2 -> 看成线性方程：m = 2*n + x，解得 x = -3.
推出：当 n = 3 时，res = 2*m - 3 = 2*(m-1) - 1.
而当n变化时，m的系数就会相应改变，故可以猜测 res = (n-1)*(m-1) - 1.
这是一个结论，证明参考https://www.acwing.com/solution/content/3165/
*/

//最终做法
/* 
#include<stdio.h>

int n, m;

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );

    printf( "%d\n", (n-1) * (m-1) - 1 );

    return 0;
} 
 */