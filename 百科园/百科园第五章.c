//程序设计1
/*请编写一个函数void fun(char ss[]),其功能是:将字符串ss中所有下标为奇数位置上的字母转换为大写(若该位置上不是字母,则不转换)。
例如,若输入abc4EFg,则应输出aBc4EFg。 注意:部分源程序给出如下。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号中填入所编写的若干语句。
试题程序:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void fun ( char ss[])
{
     /***************Begin************/
	int i=0;
	for(i=0;i<strlen(ss);i++){
		if(i%2&&ss[i]>='a'&&ss[i]<='z'){
			ss[i]-=32;
		}
	}
     /*************** End ************/
}

int main()
{
char tt[100];
FILE *out,*in;
printf("Please enter an character string within 50 characters:\n");
gets(tt);
printf("\n\nAfter changing,the string\n%s",tt);
fun(tt);
printf("\nbecomes\n %s",tt);
/******************************/
in=fopen("in14.dat","r");
out=fopen("out14.dat","w");
fgets(tt,16,in);
strcat(tt,"After changing the string");
fun(tt);
fprintf(out,"%s",tt);
fclose(in);
fclose(out);
/******************************/
 system("pause");
 return 0;
}

//程序设计2
/*编写一个函数fun,它的功能是:实现两个字符串的连接(不使用库函数strcat),即把p2所指的字符串连接到p1所指的字符串后。
例如,分别输入下面两个字符串: 
FirstString 
SecondString 
则程序输出:FirstStringSecondString
注意:部分源程序给出如下。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号中填入所编写的若干语句。 
试题程序:*/
#include<stdio.h>
#include<stdlib.h>
void fun(char p1[],char p2[])
{
     /***************Begin************/
  int i,j;
  for(i=0;p1[i];i++);
  for(j=0;p2[j];j++){
    p1[i++]=p2[j];
  }
  p1[i]='\0';
     /*************** End ************/
}
int main()
{
  FILE *wf,*in;
  char s1[80],s2[40];
  char  p1[80]="FirstString",p2[40]="SecondString";
  printf("Enter s1 and s2:\n") ;
  scanf("%s%s",s1,s2);
  printf("s1=%s\n",s1);
  printf("s2=%s\n",s2);
  printf("Invoke fun(s1,s2):\n");
  fun(s1,s2);
  printf("After invoking:\n");
  printf("%s\n",s1);
/******************************/
  in=fopen("in16.dat","r");
  wf=fopen("out16.dat","w");
  fscanf(in,"%s %s",p1,p2);
  fun(p1,p2);
  fprintf(wf,"%s",p1);
  fclose(in);
  fclose(wf);
/*****************************/
 system("pause");
  return 0;
}

//程序设计3
/*请编写一个函数fun,它的功能是:将一个数字字符串转换为一个整数(不得调用C语言提供的将字符串转为整数的函数)。
例如,若输入字符串"-1234",则函数把它转换为整数值-1234。
注意:部分源程序给出如下。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号中填入所编写的若干语句。
试题程序:*/
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
long fun(char p[])
{
     /***************Begin************/
	long n=0,i=0;
	int flag=1;
	if(p[i]=='-'){
		i++;
		flag=-1;
	}else if(p[i]=='+'){
		i++;
	}
	while(p[i]){
		n=n*10+p[i]-'0';    //此处将字符转化为整型变量
		i++;
	}
	return n*flag;
     /*************** End ************/
}
int main()
{
  FILE *wf,*in;
  char s[10];
  long n;
  printf("Enter a string:\n");
  gets(s);
  n=fun(s);
  printf("%ld\n",n);
/******************************/
  in=fopen("in13.dat","r");
  wf=fopen("out13.dat","w");
  fscanf(in,"%s",s);
  fprintf (wf,"%ld",fun(s));
  fclose(wf);
  fclose(in);
/*****************************/
  system("pause");
return 0;
}

