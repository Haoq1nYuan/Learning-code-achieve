#include<stdio.h>

typedef union{
    int i;
    char ch[sizeof(int)];
}CHI;

int main(int argc,char const *argv[]){
    CHI chi;
    int i;
    chi.i=1234;
    for(i=0;i<sizeof(int);i++){
        printf("%02hhX",chi.ch[i]);   //输出为D2040000，因为x86系统是小端系统，低位在前，1234转换为16进制后成为0x04D2
    }
    printf("\n");
    return 0;   
}