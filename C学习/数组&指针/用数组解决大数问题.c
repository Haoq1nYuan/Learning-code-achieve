#include<stdio.h>
int main(){
    int n=0;
    scanf("%d",&n);
    int BigNumber[n];

    for(int i=0;i<n;i++){
        BigNumber[i]=0;
    }

    BigNumber[0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            BigNumber[j]*=2;   
        }
        for(int k=0;k<n;k++){
            if(BigNumber[k]>9){
                BigNumber[k+1]++;
                BigNumber[k]=BigNumber[k]%10;
            }
        }
    }

    BigNumber[0]-=1;

    for(int i=0;i<1;i++){
        for(int j=0;j<n;j++){
            BigNumber[j]*=2;
        }
        for(int k=0;k<n;k++){
            if(BigNumber[k]>9){
                BigNumber[k+1]++;
                BigNumber[k]=BigNumber[k]%10;
            }      
        }
    }

    for(int i=n-1;i>=0;i--){
        if(BigNumber[i]>0){
            for(int j=i;j>=0;j--){
                printf("&d",BigNumber[j]);
            }
            break;
        }
    }
    return 0;
}
