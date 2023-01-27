#include<stdio.h>

int main(){
    int x;

    scanf("%d",&x);

    int i;
    int isprime=1;
    
    if(x<0){
        printf("输入数据错误！");
    }else{
        for(i=2;i<x;i++){
            if(x%i==0){
                isprime=0;
                continue;
            }
        }
        if(isprime==1){
            printf("%d是素数\n",x);
        }else{
            printf("%d不是素数\n",x);
        }
    }
                        
    return 0;
}