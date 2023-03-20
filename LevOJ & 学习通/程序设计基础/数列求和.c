#include<stdio.h>
#include<math.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int sum1=2,sum2=1;
        double result,sum=2;
        for(int i=1;i<n;i++){
            sum1=sum1+sum2;
            sum2=sum1-sum2;
            result=pow(-1,(float)i)*sum1/sum2;
            sum+=result;
        }
        printf("%.4lf\n",sum);
    }    
    return 0;
}