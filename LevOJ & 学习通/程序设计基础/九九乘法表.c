#include<stdio.h>
int main(){
    int i,j;
    printf("\n------------------------------------\n");
    printf(" ");
    for(i=1;i<10;i++){
        printf("%4d",i);
    }
    printf("\n------------------------------------\n");
    for(i=1;i<10;i++){
        printf("%d",i);
        for(j=1;j<10;j++){
            printf("%4d",i*j);
        }
        printf("\n");
    }
    printf("\n------------------------------------\n");
    return 0;
}