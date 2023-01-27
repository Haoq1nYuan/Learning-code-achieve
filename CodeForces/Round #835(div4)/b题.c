#include<stdio.h>
#include<string.h>

#define N 100

int main ( int argc, char argv[] ) 
{
    int n;
    scanf( "%d",&n );
    while (n--) {
        int length, max=0;
        char s[N];
        memset( s, 0, sizeof(s) );
        scanf( "%d", &length );
        while ( length>=0 ) {
            scanf( "%c",&s[length] );
            if ( s[length]-96>max ) {
                max = s[length]-96;
            }
            length--;
        }
        printf( "%d\n",max );
    }
    return 0;
}