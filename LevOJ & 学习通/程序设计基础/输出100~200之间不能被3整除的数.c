#include<stdio.h>
int main(){
    int i,x;
    int count=0;
    for(i=100;i<201;i++){
        if(i%3==0){
            continue;
        }else{
            printf("%6d",i);
            count++;
        }
        if(count==6){
            printf("\n");
            count=0;
        }
        if(i==200){
            printf("\n");
        }
    }
    return 0;
}