//程序设计4
/*编写函数int fun(int lim, int aa[MAX]),该函数的功能是求出小于或等于lim的所有素数并放在aa数组中,
该函数返回所求出的素数的个数。 
注意:部分源程序给出如下。 
请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号中填入所编写的若干语句。 
试题程序: */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int fun(int lim, int aa[MAX])
{
/**********Begin**********/
	int i=0,j=0,count=0;
	for(i=2;i<=lim;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				break;
			}
		}
		if(j==i){
			aa[count]=i;
			count++;
		}
	}
	return count;
/**********End**********/  
}
int main()
{
  FILE *wf,*in;
  int limit,i,k,sum;
  int aa[MAX];
  printf("输入一个整数");
  scanf("%d",&limit);
  sum=fun(limit,aa);        
  for(i=0;i<sum;i++)
     {
      if(i%10==0&&i!=0)    /*每行输出10个数*/
         printf("\n ");
      printf("%5d ",aa[i]);
    }
/******************************/
  wf=fopen("2.out","w");
  in=fopen("2.dat","r");
  fscanf(in,"%d",&k);
  sum=fun(k,aa);        
  for(i=0;i<sum;i++)
      fprintf(wf,"%d\n",aa[i]);
  fclose(wf);
  fclose(in);
/*****************************/
system("pause");
return 0;
}

//程序设计5
/*请编写函数fun,函数的功能是:求出二维数组周边元素之和,作为函数值返回。二维数组中的值在主函数中赋予。 
例如,若二维数组中的值为 
    1  3  5  7  9 
    2  9  9  9  4 
    6  9  9  9  8 
    1  3  5  7  0 
则函数值为61。 
注意:部分源程序给出如下。 
请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号中填入所编写的若干语句。 
    试题程序:*/
#include<stdio.h>
#include<stdlib.h>
#define  M  4
#define  N  5
int fun( int a [M][N])
{
     /***************Begin************/
	int sum=0;
	int i=0,j=0;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(i==0||j==0||i==M-1||j==N-1){
				sum+=a[i][j];
			}
		}
	}
	return sum;
     /*************** End ************/
}
void main()
{
  FILE *wf,*in;
  int aa[M][N]={{1,3,5,7,9},{2,9,9,9,4},{6,9,9,9,8},{1,3,5,7,10}};
  int i, j, y;
  printf ("The original data is :\n ");
  for(i=0; i<M;i++)
     {for (j=0; j<N;j++) 
          printf("%6d ",aa[i][j]);
      printf("\n ");
     }
  y=fun(aa);
  printf("\nThe sun: %d\n ",y);
  printf("\n ");
/******************************/
 in=fopen("in10.dat","r");
  wf=fopen("out10.dat","w");
  for(i=0;i<M;i++)
    for(j=0;j<N;j++)
      fscanf(in,"%d",&aa[i][j]);
  y=fun(aa);
  fprintf (wf,"%d",y);
  fclose(wf);
  fclose(in);
/*****************************/
system("pause");
} 

//程序设计6
/*请编写函数fun,其功能是:将所有大于1小于等于整数m的非素数存入xx所指数组中,非素数的个数通过k传回。
例如,输入17,则应输出4 6 8 9 10 12 14 15 16。
注意:部分源程序给出如下。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号中填入所编写的若干语句。
试题程序:*/ 
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int fun(int m, int xx[])
{
/**********Begin*******/
	int i=0,count=0,j=0;
	for(i=2;i<=m;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				xx[count]=i;
				count++;
				break;
			}
		}
	}
	return count;
/*********End*********/  
}
int main()
{
  FILE *wf,*in;
  int m, n, zz[100];
  printf("\nPlease enter an integer number between 10 and 100: ");
  scanf("%d",&n);
  m=fun(n,zz);
  printf("\n\nThere are %d non-prime numbers less than %d: ",m,n);
  for(n=0;n<m;n++)
    printf("\n %4d",zz[n]);
/******************************/
  wf=fopen("1.out","w");
  in=fopen("1.in","r");
  fscanf(in,"%d",&n);
  m=fun(n,zz);
  for(n=0;n<m;n++)
    fprintf(wf,"%d\n",zz[n]);
  fclose(wf);
 fclose(in);
/*****************************/
system("pause");
return 0;
}

