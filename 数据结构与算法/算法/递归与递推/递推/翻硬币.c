//https://www.acwing.com/problem/content/description/1210/

#include<stdio.h>
#include<string.h>

char start[105], final[105];
int result;

int main ( int argc, char *argv[] )
{
    gets(start);
    gets(final);

    for ( int i = 0; i < strlen(start)-1; i++ )
        if ( start[i] != final[i] ) 
        {
            result++;
            if ( start[i+1] == '*' ) start[i+1] = 'o';
            else if ( start[i+1] == 'o' ) start[i+1] = '*';
        }  
        
    printf( "%d\n", result );

    return 0;    
}