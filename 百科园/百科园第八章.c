//程序填空1
/*给定程序中,函数fun的功能是:将形参std所指结构体数组中年龄最大者的数据作为函数值返回,并在main函数中输出。
注意:部分源程序给出如下。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的横线上填入所编写的若干表达式或语句。 
试题程序: */
#include  <stdio.h>
typedef struct
{
  char name[10];
  int age;
}STD;
STD fun(STD std[],int n)
{
  STD max;
  int i;
/**********FILL**********/
  max=std[0];
  for(i=1;i<n;i++){
/**********FILL**********/
   	if(max.age<std[i].age)
		max=std[i];}
  return max;
}
int main()
{ 
  STD std[5]={"aaa",17,"bbb",16,"ccc",18,"eee",15};
  STD max;
  max=fun(std,5);
  printf("\nThe result is: \n ");
/**********FILL**********/
  printf("\nName :%s,Age :%d\n",max.name,max.age);
return 0;
}

//程序填空2
/*人员的记录由编号和出生年、月、日组成,N名人员的数据已在主函数中存入结构体数组std中,且编号唯一。
函数fun的功能是:找出指定编号人员的数据,作为函数值返回,由主函数输出,若指定编号不存在,返回数据中的编号为空串。 
注意:部分源程序给出如下。 
请勿改动main函数和其他函数中的任何内容,仅在函数fun的横线上填入所编写的若干表达式或语句。 
试题程序: */
#include <stdio.h>
#include <string.h>
#define N 8
typedef struct
{
  	char num[10];
	int year,month,day;
}STU;
/**********FILL**********/
STU fun(STU *std,char *num)
{
	int i;
	STU a={"",9999,99,99};
	for(i=0;i<=N;i++)
/**********FILL**********/
		if(strcmp(std[i].num,num)==0)
/**********FILL**********/
			return (std[i]);
	return a;
}
int main()
{
	STU std[N]={{"11111",1984,2,15},{"22222",1983,9,21},{"33333",1984,9,1},{"44444",1983,7,15},
{"55555",1984,9,28},{"666666",1983,11,14},{"77777",1983,6,22},{"88888",1984,8,18}};
	STU p;
	char n[10]="666666";
	p=fun(std,n);
	if(p.num[0]==0)
	{
		printf("\nNot found!\n");
	}
	else
	{
		printf("\nSucceed!\n");
		printf("%s   %d-%d-%d\n",p.num,p.year,p.month,p.day);
	}
return 0;
}

//程序填空3
/*请补充函数fun,该函数的功能是:建立一个带头结点的单向链表并输出到文件"out70.dat"和屏幕上,
各结点的值为对应的下标,链表的结点数及输出的文件名作为参数传入。注意:部分源程序给出如下。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的横线上填入所编写的若干表达式或语句。
试题程序: */
#include <stdio.h>
#include <stdlib.h>
typedef struct ss
{
	 int data;
	 struct ss *next;
}NODE;
void fun(int n,char*filename)
{
	 NODE *h,*p,*s;
	 FILE *pf;
	 int i;
	 h=p=(NODE *)malloc(sizeof(NODE));
	 h->data=0;
	 for(i=1;i<n;i++)
	 {
		s=(NODE *)malloc (sizeof (NODE));
/**********FILL**********/
		s->data=i;
/**********FILL**********/
		p->next=s;
/**********FILL**********/
		p=p->next;
	 }
	 p->next=NULL;
	 if((pf=fopen(filename,"w"))==NULL)
	 {
		printf("Can not open out98.dat!");
		exit(0);
	 }
	 p=h;
	 fprintf(pf,"\n***THE LIST***\n");
	 printf("\n***THE LIST***\n");
	 while(p)
	 {
		fprintf(pf,"%3d",p->data);
		printf("%3d",p->data);
		if(p->next!=NULL)
		{
			fprintf(pf,"->");
			printf("->");
		}
		p=p->next;
	 }
	 fprintf(pf,"\n");
	 printf("\n");
	 fclose(pf);
	 p=h;
	 while(p)
	 {
		s=p;
		p=p->next;
		free(s);
	 }
}
int main()
{
	 char *filename="out98.dat";
	 int n;
	 printf("\nInput n:");
	 scanf("%d",&n);
	 fun(n,filename);
return 0;
}

