/* #include <stdio.h>
#include <stdlib.h>

int n;

typedef struct node
{
    int num;
    struct node* next;
} N;

int main ()
{
    N *head;
    head = NULL;

    for ( int i = 1; i <= 5; i ++ )
    {
        scanf( "%d", &n );

        N *newcode;
        newcode = (N*)malloc(sizeof(N));
        newcode->num = n;
        newcode->next = NULL;

        N *p = head;

        if ( p != NULL )
        {
            while (p->next != NULL) p = p->next;
            p->next = newcode;
            p = p->next;
        }
        else head = newcode;
    }

    N * q = head;
    for ( int i = 1; i <= 5; i++ ) 
    {
        printf( "%d ", q->num );
        q = q->next;
    }
    puts("");

    int kk;
    scanf( "%d", &kk );

    N *n, *m = NULL;
    for ( n = head; n; m = n, n = n->next )
        if ( n->num == kk ) 
        {
            m->next = n->next;
            free(n);
            break;
        }
    
    N * t = head;
    for ( int i = 1; i <= 4; i++ ) 
    {
        printf( "%d ", t->num );
        t = t->next;
    }
    puts("");

    int pp;
    scanf( "%d %d", &kk, &pp );

    N *a;                       
    for ( a = head; a; a = a->next )
        if ( a->num == pp )
        {
            N *newcode = (N*)malloc(sizeof(N));
            newcode->num = kk;
            newcode->next = a->next;
            a->next = newcode;
            break;
        }
        
    N * o = head;
    for ( int i = 1; i <= 5; i++ ) 
    {
        printf( "%d ", o->num );
        o = o->next;
    }

    return 0;
} */

#include<stdio.h>
#include <stdlib.h>

int main ()
{
    char *s = (char*)malloc(5);

    gets(s);

    puts(s);

    return 0;
}