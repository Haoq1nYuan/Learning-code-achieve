#include<stdio.h>
#include<string.h>
int a[1000],b[1][1000];
int main(){
    int num,i,j,k,box; 
    while(1){
        scanf("%d",&num);
        if(num==-1){  
            break;
        }else{
            a[num]++;
        }
    }
    j=1;
    for(i=1;i<1000;i++){
        if(a[i]!=0){
            b[0][j]=i;
            b[1][j]=a[i];
            j++;
        }
    }
    for(i=1;i<j;i++){
        for(k=1;k<j-i;k++){
            if(b[1][k]>b[1][k+1]){
                box=b[1][k];
                b[1][k]=b[1][k+1];
                b[1][k+1]=box;
                box=0;
                box=b[0][k];
                b[0][k]=b[0][k+1];
                b[0][k+1]=box;
                box=0;
            }
        }
    }
    for(i=1;i<j;i++){
        printf("%d %d\n",b[0][i],b[1][i]);
    }
    return 0;
}