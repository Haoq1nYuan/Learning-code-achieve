#include<stdio.h>
#include<stdlib.h>

typedef struct student 
{
    int num;
    char name[10];
    char sex;
    int age;
    double score;
    struct student * next;
} S;

int main ( int argc, char * argv[] ) 
{
    S *head;
    head = ( S* )malloc( sizeof(S) );
    head->next = NULL;
    S *p;
    int count = 10;
    while ( count ) {
        p = ( S* )malloc( sizeof(S) );
        scanf( "%d %s %c %d %lf", &p->num, &p->name, &p->sex, &p->age, &p->score );
        p->next = head->next;
        head->next = p;
        count--;
    }
    printf( "学号\t姓名\t性别\t年龄\t成绩\t\n" );
    S *n = head;
    while ( count < 10 ) {
        n = n->next;
        printf( "%d\t%s\t%c\t%d\t%.1lf\n", n->num, n->name, n->sex, n->age, n->score );
        count++;
    }
    return 0;
}