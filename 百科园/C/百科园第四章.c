//程序设计1
/*
函数fun()是根据正整数n，求下面数列的和 s=1+1/22+1/333+......+1/nn...nn
当输入n=5，s=1.04870057 ,注意:部分源程序给出如下。 
请勿改动main函数和其他函数中的任何内容,仅在函数fun的注释语句之间填入所编写的若干语句。
*/ 
#include<stdio.h>
#include<stdlib.h>
double fun(int n)
{
	/*********Begin*********/
	int i=0,j=0,box=0;
	double s=0.0,num=0.0;
	for(i=1;i<n+1;i++){
		box=i;
		num=0;
		for(j=1;j<i+1;j++){
			num+=box;
			box*=10;
		}
		s+=1.0/num;
	}
	return s;
	/*********End*********/
}
int main()
{
	FILE *in,*out;
	int n,i;
	double s;
	scanf("%d",&n);
	s=fun(n);
	printf("%.8lf\n",s);
	/**************/
	in=fopen("in96.dat","r");
	out=fopen("out96.dat","w");
	while(!feof(in))
	{
		fscanf(in,"%d",&n);
		fprintf(out,"%.8lf\n",fun(n));
	}
	fclose(in);
	fclose(out);
       system("pause");
	return 0;
}

//程序设计2
/*
函数fun是根据输入n，求下面分母为n以内(包含n)的素数构成的数列的和 ，输入10，输出：-0.138095。
要求在fun函数的注释语句之间编写程序，其它部分不得增删语句。
*/
#include<stdio.h>
#include<stdlib.h>
double fun(int n)
{
/*************************Begin*********************/
	int i=0,j=0,count=1;
	double s=0.0;
	for(i=1;i<n+1;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				break;
			}
		}
		if(j==i){
			s+=((count%2==0)?-1:1)*((double)count/(double)i);
			count++;
		}
	}
	return s;
/**************************End**********************/
}
int main()
{
	int n;
	double s,x;
	FILE *in,*out;
	printf("输入n:");
	scanf("%d",&n);
	s=fun(n);
	printf("%lf\n",s);
	/*****************/
	in=fopen("in2019-2-1-2.dat","r");
	out=fopen("out2019-2-1-2.dat","w");
	while(!feof(in))
	{
		fscanf(in,"%d",&n);
		fprintf(out,"%lf\n",fun(n));
	}
            fclose(in);
            fclose(out);
	system("pause");
	return 0;	
}

//程序设计3
   /*请编写函数fun,其功能是:将所有大于1小于整数m的非素数存入xx所指数组中,非素数的个数通过k传回。 
    例如,输入17,则应输出4 6 8 9 10 12 14 15 16。 
注意:部分源程序给出如下。 
请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号中填入所编写的若干语句。 
    试题程序: */
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int fun(int m, int xx[])
{
    /***************Begin************/
	int k=0,i=0,j=0;
	for(i=1;i<m+1;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				xx[k]=i;
				k++;
				break;
			}
		}
	}
	return k;
    /*************** End ************/
}
int main()
{
  FILE *wf,*in;
  int m, n,k, zz[100];
  printf("\nPlease enter an integer number between 10 and 100: ");
  scanf("%d",&n);
  m=fun(n,zz);
  printf("\n\nThere are %d non-prime numbers less than %d: ",m,n);
  for(n=0;n<m;n++)
    printf("%4d\n",zz[n]);
  in=fopen("in01.dat","r");
  wf=fopen("out01.dat","w");
  fscanf(in,"%d",&k);
  m=fun(k,zz);
  for(n=0;n<m;n++)
    fprintf(wf,"%d\n",zz[n]);
  fclose(in);
  fclose(wf);
  return 0;
}

//程序设计4
#include<stdio.h>
#include<stdlib.h>
double fun(int n)
{
/**********************Begin*********************/
	int i=0;
	double s=0.5,num=0.5;
	for(i=2;i<n+1;i++){
		num*=(2.0*i-1)/(2.0*i);
		s+=((i%2==0)?-1:1)*num;
	}
	return s;
/**********************End*********************/
}
int main()
{
	int n;
	double s;
	FILE *in,*out;
	printf("输入n:");
	scanf("%d",&n);
	s=fun(n);
	printf("%lf\n",s);
	/***********************/
	in=fopen("in2019-2-3-2.dat","r");
	out=fopen("out2019-2-3-2.dat","w");
	while(!feof(in))
	{
		fscanf(in,"%d",&n);
		fprintf(out,"%lf\n",fun(n));
	}
            fclose(in);
            fclose(out);
	system("pause");
	return 0;
}
