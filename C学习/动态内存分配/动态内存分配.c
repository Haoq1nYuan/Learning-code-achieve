#include<stdio.h>
#include<stdlib.h>
int main(void){
    int number;
    int i;
    int *a;
    printf("ÊäÈëÊıÁ¿£º");
    scanf("%d",&number);
    a=(int*)malloc(number*sizeof(int));
    for(i=0;i<number;i++){
        scanf("%d",&a[i]);
    }
    for(i=number-1;i>=0;i--){
        printf("%d",a[i]);
    }
    free(a);
    return 0;
}