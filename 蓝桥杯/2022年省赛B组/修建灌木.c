#include<stdio.h>

int N, i;

int main ( int argc, char *argv[] ) 
{
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
        if ( i <= N/2 ) 
            printf( "%d\n", 2*( N-i ) );
        else if ( i > N/2 ) 
            printf( "%d\n", 2*( i-1 ) );
    }
    return 0;
}