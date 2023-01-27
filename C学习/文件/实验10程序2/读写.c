#include<stdio.h>
#include<stdlib.h>

struct student 
{
    int num;
    char name[5];
    int score;
} stu[10], box;

int main ( int argc, char * argv[] )
{
    FILE *p, *q, *s;
    int i = 0, j, count;
    p = fopen( "file2", "r" );
    q = fopen( "file3", "w" );
    s = fopen( "file4", "wb" );
    while ( !feof( p ) ) {
        fscanf( p, "%d %s %d\n", &stu[i].num, &stu[i].name, &stu[i].score );
        i++;
    }
    count = i;
    for ( i=0; i<count-1; i++ ) {
        for ( j=i+1; j<count; j++ ) {
            if ( stu[i].score < stu[j].score ) {
                box = stu[i];
                stu[i] = stu[j];
                stu[j] = box;
            }
        }
    }
    i = 0;
    fprintf( q, "排序后的数据为:\n" );
    while ( count > 0 ) {  
        fprintf( q, "%d %s %d\n", stu[i].num, stu[i].name, stu[i].score );
        fwrite( &stu[i], sizeof( struct student ), 1, s );
        count--;
        i++;
    }   
    fclose( p );
    fclose( q );
    fclose( s );
    return 0;
}