#include<stdio.h>
int main(){
    int n;   
    while(scanf("%d",&n)!=EOF){
        while(n--){
            unsigned long long a,b;
            long long result;
            char ch; 
            scanf("%u%c%u",&a,&ch,&b);
            switch(ch){
                case '+':result=a+b;break;
                case '-':result=a-b;break;
                case '*':result=a*b;break;
                case '/':result=a/b;break;
            }
            printf("%lld\n",result);
        } 
    }
    return 0;
}