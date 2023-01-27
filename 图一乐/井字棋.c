#include<stdio.h>

int main(){
    const int size=3;
    int board[size][size];
    int i,j;
    int numOfX;//   numOfX输入1
    int numOfO;//   numOfO输入0
    int result=-1;//   -1:没人赢，1:X赢，0:O赢

    //读入矩阵
    /*for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("请输入第%d行第%d列的数字\n",i,j);
            scanf("%d",&board[i][j]);
        }
    }*/  //此种只能按照特定顺序读入数字

    for(int count=1;count<10;count++){
        printf("请选择你想输入的位置(行坐标 列坐标)：\n");
        scanf("%d %d",&i,&j);
        printf("请输入0或1\n");
        scanf("%d",&board[i][j]);
    }//   此种可以从任意位置读入

    //检查行
    for(i=0;i<size&&result==-1;i++){
        numOfO=numOfX=0;
        for(j=0;j<size;j++){
            if(board[i][j]==1){
                numOfX++;
            }else{         
                numOfO++;
            }
        }
        if(numOfO==size){
            result=0;
        }else if(numOfX==size){
            result=1;
        }
    }

    //检查列
    if(result==-1){
        for(i=0;i<size&&result==-1;i++){
            numOfO=numOfX=0;
            for(j=0;j<size;j++){
                if(board[i][j]==1){
                    numOfX++;
                }else{
                    numOfO++;
                }
            }
            if(numOfO==size){
                result=0;
            }else if(numOfX==size){
                result=1;
            }
        }
    }

    //检查正对角线
    if(result==-1){
        numOfO=numOfX=0;
        for(i=0;i<size;i++){
            if(board[i][j]==1){
                numOfX++;
            }else{
                numOfO++;
            }
        }
        if(numOfO==size){
            result=0;
        }else if(numOfX==size){
            result=1;
        }
    }

    //检查反对角线
    if(result==-1){
        numOfO=numOfX=0;
        for(i=0;i<size;i++){
            if(board[i][size-i-1]==1){
                numOfX++;
            }else{
                numOfO++;
            }
        }
    }

    //输出结果
    if(result==1){
        printf("玩家X赢\n");
    }else if(result==0){
        printf("玩家O赢\n");
    }else if(result==-1){
        printf("平局\n");
    }
    return 0;
}