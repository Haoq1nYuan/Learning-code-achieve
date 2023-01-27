#include<stdio.h>
#include<stdlib.h>
int main () {
    char **a;
    int number;
    scanf( "%d", &number );
    a = ( char** )malloc( sizeof(char*) * number );
    a[0] = ( char* )malloc( sizeof(char) * 2 );
    a[1] = ( char* )malloc( sizeof(char) * 2 );
    scanf( "%s", a[0] );
    scanf( "%s", a[1] );
    printf( "%s\n", a[0] );
    printf( "%s\n", a[1] );
    free(a[0]);
    free(a[1]);
    free(a);
    return 0;
}