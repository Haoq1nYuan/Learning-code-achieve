#include<stdio.h>
#include<string.h>
#define N 1000 
#define M 1000
char a[N];
char b[M];
int main(){
    int i,j,count=0,box;
    gets(a);
    gets(b);
    for(i=0;i<strlen(a);i++){
        box=0;
        for(j=i;a[j]==b[box]&&box<strlen(b);j++){
            box++;
        }
        if(box==strlen(b)){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}