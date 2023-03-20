#include<stdio.h>
#include<math.h>
int main(){
    int a,count=0,num=0;
    scanf("%d",&a);
    while(a){
        if((a%10)%2==0){
            num+=(a%10)*pow(10.0,count);
            count++;
        }
        a/=10;
    }
    printf("%d\n",num);
    return 0;
}