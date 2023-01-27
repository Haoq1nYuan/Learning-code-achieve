#include<stdio.h>
#include<string.h>
int a[1][100];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){   
        int i,j;
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++){
            if(i==n-1){
                scanf("%d",&a[0][i]);
            }else{
                scanf("%d ",&a[0][i]);
            }
        }
        for(i=0;i<n;i++){
            if(i==n-1){
                scanf("%d",&a[1][i]);
            }else{
                scanf("%d ",&a[1][i]);
            }
        }
        for(i=0;i<n;i++){
            printf("%d ",a[0][i]+a[1][i]);
        }
        printf("\n");
    }
    return 0;
}