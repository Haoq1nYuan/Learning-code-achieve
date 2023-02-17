#include <stdio.h>
#include <stdlib.h>

typedef struct kk
{
    int num;
    struct kk *next;
} N;

void print ( N *h )
{
    for ( N *q = h; q; q = q->next )
        printf( "%d ", q->num );
    puts("");
}

int main ()
{
    N *head = NULL;
    int n;

    for ( int i = 1; i <= 5; i++ )
    {
        scanf( "%d", &n );

        N *newcode = (N*)malloc(sizeof(N));
        newcode->num= n;
        newcode->next = NULL;

        N *p = head;
        if ( p )
        {
            while ( p->next ) p = p->next;
            p->next = newcode;
            p = p->next;
        }
        else head = newcode;
    } 

    print(head);

    int target;
    scanf( "%d", &target );

    N *q;
    for ( N *o = head; o; q = o, o = o->next )
    {
        if ( o->num == target )
        {
            if ( o == head ) head = head->next;
            else q->next = o->next;
            
            free(o);
            break;
        }
    }

    print(head);

    int num1;
    scanf( "%d %d", &num1, &target );

    for ( N* o = head; o; q = o, o = o->next )
    {
        if ( o->num == target )
        {
            N *newcode = (N*)malloc(sizeof(N));
            newcode->num = num1;
            if ( o == head ) 
            {
                newcode->next = head;
                head = newcode;
            }
            else
            {
                newcode->next = o;
                q->next = newcode;
            }
        }
    }

    print(head);

    return 0;
}