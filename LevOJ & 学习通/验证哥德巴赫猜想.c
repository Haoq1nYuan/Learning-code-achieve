#include<stdio.h>
#include<math.h>
int main(){
    int i,p,q,n,p_flag,q_flag;
    while(scanf("%d",&n)!=EOF){
        if((n%2==0)&&n>=4){
            p=1;
            do{
                p+=1;
                q=n-p;
                p_flag=1;
                for(i=2;i<sqrt(1.0*p);i++){
                    if(p%i==0){
                        p_flag=0;
                        break;
                    }
                }
                q_flag=1;
                for(i=2;i<sqrt(1.0*q);i++){
                    if(q%i==0){
                        q_flag=0;
                        break;
                    }
                }
            }while(p_flag*q_flag==0);
            printf("%d+%d\n",p,q);
        }
    }
    return 0;
}