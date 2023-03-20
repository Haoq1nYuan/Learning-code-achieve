#include<stdio.h>
#include<string.h>
int a[1000];
int main(){
    int n,k,i,j;
    while(scanf("%d  %d",&n,&k)!=EOF){
        memset(a,0,sizeof(a));
        for(i=1;i<=k;i++){
            for(j=1;j<=n;j++){
                if(j%i==0){
                    a[j]=!a[j];
                }
            }
        }
        for(i=1;i<=n;i++){
            if(a[i]){
                printf("%d\n",i);
            }
        }
    }
    return 0;
}