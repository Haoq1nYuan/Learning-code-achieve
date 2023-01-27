#include<stdio.h>

int set(int i);

int main(){
    int m;
    while(scanf("%d",&m)!=EOF){
        int i,j,max=0;
        for(i=5;i<m-1;i++){
            if(set(i)&&set(i+2)){
                if(max<i){
                    max=i;
                }
            }
        }
        printf("%d %d\n",max,(max+2));
    }
    return 0;
}

int set(int i){
    int k;
    for(k=2;k<i;k++){
        if(i%k==0){
            return 0;
        }
    }
    return 1;
}