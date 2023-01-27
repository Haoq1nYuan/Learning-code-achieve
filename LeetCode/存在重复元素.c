#include<stdio.h>
#define N 10000

int set(int *a, int length);

int main(int argc, char *argv[])
{
    int num[N],i=0,count=0,result;
    while (scanf("%d",&result)!=EOF) {
        num[i] = result;
        i++;
        count++;
    }
    if ( set(num, count) ) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}

int set(int *a, int length) 
{
    int flag = 0;
    int i,j,isprime = 1;
    for (i=0; i<length; i++) {
        for (j=0; j<length; j++) {
            if ( a[i]==a[j] && i!=j ) {
                flag = 1;
                isprime = 0;
                break;
            }
        }
        if ( isprime==0 ) {
            break;
        }
    }
    return flag;
}