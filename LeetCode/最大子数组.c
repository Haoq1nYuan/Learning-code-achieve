#include<stdio.h>
#define N 10000

int set(int *num, int count);

int main(){
    int num[N],result=0,i=0;
    signed int number;
    while(scanf("%d",&number)!=EOF){
        num[i]=number;
        i++;
    }
    result=set(num, i);
    printf("%d\n",result);
    return 0;
}

int set(int *num, int count){
    int length,i,j,sum,max=0;
    for(length=1; length<count; length++){
        for(i = 0; i+length<count; i++){
            for(j=i; j<=i+length; j++){
                sum+=num[j];
            }
            if(max<sum){
                max=sum;
            }
            sum=0;
        }
    }
    return max;
}