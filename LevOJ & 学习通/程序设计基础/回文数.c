#include<stdio.h>
int main(){
    int a,b,t=0;
    int A;
    while(scanf("%d",&a)!=EOF){
        A=a;
        while(a!=0){
            t=t*10+a%10;
            a=a/10;
        }
        if(A==t){
            printf("Yes\n",A);
        }else{
            printf("No\n",A);
        }
        t=0;
    }
    return 0;
}