//程序填空4
/*已知学生的记录由学号和学习成绩构成,N名学生的数据已存入a结构体中,给定程序的功能是找出成绩最低的学生记录,
通过形参返回主函数。注意:部分源程序给出如下。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的横线上填入所编写的若干表达式或语句。 本题程序: */
#include <stdio.h>
#include <string.h>
#define N 10
typedef struct ss  /*定义结构体*/
{ char num[10]; 
  int s;
} STU;
void fun(STU a[], STU *s)
{
/**********FILL**********/
  STU h;
   int i;
   h=a[0];
   for(i=1;i<N;i++)
	if(a[i].s<h.s)
/**********FILL**********/
		h=a[i];
/**********FILL**********/
   *s=h;
}
int main()
{ 
STU a[N]={{ "A01",81},{ "A02",89},
{ "A03",66},{ "A04",87},{ "A05",77},
{ "A06",90},{ "A07",79},{ "A08",61},
{ "A09",80},{ "A10",71}},m;
  int i;
  printf("*****The original data*****");
  for(i=0;i<N;i++) 
     printf("No=%s Mark=%d\n", a[i].num,a[i].s);
  fun(a,&m);
printf("*****THE RESULT*****\n");
  printf("The lowest :%s, %d\n",m.num,m.s);
return 0;
}

//程序设计1
/*有n个学生，每个学生的数据包括学号，C语言程序设计课程的平时成绩和期末考试成绩，，测试数据已在主函数中，实现按平时成绩占30%，期末成绩占70%计算总评成绩，
将总评成绩平均分以上的学生的等级确定为"均分以上"，同时将这些同学的对应信息存放在结构体数组h中，人数通过函数返回值得到。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号中注释语句之间填入所编写的若干语句。*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define  N 100
typedef  struct
{ char num[10];/*学号*/
  int s1;/*期末成绩*/
  int s2;/*平时成绩*/
  float sum; /*总评*/
  char level[10]; /*等级*/
} STU;
int fun (STU a[],int n,STU h[])
{
/************Begin************/
	int i, j = 0;
	float sum = 0;
	for ( i=0; i<n; i++ ) {
		a[i].sum = a[i].s1*0.7 + a[i].s2*0.3;
		sum += a[i].sum;
	}
	sum /= 10;
	for ( i=0; i<n; i++ ) {
		if ( a[i].sum > sum ) {
      strcpy( a[i].level,"均分以上" ); 
      h[j] = a[i];
			j++;
		}
	}
	return j;
 /************End**************/
}
int main()
{
  STU s[N]={{"GA05",85,76},{"GA03",76,90},{"GA02",69,90},{"GA04",85,56},{"GA01",91,95},
				{"GA07",72,80},{"GA08",64,45},  {"GA06",87,98},{"GA015",85,86},{"GA013",91,97}},h[N];
  int i,k,n=10; 
  FILE *out,*in;
  k=fun(s,n,h);
  printf("There are :\n");
  for(i=0;i<k;i++)
    printf("%s %d %d %.2f %s\n",h[i].num,h[i].s1,h[i].s2,h[i].sum,h[i].level);
  /******************************/
  in=fopen("in70.dat","r");
  out=fopen("out70.dat","w");
  i=0;
  while(!feof(in))
  {
  	fscanf(in,"%s %d %d",s[i].num,&s[i].s1,&s[i].s2);
  	i++;
  }
  n=i;
  k=fun(s,n,h);
  for(i=0;i<k;i++)
    fprintf(out,"%s %d %d %.2f %s\n",h[i].num,h[i].s1,h[i].s2,h[i].sum,h[i].level);
  fclose(out);
  fclose(in);
  /******************************/
  system("pause");
  return 0;
}

