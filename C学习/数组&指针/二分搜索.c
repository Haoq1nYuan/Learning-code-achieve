#include<stdio.h>

int search(int key,int *a,int len){
    int ret=-1;
    int left=0;
    int right=len-1;
    while(right>left){
        int mid=(left+right)/2;
        if(*(a+mid)==key){
            ret=mid;
            break;
        }else if(*(a+mid)>key){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
}

int main(){
    int k;
    scanf("%d",&k);
    int a[]={1,3,5,8,10,23,45,56,66,70,};
    int ret=search(k,a,sizeof(a)/sizeof(a[0]));
    printf("%d在第%d个位置上\n",k,ret+1);
    return 0;
}