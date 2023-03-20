#include<stdio.h>
#include<string.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        getchar();
        char a[n][50],BOX[50];
        memset(a,0,sizeof(a));
        int i,j,box;
        for(i=0;i<n;i++){
            gets(a[i]);
            if(a[i][0]=='C'&&a[i][1]=='h'&&a[i][2]=='i'&&a[i][3]=='n'&&a[i][4]=='a'){
                box=i;
            }
        }
        strcpy(BOX,a[box]);
        strcpy(a[box],a[n-1]);
        strcpy(a[n-1],BOX);

        memset(BOX,0,sizeof(BOX));
        for(i=0;i<n-2;i++){
            for(j=0;j<n-2-i;j++){
                if(strcmp(a[j],a[j+1])>0){
                    strcpy(BOX,a[j]);
                    strcpy(a[j],a[j+1]);
                    strcpy(a[j+1],BOX);
                    memset(BOX,0,sizeof(BOX));
                }
            }
        }
        for(i=0;i<n;i++){
            puts(a[i]);
        }
    }
    return 0;
}