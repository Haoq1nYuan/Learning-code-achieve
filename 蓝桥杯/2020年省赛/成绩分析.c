#include<stdio.h>

#define N 10000

int score[N];

int main ( int argc, char *argv[] )
{
    int n, i, sum = 0, max = 0, min = 100;
    double ave = 0;
    scanf( "%d", &n );
    i = 0;
    while ( n-- ) {
        scanf( "%d", &score[i] );
        sum += score[i];
        if ( max < score[i] ) {
            max = score[i];
        }
        if ( min > score[i] ) {
            min = score[i];
        }
        i++;
    }
    ave = 1.0*sum/i;
    printf( "%d\n", max );
    printf( "%d\n", min );
    printf( "%.2f\n", ave );
    return 0;    
}