//程序设计2
/*学生的记录由学号和成绩组成，N名学生的数据已在主函数中放入结构体数组s中,请编写函数fun，它的功能是：
把分数最高的学生数据放在b所指的数组中,注意：分数最高的学生可能不止一个，函数返回分数最高的学生的人数。 
注意: 部分源程序在如下。 
请勿改动主函数main和其它函数中的任何内容，仅在函数fun的花括号中填入 
你编写的若干语句。 
给定源程序： */
#include <stdio.h> 
#define N 16 
typedef struct 
{	 char num[10]; 
int s; 
} STREC; 
int fun( STREC *a, STREC *b ) 
{
   /**************Begin*************/
	int i, j = 0;
	STREC max={0,0};
	for ( i=0; i<N; i++ ) {
		if ( a[i].s > max.s ) {
			max = a[i];
		}
	}
	for ( i=0; i<N; i++ ) {
		if ( a[i].s == max.s ) {
			b[j++] = a[i];
		}
	}
	return j;
   /*************End***************/
    
} 
int main() 
{ STREC s[N]={{"GA05",85},{"GA03",76},{"GA02",69},{"GA04",85}, 
  {"GA01",91},{"GA07",72},{"GA08",64},{"GA06",87}, 
  {"GA015",85},{"GA013",91},{"GA012",64},{"GA014",91}, 
  {"GA011",77},{"GA017",64},{"GA018",64},{"GA016",72}}; 
STREC h[N]; 
   int i,n;
   FILE *out,*in;
   n=fun(s,h);
   printf("The %d highest score :\n",n);
   for(i=0;i<n; i++)
     printf("%s  %4d\n",h[i].num,h[i].s);
   printf("\n");
   out = fopen("out03.dat","w");
   in=fopen("in03.dat","r");
   i=0;
   while(!feof(in))
   {
      fscanf(in,"%s %d\n",h[i].num,&h[i].s);
      i++;
   }
   n=fun(s,h);
   for(i=0;i<n; i++)
   {
     fprintf(out, "%s %d\n",h[i].num,h[i].s);
   }
   fclose(in);
   fclose(out);
return 0;
} 

//程序设计3
/*有n个学生，每个学生的数据包括学号，C语言程序设计课程的平时成绩和期末考试成绩，测试数据已在主函数中，要求按平时成绩占30%，期末成绩占70%计算总评成绩，
并将总评成绩低于90分，且高于等于80分的同学的等级确定为"良好"，并将这些同学的对应信息存放在结构体数组h中，人数通过函数返回值得到，输出相应的信息。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号中注释语句之间填入所编写的若干语句。*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define  N 100
typedef  struct
{ char num[10];/*学号*/
  int s1;/*期末成绩*/
  int s2;/*平时成绩*/
  float sum; /*总评*/
  char level[10]; /*等级*/
} STU;
int fun (STU a[],int n,STU h[])
{
/************Begin************/
  int i, j = 0;
  for ( i=0; i<n; i++ ) {
	a[i].sum = a[i].s1*0.7 + a[i].s2*0.3;
	if ( a[i].sum >= 80.0 && a[i].sum < 90.0 ) {
		strcpy( a[i].level, "良好" );
		h[j++] = a[i];
	}
  }
  return j;
 /************End**************/
}
int main()
{
  STU s[N]={{"GA05",85,76},{"GA03",76,90},{"GA02",69,90},{"GA04",85,56},{"GA01",91,95},
				{"GA07",72,80},{"GA08",64,45},  {"GA06",87,98},{"GA015",85,86},{"GA013",91,97}},h[N];
  int i,k,n=10; 
  FILE *out,*in;
  k=fun(s,n,h);
  printf("There are :\n");
  for(i=0;i<k;i++)
    printf("%s %d %d %.2f %s\n",h[i].num,h[i].s1,h[i].s2,h[i].sum,h[i].level);
  /******************************/
  in=fopen("in68.dat","r");
  out=fopen("out68.dat","w");
  i=0;
  while(!feof(in))
  {
  	fscanf(in,"%s %d %d",s[i].num,&s[i].s1,&s[i].s2);
  	i++;
  }
  n=i;
  k=fun(s,n,h);
  for(i=0;i<k;i++)
    fprintf(out,"%s %d %d %.2f %s\n",h[i].num,h[i].s1,h[i].s2,h[i].sum,h[i].level);
  fclose(out);
  fclose(in);
  /******************************/
  system("pause");
  return 0;
}

