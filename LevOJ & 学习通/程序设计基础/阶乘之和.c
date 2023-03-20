#include<stdio.h>
int main(){
    int a,sum;
    while(scanf("%d",&a)!=EOF){
        sum=1;
        for(int i=2;i<=a;i++){
            int t=1;
            for(int j=2;j<=i;j++){
                t=t*j;
            }
            sum+=t;     
        }
        if(a<=1){
            printf("%d\n",sum);
        }else{
            printf("%d\n",sum+1);
        }  
    }
    return 0;
}