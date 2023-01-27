# include<stdio.h>

#include<string.h>

# define N 3

# define M 10

//在下方编一个函数完成三个数（字符串）排序。
void sort(char a[N][M],int line){
    int i=0,j=0;
    char box[M];
    for(i=0;i<line-1;i++){
        for(j=0;j<line-1-i;j++){
            if(strcmp(a[j],a[j+1])<0){
                strcpy(box,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],box);
            }
        }
    }
}

int main() //主函数

{

int i,j;

char a[N][M], t[M];

for(i=0;i<N;i++)

 scanf("%s",a[i]);

sort(a,N);

for(i=0;i<N;i++)

 printf("%s",a[i]);

getchar();getchar();

}