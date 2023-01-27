/*如果b等于0，计算结束，a就是最大公约数；
否则，计算a除以b的余数，让a等于b，而b等于那个余数；
回到第一步。

a   b   t
12  18  12
18  12  6
12  6   0
6   0      */

#include<stdio.h>
int main(){
    int a,b;
    int t;
    scanf("%d %d",&a,&b);

    /*  
    t=a%b;//假设a>b
    while(t!=0){
        a=b;
        b=t;
        t=a%b;
        printf("t=%d\n",t);
    }*/

    for(int i=2;i<((a<b)?a:b);i++){
        if(a%i==0&&b%i==0){
            printf("最大公约数是%d\n",i);
        }
    }

    return 0;
}