#include<stdio.h>
int main(){
    int n,num1=1,num2=1;
    int count=2;
    scanf("%d",&n);
        printf("%12d",num1);
        printf("%12d",num2);
    for(int i=1;i<n/2;i++){
        num1=num1+num2;
        num2=num2+num1;
        printf("%12d",num1);
        printf("%12d",num2);
        count+=2;
        if(count%4==0){
            printf("\n");
        }
    }
    return 0;
}