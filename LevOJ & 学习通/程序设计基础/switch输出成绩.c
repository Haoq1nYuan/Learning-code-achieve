#include<stdio.h>
int main(){
    int a;
    while(scanf("%d",&a)!=EOF){
        if(a<0||a>100){
            printf("输入成绩错误。\n");
        }else{
            switch(a/10){
                case 10:
                case 9:printf("成绩为：%d，成绩等级：优\n",a);break;
                case 8:printf("成绩为：%d，成绩等级：良\n",a);break;
                case 7:printf("成绩为：%d，成绩等级：中\n",a);break;
                case 6:printf("成绩为：%d，成绩等级：合格\n",a);break;
                case 5:
                case 4:
                case 3:
                case 2:
                case 1:
                case 0:printf("成绩为：%d，成绩等级：不及格\n",a);break;
            }
        }
    }
    return 0;
}
