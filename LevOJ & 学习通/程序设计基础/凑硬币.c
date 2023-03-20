#include<stdio.h>
int main(){
    int i,j,k;
    for(i=0;i<=10;i++){
        for(j=0;j<=20;j++){
            for(k=0;k<=50;k++){
                if(1*i+2*j+5*k==10){
                    printf("%d %d %d£»",i,j,k);
                }
            }
        }
    }
    return 0;
}
