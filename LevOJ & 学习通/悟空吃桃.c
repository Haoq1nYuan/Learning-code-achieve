#include<stdio.h>
int set(int n){
    if(n==1){
        return 1;
    }else{
        return 2*(set(n-1)+1);
    }
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",set(n));
    }
    return 0;
}