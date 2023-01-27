#include<stdio.h>
int a[100000];
int cost[100000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int m,n,i=1,len,j;
        scanf("%d",&m);
        scanf("%d",&n);
        while(n--){
            scanf("%d",&a[i]);
            i++;
        }
        cost[1]=a[1];
        cost[2]=a[2];
        for(j=3;j<i;j++){
            cost[j]=a[j]+((cost[j-1]>cost[j-2])?cost[j-2]:cost[j-1]);
        }
        if(m>cost[j-1]){
            printf("%d\n",m-cost[j-1]);
        }else{
            printf("Can't get the top!\n");
        }
    }
    return 0;
}