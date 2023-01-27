#include<stdio.h>
int a[5000];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int t,count,i,j,box,num;
        scanf("%d",&t);
        count=0;
        while(n--){
            scanf("%d",&a[count]);
            count++;
        }
        for(i=0;i<count;i++){
            for(j=0;j<count-1-i;j++){
                if(a[j]>a[j+1]){
                    box=a[j+1];
                    a[j+1]=a[j];
                    a[j]=box;
                }
            }
        }
        num=0;
        for(i=0;i<count;i++){
            t-=a[i];
            if(t<0){
                break;
            }else{
                num++;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}