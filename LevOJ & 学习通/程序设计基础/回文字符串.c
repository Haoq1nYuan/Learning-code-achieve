#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fun(char *);
int main(){
    char str[100];
    gets(str);
    if(fun(str)){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    system("pause");
    return 0;
}

int fun ( char *word ) 
{
    int length=strlen(word);
    int i;
    for(i=0;i<length/2;i++){
        if(word[i]!=word[length-1-i]){
            return 0;
        }    
    }
    return 1;
}