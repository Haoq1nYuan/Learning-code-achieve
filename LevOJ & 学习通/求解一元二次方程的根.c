#include<stdio.h>
#include<math.h>
int main(){
    double a,b,c,delta,x1,x2,p,q;
    while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF){
        if(a==0){
            printf("不是一元二次方程\n");
        }else{
            delta=b*b-4*a*c;
            printf("delta=%lf\n",delta);
            if(delta>=0){
                x1=-b/(2*a)+sqrt(delta)/(2*a);
                x2=-b/(2*a)-sqrt(delta)/(2*a);
                printf("x1=%.2f,x2=%.2f\n",x1,x2);
            }else{
                p=-b/(2*a);
                q=sqrt(-delta)/(2*a);
                printf("x1=%.2f+%.2fi,x2=%.2f-%.2fi\n",p,q,p,q);
            }
        }
    }
    return 0;
}