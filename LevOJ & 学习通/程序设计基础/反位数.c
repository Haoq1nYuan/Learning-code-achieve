#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int t=0,p=0;
    while(a!=0){
        t=t*10+a%10;
        a=a/10;
    }
    printf("%d\n",t);
    while(b!=0){
        p=p*10+b%10;
        b=b/10;
    }
    printf("%d\n",p);
    return 0;
}

/*#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int t=0;
    while(a!=0){
        t=t*10+a%10;
        a=a/10;
    }
    printf("%d\n",t);
}*/