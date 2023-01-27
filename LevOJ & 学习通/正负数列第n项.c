#include<stdio.h>
#include<math.h>

int main(){
    int n;
    int sum1=2,sum2=1;
    double result,sum=2;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        sum1=sum1+sum2;
        sum2=sum1-sum2;
        result=pow(-1,(float)i)*sum1/sum2;
        sum+=result;
    }
    printf("%lf",sum);
    return 0;
}