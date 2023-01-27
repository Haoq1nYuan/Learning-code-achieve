#include<stdio.h>
int main(){
    int m,n,k;
    while(scanf("%d %d %d",&m,&n,&k)!=EOF){
        int i,result,l;
        l=m;
        if(l>n){
            l=n;
        }
        if(l>k){
            l=k;
        }
        for(i=1;i<l+1;i++){
            if(n%i==0&&m%i==0&&k%i==0){
                result=i;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
