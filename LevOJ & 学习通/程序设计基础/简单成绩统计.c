#include<stdio.h>
int main(){
    int x,isprime=1,max=0,min=100,count=0,sum=0;
    double result;
    do{
        isprime=1;
        scanf("%d",&x);
        if(x==-1){
            isprime=0;
            break;
        }
        if(max<x){
            max=x;
        }else if(min>x){
            min=x;
        }
        sum+=x;
        count++;
        result=1.00*sum/count;
    }while(isprime);
    printf("%d,%.2f,%d,%d",count,result,max,min);
    return 0;
}