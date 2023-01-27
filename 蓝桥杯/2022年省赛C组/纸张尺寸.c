//https://www.acwing.com/problem/content/4655/

//普通做法
/* #include<stdio.h>

int num, size[11][3];
char name;

int main ( int argc, char *argv[] )
{
    scanf( "%c%d", &name, &num );

    size[0][0] = 1189;
    size[0][1] = 841;
    for ( int i = 1; i <= num; i++ ) 
    {
        size[i][0] = size[i-1][1];
        size[i][1] = size[i-1][0] / 2;
    }

    printf( "%d\n", size[num][0] );
    printf( "%d\n", size[num][1] );

    return 0;
} */

//滚动数组优化
#include<stdio.h>

int num, x, y;
char name;

int main ( int argc, char *argv[] )
{
    scanf( "%c%d", &name, &num );

    x = 1189;
    y = 841;
    for ( int i = 1; i <= num; i++ ) 
    {
        int box = x;
        x = y;
        y = box / 2;
    }

    printf( "%d\n", x );
    printf( "%d\n", y );

    return 0;
}
