#include<stdio.h>
int main(){
    int n,k,i;
    while(scanf("%d",&n)!=EOF){
        int a[n-1],b[n-1];
        scanf("%d",&k);
        if(n>=k){
            for(i=0;i<n;i++){
                scanf("%d",&a[i]);
                b[i]=a[i];
            }
            for(i=k;i<n;i++){
                a[i-k]=a[i];
                printf("%d\n",a[i-k]);
            }   
            for(i=0;i<k;i++){
                printf("%d\n",b[i]);
            }
        }
    } 
    return 0;
}