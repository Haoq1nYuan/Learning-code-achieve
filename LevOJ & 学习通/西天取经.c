#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int k,max,cost,total=0;
        while(n--){
            max=0;
            scanf("%d",&k);
            while(k--){
                scanf("%d",&cost);
                max=cost>max?cost:max;
            }
            total+=max;
        }
        printf("%d\n",total);
    }
    return 0;
}