//程序设计7
/*    编写程序，实现矩阵（3行3列）的转置（即行列互换）。
例如，输入下面的矩阵：  
         100  200  300
         400  500  600
         700  800  900
程序输出：  
         100  400  700
         200  500  800
         300  600  900
    注意： 部分源程序存在文件program.c中。
    请勿改动主函数main和其他函数中的任何内容，仅在函数fun的花括号中填入你编写的若干语句。*/
#include <stdio.h>
#include<stdlib.h>
void fun(int array[3][3])
{
    /**********  Begin  **********/
	int i=0,j=0,box;
	for(i=0;i<3;i++){
		for(j=i;j<3;j++){
			box=array[i][j];
			array[i][j]=array[j][i];
			array[j][i]=box;
		}
	}
    /**********   End  ***********/
}

void NONO( )
{/* 请在此函数内打开文件，输入测试数据，调用 fun 函数，
    输出数据，关闭文件。 */
    int i,j;
    FILE  *wf ,*in;
    int array[3][3]={{100,200,300},
                     {400,500,600},
                     {700,800,900}};
    in=fopen("a11.in","r");
    for(i=0;i<3;i++)
    {   for(j=0;j<3;j++)
	fscanf(in,"%d",&array[i][j]);
     }
    wf = fopen("a11.out", "w") ;
    fun(array);
    for(i=0;i<3;i++)
    {   for(j=0;j<3;j++)
	fprintf(wf,"%7d\n",array[i][j]);
     }

    fclose(wf) ;
    fclose(in);
}

int main()
{
    int i,j;
    int array[3][3]={{100,200,300},
                     {400,500,600},
                     {700,800,900}};
     for (i=0;i<3;i++)
    {    for (j=0;j<3;j++)
         printf("%7d",array[i][j]);
         printf("\n");
    }
    fun(array);
    printf("Converted array:\n");
    for(i=0;i<3;i++)
    {   for(j=0;j<3;j++)
        printf("%7d",array[i][j]);
        printf("\n");
    }
 NONO( );
 system("pause");
 return 0;
}

//程序设计8
/*请编写函数fun,其功能是:计算并输出给定数组(长度为n)中,每相邻两个元素的平均值的平方根之和。 
例如,若给定数组中的9个元素依次为12.0、34.0、4.0、23.0、34.0、45.0、18.0、3.0、11.0,则输出应为s=35.951014。 
注意:部分源程序给出如下。 请勿改动main函数和其他函数中的任何内容,仅在函数fun的花括号的注释语句之间中填入所编写的若干语句。 试题程序:*/ 
#include  <stdio.h>
#include  <math.h>
#include<stdlib.h>
double fun(double x[],int n)
{
/************Begin**************/	
	int i=0;
	double average=0.0,sum=0.0;
	for(i=0;i<n-1;i++){
		average=(x[i]+x[i+1])/2;
		sum+=sqrt(average);
	}
	return sum;
/************End**************/
}
int main()
{double s,a[100]={12.0,34.0,4.0,23.0,34.0,45.0,18.0,3.0,11.0};
 int i,n;
 FILE *out,*in;
 printf("\nThe original data is : ");
 for(i=0;i<9;i++)
	printf("%6.1f",a[i]);
 printf("\n\n"); 
 s=fun(a,9);
 printf("s=%lf\n\n",s);
 /******************************/
 in=fopen("in48.dat","r");
 out=fopen("out48.dat","w");
 fscanf(in,"%d",&n);
 for(i=0;i<n;i++)
	 fscanf(in,"%lf",&a[i]);
 s=fun(a,n);
 fprintf(out,"%lf",s);
 fclose(out);
 fclose(in);
 /******************************/
 system("pause");
 return 0;
}

//程序填空1
/*请补充函数fun(char s[]),该函数的功能是:把字符串中的内容逆置。
例如,字符串中原有的字符串为abcde,则调用该函数后,串中的内容为edcba。
注意:部分源程序给出如下。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的横线上填入所编写的若干表达式或语句。
试题程序: */
#include <string.h>
#include <stdio.h>
#define N 81
void fun(char s[])
{
	 int i,n=strlen(s)-1;
	 char t;
/**********FILL**********/
	 for(i=0;i<n;i++,n--)  //两头一起向中间收拢
	 {
    	t=s[i];
/**********FILL**********/
	  	s[i]=s[n]; 
/**********FILL**********/
	  	s[n]=t;  
	 }
}

