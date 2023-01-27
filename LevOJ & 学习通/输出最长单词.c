#include<stdio.h>
#define N 100
int main(){
    char a[N];
    int i=0,result,length=0,max=0;
    gets(a);
    while(a[i]){
        if(a[i]!=' '){    
            length++;
        }        
        if(a[i]==' '&&a[i-1]){      
            if(max<length){
                max=length;
                result=i;
            }
            length=0;
        }
        i++;
    }
    for(i=result-max;i<result;i++){
        printf("%c",a[i]);
    }
    return 0;
}
