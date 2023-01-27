#include<stdio.h>
#include<stdlib.h>

struct student 
{
	int num;
	char name[15];
	double score;
} stu;

int main ()
{
	FILE * p;
	int count = 3;
	p = fopen( "data", "w" );
	if ( p == NULL ) {
		printf( "Unsuccessfully!\n");
	} else {
		printf( "请输入学生信息：\n" );
		while ( count > 0 ) {
			count--;
			fprintf( p, "学生数据%d:\t", 3-count );
			scanf( "%d %s %lf", &stu.num, &stu.name, &stu.score );
			fprintf( p, "%d\t%s\t%lf\n", stu.num, stu.name, stu.score );
		}
	}
	fclose( p );
	return 0;
}