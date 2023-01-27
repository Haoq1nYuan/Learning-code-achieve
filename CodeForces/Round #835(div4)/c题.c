#include<stdio.h>
#include<string.h>

#define N 200000
long long s[N],t[N];

int main ( int argc, char *argv[] ) 
{
    int n;
    scanf( "%d",&n );
    while ( n-- ) {
        int number, i, j, count=0, box;
        memset( s, 0, sizeof(s) );
        memset( t, 0, sizeof(t) );
        scanf( "%d",&number );
        while ( count!=number ) {
            scanf( "%d",&s[count] );
            count++;
        }
        for ( i=0; i<number; i++ ) {
            t[i] = s[i];
        }
        for ( i=0; i<2; i++ ) {
            for ( j=i+1; j<number; j++ ) {
                if ( t[i]<t[j] ) {
                    box = t[i];
                    t[i] = t[j];
                    t[j] = box;
                }   
            }
        }
        for ( i=0; i<number; i++ ) {
            if ( s[i]!=t[0] ) {
                printf( "%lld ",s[i]-t[0] );
            } else {
                printf( "%lld ",t[0]-t[1] );
            }
        }
        printf( "\n" );
    }
    return 0;
}