//程序设计4
/*学生的记录由学号和成绩组成,N名学生的数据已在主函数中放入结构体数组s中,请编写函数fun,
它的功能是:把指定分数范围内的学生数据放在b所指的数组中,分数范围内的学生人数由函数值返回。
例如,输入的分数是60和69,则应当把分数在60到69的学生数据进行输出,包含60分和69分的学生数据。
主函数中把60放在low中,把69放在heigh中。注意:部分源程序给出如下。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号中填入所编写的若干语句。
试题程序: */
#include <stdio.h>
#define  N  16
typedef  struct
{ char num[10];
  int  s ;
}STREC;
int  fun (STREC *a, STREC *b, int l, int h )
{
/************Begin*************/
	int i, j = 0;
	for ( i=0; i<N; i++ ) {
		if ( a[i].s >= l && a[i].s <= h ) {
			b[j++] = a[i];
		}
	}
	return j;
/************End************/
}

int main ()
{
  FILE *wf,*in;
  STREC  s[N]={{ "GA005",85},{"GA003",76},{"GA002",69},{"GA004",85},
  {"GA001",96},{"GA007",72},{"GA008",64},{"GA006",87},
  {"GA015",85},{"GA013",94},{"GA012",64},{"GA014",91},
  {"GA011",90},{"GA017",64},{"GA018",64},{"GA016",72}};
  STREC h[N],tt; 
  int i, j,n, low, heigh, t;
  printf("Enter 2 integer number low & heigh: ");
  scanf("%d%d",&low,&heigh);
  if(heigh<low) 
    {t=heigh;heigh=low; low=t;}
  n=fun(s,h,low, heigh);
  printf("The student 's data between %d--%d:\n ",low, heigh);
  for(i=0;i<n;i++)
     printf("%s %4d\n ",h[i].num, h[i].s);    /*输出指定分数范围内的学生记录*/
  printf("\n ");
/******************************/
 in=fopen("in26.dat","r");
 i=0;
 while(!feof(in))
 {
     fscanf(in,"%s %d\n",s[i].num,&s[i].s);
     i++;
  }
  n=fun(s,h,80,98);
  for(i=0;i<n-1;i++)          /*分数在80～98之间的学生记录按分数从低到高排列*/
     for(j=i+1;j<n;j++)
        if(h[i].s>h[j].s) 
          {tt=h[i];h[i]=h[j];h[j]=tt;}
  wf=fopen("out26.dat","w");
  for(i=0;i<n;i++)
     fprintf(wf, "%s %4d\n",h[i].num, h[i].s);
  fclose(in);
  fclose(wf);
/*****************************/
return 0;
}

//程序设计5
/*有n个学生，每个学生的数据包括学号，C语言程序设计课程的平时成绩和期末考试成绩，测试数据已在主函数中，要求按平时成绩占30%，期末成绩占70%计算总评成绩，
并将总评成绩低于60分的同学的等级确定为"不及格"，其余同学为"及格"，并输出相应的信息。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号中注释语句之间填入所编写的若干语句。*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define  N 100
typedef  struct
{ char num[10];/*学号*/
  int s1;/*期末成绩*/
  int s2;/*平时成绩*/
  float sum; /*总评*/
  char level[10]; /*等级*/
} STU;
void fun (STU a[],int n)
{
/************Begin************/
	int i, j;
	for ( i=0; i<n; i++ ) {
		a[i].sum = a[i].s1*0.7 + a[i].s2*0.3;
		if ( a[i].sum < 60 ) {
			strcpy( a[i].level, "不及格" );
		} else {
			strcpy( a[i].level, "及格" );
		}
	} 
 /************End**************/
}
int main()
{
  STU s[N]={{"GA05",85,76},{"GA03",76,90},{"GA02",69,90},{"GA04",85,56},{"GA01",91,95},
				{"GA07",72,80},{"GA08",64,45},  {"GA06",87,98},{"GA015",85,86},{"GA013",91,97}};
  int i,n=10; 
  FILE *out,*in;
  fun(s,n);
  printf("There are :\n");
  for(i=0;i<n;i++)
    printf("%s %d %d %.2f %s\n",s[i].num,s[i].s1,s[i].s2,s[i].sum,s[i].level);
  /******************************/
  in=fopen("in67.dat","r");
  out=fopen("out67.dat","w");
  i=0;
  while(!feof(in))
  {
  	fscanf(in,"%s %d %d",s[i].num,&s[i].s1,&s[i].s2);
  	i++;
  }
  n=i;
  fun(s,n);
  for(i=0;i<n;i++)
    fprintf(out,"%s %d %d %.2f %s\n",s[i].num,s[i].s1,s[i].s2,s[i].sum,s[i].level);
  fclose(out);
  fclose(in);
  /******************************/
  system("pause");
  return 0;
}

