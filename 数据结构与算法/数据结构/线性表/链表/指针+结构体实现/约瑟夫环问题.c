#include<stdio.h>
#include<stdlib.h>

typedef struct people
{
    int number;
    struct people *next;
} Ori;

int n, k, m;

void create ( Ori *list ) 
{
    int i = 1;
    Ori *p = list;
    while ( i <= n ) {
        Ori *newcode = ( Ori* )malloc( sizeof( Ori ) );
        newcode->number = i;
        newcode->next = NULL;
        if ( !p ) {
            list->next = newcode;
        } else {
            while ( p->next ) {
                p = p->next;
            }
            p->next = newcode;
        } 
        i++;
    }
    p = p->next;
    p->next = list->next;
}

void delete ( Ori *list )
{
    Ori *search = list;
    while ( k > 1 ) {
        search = search->next;
        k--;
    }

    while ( n > 0 ) {
        int count = 1;
        while ( count < m ) {
            search = search->next;
            count++;
        }
        printf( "%d\n", search->next->number );

        Ori *q = search->next;
        search->next = q->next;
        free( q );
        n--;
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%d %d %d", &n, &k, &m );
    while ( k >= n ) {
        k -= n;
    }

    Ori *list = ( Ori* )malloc( sizeof( Ori ) );
    list->next = NULL;
    create( list );

    delete( list );
    
    return 0;
}