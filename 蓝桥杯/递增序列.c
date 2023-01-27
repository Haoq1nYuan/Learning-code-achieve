#include <stdio.h>
#define N 30 
#define M 50
int main(int argc, char *argv[])
{
  char a[N][M];
  int i,j,count=0,h,s,q;
  for(i=0;i<N;i++){
    gets(a[i]);
  }
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      for(h=j+1;h<M;h++){
        if(a[i][j]<a[i][h]){
          count++;              //横向
        }
      }
      for(h=i+1;h<N;h++){
        if(a[i][j]<a[h][j]){
          count++;              //竖向
        }
      }
      for(q=i+1,s=j+1;q<N&&s<M;q++,s++){
        if(a[i][j]<a[q][s]){
          count++;              //主对角线
        }
      }
      for(q=i+1,s=j-1;q<N&&s>=0;q++,s--){
        if(a[i][j]!=a[q][s]){
          count++;              //副对角线
        }
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
