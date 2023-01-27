#include<stdio.h>
#include<string.h>
int a[10000];
int main(){
    int L,M;
    while(scanf("%d %d",&L,&M)!=EOF){
        int b,c,i,num;
        while(M--){
            scanf("%d %d",&b,&c);
            for(i=b;i<=c;i++){
                if(a[i]==0){
                    a[i]=1;
                }
            }
        }
        num=0;
        for(i=0;i<L+1;i++){
            if(a[i]==0){
                num++;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}