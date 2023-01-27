#include <stdio.h>
int main(){
    int i,j,k,l,m;
    char c[]="love"; 
    for (i=1;i<=5;i++)
        printf("\n"); 
    for(i=1;i<2;i++){
        for(j=1;j<=34-(i-1)*2;j++)
            printf(" ");
        for(k=1;k<3+i;k++)
            printf("%s",c);
        for(l=1;l<19-4*(i-1);l++)
            printf(" ");
        for(m=1;m<3+i;m++)
            printf("%s",c);
        printf("\n");
    }
    for(i=1;i<=3;i++){ 
        for(j=1;j<=32-2*i;j++)
            printf(" ");
        for(k=1;k<=4+i;k++)
            printf("%s", c);
        for(l=1;l<=13-4*i+1;l++)
            printf(" "); 
        for(m=1;m<=4+i;m++)
            printf("%s",c);
        printf("\n"); 
    }  
    for(i=1;i<=7;i++){
        for(j=1;j<=24+1;j++)
            printf(" ");  
        for(k=1;k<=15;k++)
            printf("%s",c); 
        printf("\n");  
    }
    for(i=7;i>=2;i--){ 
        for(j=1;j<=40-2*i+1;j++)
            printf(" "); 
        for(k=1;k<=7+i;k++)
            printf("%s", c);
        printf("\n"); 
    }
    for(i=5;i>=2;i--){
        for(j=1;j<=41+(5-i)*4;j++)
            printf(" "); 
        for(k=1;k<=7-(5-i)*2;k++)
            printf("%s",c);
        printf("\n");  
    }
    for(i=1;i<5;i++)
        printf(" \n");
    return 0;
}
