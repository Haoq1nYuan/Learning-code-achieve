#include<stdio.h>
#include<string.h>
int main(){
    char a[1000];
    gets(a);
    int num=0,i,len;
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]!=' '&&a[i+1]==' '){
            num++;
        }
        if(a[i]!=' '&&a[i+1]=='\0'){
            num++;
        }
    }
    printf("%d\n",num);
    return 0;
}