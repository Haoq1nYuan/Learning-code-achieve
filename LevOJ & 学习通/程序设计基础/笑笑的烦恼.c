#include<stdio.h>
int main()
{
    int max,min,count,SUM,number;
    double average;
    int score[number];

    for(int count=0;count>=0;count++){
        int i;
        scanf("%d",&i);
        if(i!=-1){
           score[count]=i; 
        }else{
            break;
        }
    }

    printf("%d\n",count+1);

    for(int i=1;i<count+2;i++){
        max=score[0];
        if(max>score[i]){
            max=max;
        }else{
            max=score[i];
        }
    }
    printf("%d\n",max);

    for(int i=1;i<count+2;i++){
        max=score[0];
        if(max<score[i]){
            max=max;
        }else{
            max=score[i];
        }
    }
    printf("%d\n",min);

    for(int i=0;i<count+1;i++){
        SUM+=score[i];
    }
    average=SUM/(count+1);
    printf("%f\n",average);

    return 0;

}