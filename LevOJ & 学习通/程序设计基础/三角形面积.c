#include<stdio.h>
#include<math.h>
int main(){
    int a,b,c;
    double p,S,T;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF){
        if(a+c>b&&a+b>c&&b+c>a){
            p=(a+b+c)*0.5;
            T=p*(p-a)*(p-b)*(p-c);
            S=sqrt(T);
            printf("%.2f\n",S);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}