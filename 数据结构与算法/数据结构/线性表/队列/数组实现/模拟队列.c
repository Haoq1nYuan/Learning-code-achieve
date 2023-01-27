//https://www.acwing.com/problem/content/831/

#include<stdio.h>
#define N 100010

int m, num;
char how[10];
int h, t, q[N];

/* void init ()
{
    h = 0;
    t = 0;
}

void add ( int x )
{
    q[++t] = x;
}

void pop ()
{
    h++;
}

int empty ()
{
    return h == t;
}

int get_head ()
{
    return q[h];
}

int get_tail ()
{
    return q[t];
} */

int main ( int argc, char *argv[] )
{   
    scanf( "%d", &m );
    
    t = -1;

    while ( m-- )
    {
        scanf( "%s", how );

        if ( how[0] == 'p' && how[1] == 'u' ) 
        {
            scanf( "%d", &num );
            q[++t] = num;
        }
        else if ( how[1] == 'o' ) h++;
        else if ( how[0] == 'e' ) 
        {
            if ( h <= t ) printf( "NO\n" );
            else printf( "YES\n" );
        }
        else printf( "%d\n", q[h] ); 
    }   

    return 0;
}
