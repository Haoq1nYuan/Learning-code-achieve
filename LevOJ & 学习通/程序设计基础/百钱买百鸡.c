#include<stdio.h>
int main(){
    int i,j,k;
    int x;
    scanf("%d",&x);
    for(i=1;i<=19;i++){
        for(j=1;j<=31;j++){
            for(k=1;k<=98;k++){
                if(i+j+k==x&&5*i+3*j+0.5*k==x){
                    printf("%d %d %d\n",i,j,k);
                }
            }
        }
    }
    return 0;
}