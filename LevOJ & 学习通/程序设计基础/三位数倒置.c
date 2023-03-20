#include <stdio.h>

int main()
{
    int a,b;
    int c,d;

    printf("number=");
    scanf("%d/n",&a);

    b=a/100;
    c=a%10;
    d=a/10%10;
    int result=c*100+d*10+b;

    printf("%d\n",result);

    return 0;
}