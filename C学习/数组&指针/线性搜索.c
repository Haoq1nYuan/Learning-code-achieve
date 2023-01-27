#include<stdio.h>

int search(int key,int a[],int len){
    int ret=-1;
    for(int i=0;i<len;i++){
        if(key==a[i]){
            ret=i;
            break;
        }  
    }
    return ret;
}

int main(){
    int k;
    scanf("%d",&k);
    int a[]={1,3,4,512,14,23,6,9,45};
    int r=search(k,a,sizeof(a)/sizeof(a[0]));
    if(r==-1){
        printf("%d不存在\n",k);
    }else{
        printf("%d在第%d个位置上\n",k,r);
    }
    return 0;
}