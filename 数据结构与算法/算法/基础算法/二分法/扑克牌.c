/*
-------题目-------
你有n种牌，第i种牌的数目为ci。另外有一种特殊的牌：joker，它的数目是m。
你可以用每种牌各一张来组成一套牌，也可以用一张joker和除了某一种牌以外的其他牌各一张组成1套牌。
比如，当n=3时，一共有4种合法的套牌：{1,2,3}, {J,2,3}, {1,J,3}, {1,2,J}。 
给出n, m和ci，你的任务是组成尽量多的套牌。每张牌最多只能用在一副套牌里（可以有牌不使用）。
-------输入-------
第一行包含两个整数n, m，即牌的种数和joker的个数。
第二行包含n个整数ci，即每种牌的张数。
-------输出-------
输出仅一个整数，即最多组成的套牌数目。
-------数据-------
2 <= n <= 50
0 <= m, ci <= 500,000,000
*/
#include<stdio.h>

int n, i;
long m, c[55]; 
long mid, right, left;

int check ( long mid )
{
    long sum = 0;
    for ( i = 1; i <= n; i++ ) {
        if ( c[i] < mid ) {
            sum += mid - c[i];
        }
    }
    if ( sum > m || mid < sum ) {
        return 0;
    } else {
        return 1;
    }
}

int main ( int argc, char *argv[] )
{   
    scanf( "%d %ld", &n, &m );
    for ( i = 1; i <= n; i++ ) {
        scanf( "%ld", &c[i] );
        right += c[i];   //最多方案数
    }
       
    left = 0;            //最少方案数
    while ( left < right ) {
        mid = ( right + left + 1 ) / 2;
        if ( check( mid ) ) {
            left = mid;                         
        } else {
            right = mid - 1;
        }
    }

    printf( "%ld\n", right );   //输出left也行

    return 0;
}