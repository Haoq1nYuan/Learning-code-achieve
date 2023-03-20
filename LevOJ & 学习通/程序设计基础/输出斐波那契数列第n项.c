#include<stdio.h>
int main(){
    int n,num1=1,num2=1;
    scanf("%d",&n);
    for(int i=1;i<=n/2;i++){
        num1=num1+num2;
        num2=num2+num1;
    }
    if(n%2){
        printf("%d\n",num1);
    }else{
        printf("%d\n",num2);
    }
    return 0;
}