//程序设计6
/*学生的记录由学生姓名、学号、语文、数学、英语三门成绩组成,N名学生的数据已在主函数中放入结构体数组s中,
请编写函数fun,其功能是:把三门总分最低的学生数据放在h所指的数组中。注意:分数最低的学生可能不止一个,
函数返回分数最低的学生的人数。 注意:部分源程序给出如下。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号中填入所编写的若干语句。试题程序:*/
#include <stdio.h>
# define  N 6
typedef  struct
{ 
	char name[10];
	long num;
	int s1;
	int s2;
	int s3;
	int s;
} STREC;
int fun (STREC *a,STREC *b,int m)
{
  /***********Begin*************/
	int i, j = 0, min = 300;
	for ( i=0; i<N; i++ ) {
		a[i].s = a[i].s1 + a[i].s2 + a[i].s3;
		if ( min > a[i].s ) {
			min = a[i].s;
		}
	}
	for ( i=0; i<N; i++ ) {
		if ( a[i].s == min ) {
			b[j++] = a[i];
		}
	}
	return j;
  /**********End***************/
}
int main()
{
  STREC s[100]={{"GA01",1,80,56,87},{"GA03",3,76,56,54},{"GA02",2,69,63,54},{"GA04",4,85,98,90},{"GA05",5,91,94,95},{"GA06",6,72,80,87}};
  STREC h[100]; 
  int i,n,m;  
  FILE *out,*in;
  n=fun(s,h,N);
  printf("The %d lowest score:\n",n);
  for(i=0;i<n;i++)
    printf("%s %4d\n",h[i].name,h[i].s);
  printf("\n");
  /******************************/
  in=fopen("in53.dat","r");
  out=fopen("out53.dat","w");
  fscanf(in,"%d\n",&m);
  for(i=0;i<m;i++)
    fscanf(in,"%s %ld %d %d %d\n",s[i].name,&s[i].num,&s[i].s1,&s[i].s2,&s[i].s3);
  n=fun(s,h,m);
  fprintf(out,"%d\n",n);
  for(i=0;i<n;i++)
  	fprintf(out,"%s %d\n",h[i].name,h[i].s);
  fclose(in);
  fclose(out);
  /******************************/
  return 0;
}

//程序改错1
/*下列给定程序中的函数Creatlink的功能是:创建带头节点的单向链表,并为各节点数据域赋0到m-1的值。 
请改正函数Creatlink中的错误,使它能得出正确的结果。 
注意:不要改动main函数,不得增行或删行,也不得更改程序的结构。 
试题程序: */
#include <stdio.h>
#include <stdlib.h>
typedef struct aa
{ int data;
  struct aa *next;
} NODE;

NODE *Creatlink(int n, int m)
{ NODE *h=NULL,*p,*s;
  int i;
  s=(NODE *)malloc(sizeof(NODE));
  h=s;
/**********ERROR**********/
  p=s;
  for(i=1;i<n;i++)
    { s=(NODE *) malloc(sizeof(NODE));
/**********ERROR**********/
      s->data=rand()%m; 
      s->next=p->next;p->next=s;  p=p->next;
    }
  s->next=NULL;
/**********ERROR**********/
  return h;
}
void outlink(NODE *h)
{ NODE  *p;
  p=h->next;
  printf("\n The LIST :\n\n HEAD");
  while(p)
    { printf("->%d",p->data); 
      p=p->next;}
  printf("\n");
}
int main()
{ NODE *head;
  head=Creatlink(8,22);
  outlink(head);
return 0;
}

