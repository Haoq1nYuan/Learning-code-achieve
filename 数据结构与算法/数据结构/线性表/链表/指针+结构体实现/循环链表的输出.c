#include<stdio.h>
#include<stdlib.h>

typedef struct people
{
    int number;
    struct people *next;
} Ori;

int n, deadline;

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

int main ( int argc, char *argv[] )
{
    scanf( "%d %d", &n, &deadline );
    Ori *list = ( Ori* )malloc( sizeof( Ori ) );
    list->next = NULL;
    create( list );

    int count = 0;
    Ori *result = list->next;
    while ( count != deadline ) {
        count++;
        printf( "%d: %d\n", count, result->number );
        result = result->next;
    }
    return 0;
}