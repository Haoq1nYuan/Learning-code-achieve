#include <stdio.h>
int PrimeNum(int n);                
int main()
{
    int a;
    while(scanf("%d", &a)!=EOF){
        int i=2;
        while(a!=1){
            if(a%i==0&&PrimeNum(i)){
                printf("%d ",i);
                a/=i;
                i=1;
            }
            i++;
        }
        printf("\n");
    }
    return 0;
}

int PrimeNum(int n){                  
    int j;
    for(j = 2; j<n; j++)                 
    {
        if(n%j == 0){
            return 0;
        }
    }
    return 1;
}
