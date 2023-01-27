#include<stdio.h>
#include<stdlib.h>
#define N 10000

int set(int *num, int n);

int main()
{
    int num[N],number,i=0;
    memset(num,0,sizeof(num));
    while(scanf("%d",&number)!=EOF){
        num[i]=number;
        i++;
    }
    return 0;
}

int set(int *num, int n){
    return 
}