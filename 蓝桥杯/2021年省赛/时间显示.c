//https://www.acwing.com/problem/content/3419/

#include<stdio.h>
#define N 3600
#define M (3600*24)  //86400
#define K (3600*24*24)  //2073600

long long n;
int hour, min, sec;

int main ( int argc, char *argv[] )
{
    while (scanf( "%lld", &n ) != EOF)
    {
        int hour = 0, min = 0, sec = 0;
        n /= 1000;

        if ( n >= K ) n -= (n/K) * K;
        if ( n >= M ) n -= (n/M) * M;
        if ( n >= N )     
        { 
            hour += n/N;
            n -= n/N * N;
        }
        if ( n >= 60 )
        {
            min += n/60;
            n -= n/60 *60;
        }
        sec += n;

        if ( hour > 9 ) printf( "%d:", hour );
        else printf( "0%d:", hour );

        if ( min > 9 ) printf( "%d:", min );
        else printf( "0%d:", min );

        if ( sec > 9 ) printf( "%d\n", sec );
        else printf( "0%d\n", sec );    
    }

    return 0;
}