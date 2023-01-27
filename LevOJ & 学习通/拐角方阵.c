#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int i,j,k;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                k=i<=j?i:j;
                printf("%d ",k);
            }
            printf("\n");
        }
    }
    return 0;
}