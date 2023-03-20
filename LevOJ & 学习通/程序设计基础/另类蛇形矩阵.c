#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 20

int ans[N][N], tem[N][N];
int num;

void reverse ( int (*p)[20] )
{   
    for ( int i = 1; i <= num; i++ )
        for ( int j = 1; j <= num; j++ )
            tem[j][num-i+1] = p[i][j];
}

int main ( int argc, char *argv[] )
{
    int l = 1, flag = 0;

    scanf( "%d", &num );

    int x = 1, y = 1;
    for ( int i = 1; i <= num*num; i++ )
    {
        ans[x][y] = i;

        if ( flag == 1 )
        {
            if ( l == 1 ) x--, y++;
            if ( l == -1 ) x++, y--;
            flag--;
            continue;
        }
        
        if ( x == 1 || x == num || y == 1 || y == num ) l *= (-1), flag++;

        if ( x == 1 ) 
        {
            if ( y < num ) y++;
            else x++;
        } else if ( x == num ) y++; 
        else if ( y == 1 )
        {
            if ( x < num ) x++;
            else y++;
        } else if ( y == num ) x++; 
        else if ( l == 1 ) x--, y++;
        else x++, y--;
    }

    reverse(ans);

    for ( int i = 1; i <= num; i++ )
    {
        for ( int j = 1; j <= num; j++ )
            printf( "%-2d ", tem[i][j] );
        puts("");
    }

    return 0;
}