int main()
{
	 char a[N];
	 printf("Enter a string:");
	 gets(a);
	 printf("The  original string is:");
	 puts(a);
	 fun(a);
	 printf("\n");
	 printf("The string after modified:");
	 puts(a);
return 0;
}

//程序填空2
/*
下面程序的功能是将一个整数数组中存储的N个整数循环右移或循环左移m次。数组中各元素的初始值为1，2，3，4，5，6，7，8。
函数fun的功能是将形参数组中前n元素值，循环移位m次，形参k表示移位方向，k=0表示循环右移，k=1表示循环左移。
m=3，k=0时输出：6，7，8，1，2，3，4，5
m=3，k=1时输出：4，5，6，7，8，1，2，3
注意：仅在注释语句下面填入所编写的若干表达式或语句,其他部分不要改动。
*/
#include<stdio.h>
#define N 8
void fun(int a[],int n,int m,int k)
{
	int i,temp;
	if (m<0)return;
/**********FILL**********/
	while(m>0)
	{
		if(!k)
		{
			temp=a[n-1];
			for(i=n-1;i>0;i--)
			{
             /**********FILL**********/
			  a[i]=a[i-1];
			} 
			a[0]=temp;
		}
		else
		{
			temp=a[0];
			for(i=1;i<n;i++)
			  a[i-1]=a[i];			
      /**********FILL**********/ 
			  a[i-1]=temp;
		}
		m--;
	}
}
int main()
{
	int a[N]={1,2,3,4,5,6,7,8},m,i,k;
	printf("Input m:\n");
	scanf("%d",&m);
	printf("Input k:\n");
	scanf("%d",&k);	
    /**********FILL**********/ 
	fun(a,N,m,k);
	printf("Result:\n");
	for(i=0;i<N;i++)
	  printf("%4d",a[i]);
	return 0;
}

//程序填空6
/*请补充函数fun,该函数的功能是:把一个整数转换成字符串,并倒序保存在字符数组str中。
例如,当n=13572468时,str="86427531"。
注意:部分源程序给出如下。
请勿改动main函数和其他函数中的任何内容,仅在函数fun的横线上填入所编写的若干表达式或语句。
试题程序:*/
#include <stdlib.h>
#include <stdio.h>
#define N 80
char str[N];
void fun(long int n)
{
	 int i=0;
/**********FILL**********/
	 while(n)
	 {
/**********FILL**********/
		str[i]=n%10+'0';   //将整型转换为字符
		n/=10;
		i++;
	 }
/**********FILL**********/
	  str[i]='\0';
}
int main()
{
	 long int n=13572468;
	 printf("*** the origial data ***\n");
	 printf("n=%ld",n);
	 fun(n);
	 printf("\n%s",str);
return 0;
}

//程序改错3
/*下列给定程序中,函数fun的功能是:求出数组中最大数和次最大数,并把最大数和a[0]中的数对调、次最大数和 a[1] 中的数对调。 
请改正程序中的错误,使它能得出正确的结果。 
注意:不要改动main函数,不得增行或删行,也不得更改程序的结构。 
    试题程序:*/
#include<stdio.h>
#define  N   20
/**********ERROR**********/
void fun(int a[],int n)
{
 int  i,  m, t, k;
 for(i=0; i<n;i++)
   {
/**********ERROR**********/
    m=i;
    for(k=i+1; k<n; k++)
      if(a[k]>a[m])
         m=k;
    t=a[i];
    a[i]=a[m];
    a[m]=t;
   }
}
int main()
{ 
  int b[N]={11,5,12,0,3,6,9,7,10,8},n=10,i;
  for(i=0; i<n; i++)  
    printf("%d ",b[i]);
  printf("\n");
  fun(b,n);
  for(i=0; i<n; i++)  
    printf("%d ", b[i]);
  printf("\n");

return 0;
}
