#include<stdio.h>

int* f(void);
void g(void);

int main()
{
    int* p = f();
    printf("*p=%d\n", *p);
    g();
    printf("*p=%d\n", *p);
    return 0;
}

int* f(void)
{
    int i = 12;
    return &i; //无法编译运行，传出一个局部变量的地址后（离开这个函数），i所处的空间就会被回收，在运行g函数的时候就会重新使用该内存
}

void g(void)
{   
    int k = 24;
    printf("k=%d\n",k);
}