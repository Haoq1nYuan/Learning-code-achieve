#include<stdio.h>

int judge(int);

int main(){
    int count=0;
    int i;
    for(i=101;i<201;i++){
        if(judge(i)){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}

int judge(int a){
    int i;
    for(i=2;i<a;i++){
        if(a%i==0){
            return 0;
            break;
        }else if(i==a){
            return 1;
        }
    }
}