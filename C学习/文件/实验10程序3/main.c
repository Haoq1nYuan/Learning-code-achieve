#include<stdio.h>
#include<stdlib.h>

struct student
{
    int num;
    char name[5];
    char sex;
    int score;
} stu[3]={{1,"zhang",'w',88},
{2,"fang",'m',45},
{3,"sun",'w',77}};

void sort ( struct student *stu, int count )
{
    int i, j;
    struct student box;
    for ( i=0; i<count-1; i++ ) {
        for ( j=i+1; j<count; j++ ) {
            if ( stu[i].score < stu[j].score ) {
                box = stu[i];
                stu[i] = stu[j];
                stu[j] = box;
            }
        }
    }
}

int main ( int argc, char * argv[] )
{
    FILE *p;
    int i;
    p = fopen( "student", "w+" );
    i = 2;
    while ( i >= 0 ) {
        fwrite( &stu[i], sizeof( struct student ), 1, p );
        i--;
    }
    fclose( p );
    fflush( p );
    p = fopen( "student", "r+" );
    i = 0;
    while ( !feof( p ) ) {
        fread( &stu[i], sizeof( struct student ), 1, p );
        i++;
    }
    sort( stu, i );
    i = 0;
    while ( i < 3 ) {
        printf( "%d %s %c %d\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score );
        i++;
    }
    fclose( p );
    return 0;
}
