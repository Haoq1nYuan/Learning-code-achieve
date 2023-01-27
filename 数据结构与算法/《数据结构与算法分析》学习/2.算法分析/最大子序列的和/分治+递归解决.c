//此方法时间复杂度为O( N*logN ) > O( N )
#include<stdio.h>

#define N 10000

int a[N];

int Max ( int a, int b, int c )
{
    int result;
    if ( a > b ) {
        result = a;
    }
    if ( result < c ) {
        result = c;
    }
    return result;
}

int MaxSubSum ( const int *a, int left, int right )
{
    int MaxLeftSum, MaxRightSum;  //左右半块不包含中心边界的最大子序列和
    int MaxLeftBorderSum = 0, MaxRightBorderSum = 0;  //左右半块数据中包含中心边界的最大子序列和
    int LeftBorderSum, RightBorderSum;  //中间计算量
    int center, i;

    if ( left == right ) {
        if ( a[left] > 0 ) {
            return a[left];
        } else {
            return 0;
        }
    }

    center = ( left + right )/2;
    MaxLeftSum = MaxSubSum( a, left, center );
    MaxRightSum = MaxSubSum( a, center + 1, right );

    for ( i = center; i>=left; i-- ) {
        LeftBorderSum += a[i];
        if ( MaxLeftBorderSum < LeftBorderSum ) {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }

    for ( i = center + 1; i<=right; i++ ) {
        RightBorderSum += a[i];
        if ( MaxRightBorderSum < RightBorderSum ) {
            MaxRightBorderSum = RightBorderSum;
        }
    }

    return Max( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int main ( int argc, char *argv[] )
{
    int result, num, leftborder, rightborder, i = 0;

    scanf( "%d %d", &leftborder, &rightborder );
    scanf( "%d", &num );
    while ( num != 0 ) {
        a[i++] = num;
        scanf( "%d", &num );
    } 

    result = MaxSubSum( a, leftborder, rightborder );
    printf( "%d\n", result );
    return 0;
}