//程序改错2
/*下列给定程序中,函数fun的功能是:对N名学生的学习成绩,按从高到低的顺序找出前m(m<=10)名学生,
并将这些学生数据存放在一个动态分配的连续存储区中,此存储区的首地址作为函数值返回。 
请改正程序中的错误,使它能得出正确的结果。 
注意:不要改动main函数,不得增行或删行,也不得更改程序的结构。 
试题程序:*/ 
#include <stdlib.h>
#include  <string.h>
#include  <stdio.h>
#include  <malloc.h>
#define N 10
typedef struct ss
   { char num[10];
     int s;
   } STU;
STU *fun(STU a[], int m)
{ STU b[N],*t;
  int i, j,k;
/**********ERROR**********/
  t=(STU *)calloc(m,sizeof(STU));
  for(i=0;i<N;i++) b[i]=a[i];
  for(k=0;k<m;k++)
     { for (i=j=0;i<N;i++)
          if(b[i].s>b[j].s) j=i;
/**********ERROR**********/
      strcpy(t[k].num,b[j].num);
      t[k].s=b[j].s;
      b[j].s=0;
     }
return t;
}
void outresult(STU a[],FILE *pf)
{ int i;
  for(i=0;i<N;i++)
  fprintf(pf, "No=%s Mark=%d\n ",
a[i].num, a[i].s);
  fprintf(pf, "\n\n ");
}
int main()
{ STU a[N]={{ "A01 ",81},{ "A02 ",89},{ "A03 ",66},{ "A04 ",87},{ "A05 ",77},
			{ "A06 ",90},{ "A07 ",79},{ "A08 ",61},{ "A09 ",80},{ "A10 ",71}};
  STU *pOrder;
  int i, m;
  printf("*****THE RESULT*****\n");
  outresult(a,stdout);
  printf("\nGive the number of the students who have better score: ");
  scanf("%d",&m);
  while(m>10)
       { printf("\nGive the number of the students who have better score: ");
  scanf("%d",&m);
}
  pOrder=fun(a,m);
  printf("***** THE RESULT*****\n");
  printf("The top :\n");
  for(i=0;i<m;i++)
     printf("%s  %d\n",pOrder[i].num, pOrder[i].s);
  free(pOrder);
return 0;
}  

//程序改错3
/*下列给定程序的功能是:建立一个带头节点的单向链表,并用随机函数为各节点数据域赋值。
函数fun的作用是求出单向链表节点(不包括头节点)数据域中的最大值,并且作为函数值返回。
请改正函数fun中的错误,使它能得出正确的结果。
注意:不要改动main函数,不得增行或删行,也不得更改程序的结构。
试题程序: */
#include <stdio.h>
#include <stdlib.h>
typedef struct aa
{ int data;
  struct aa *next;
} NODE;
int fun (NODE *h)
{ int max=-1;
  NODE *p;
/**********ERROR**********/
  p=h->next;
  while(p)
       { if(p->data>max)
             max=p->data;
/**********ERROR**********/
      p=p->next;
       }
  return max;
}
void outresult(int s, FILE *pf)
{ fprintf(pf, "\nThe max in link :%d\n",s);
}
NODE *creatlink(int n, int m)
{ NODE *h,*p,*s;
  int i;
  h=p=(NODE *)malloc(sizeof(NODE));
  h->data=9999;
  for(i=1;i<=n;i++)
    { s=(NODE *) malloc(sizeof(NODE));
      s->data=rand()%m; s->next=p->next;
      p->next=s;  p=p->next;
    }
  p->next=NULL;
  return h;
}
void outlink(NODE *h,FILE *pf)
{ NODE  *p;
  p=h->next;
  fprintf(pf, "\n The LIST :\n\n HEAD");
  while(p)
    { 
fprintf(pf, "->%d",p->data); 
  p=p->next;}
  fprintf(pf, "\n");
}
int main()
{ NODE *head; int m;
  head=creatlink(12,100);
  outlink(head,stdout);
  m=fun(head);
  printf("\nThe RESULT :\n"); 
  outresult(m,stdout);
return 0;
}

