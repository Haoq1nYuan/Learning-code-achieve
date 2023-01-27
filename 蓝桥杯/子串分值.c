#include<stdio.h>
#include<string.h>
#define N 100000
int set(char *,int ,int );
int main(){
    int i,j,box=0,box2=0,result=0;
    char S[N];
	gets(S);
    for(i=1;i<=strlen(S);i++){
        box=i-1;
        for(j=1;j+box<=strlen(S);j++){
            box2=j;
            result+=set(S,box2,box);
        }
    }
    printf("%d\n",result);
    return 0;
}
/* int set(char *p,int n,int box){
    int flag=1,i,j,count=0;
    for(i=n-1;i<=n-1+box;i++){
        for(j=n-1;j<=n-1+box;j++){
            if(p[i]==p[j]&&i!=j)
                flag=0;               //此种方法会造成超时
        }
        if(flag)
            count++;
        flag=1;
    }
    return count;
} */

int set(char *p,int n,int box){
    char BOX[100000];
    memset(BOX,0,sizeof(BOX));
    int result=0,i;
    for(i=n-1;i<=n-1+box;i++){
        BOX[p[i]-'0']++;
    }
    for(i=n-1;i<=n-1+box;i++){
        if(BOX[p[i]-'0']==1){
            result++;
        }
    }
    return result;
}   

