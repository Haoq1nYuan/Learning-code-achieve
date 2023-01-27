//拷贝结构方法
/*#include<stdio.h>

struct point{
    int x;
    int y;
};

struct point getStruct(void);
void output(struct point);

int main(){
    struct point y={0,0};
    y=getStruct();
    output(y);
}

struct point getStruct(void){
    struct point p;
    scanf("%d",&p.x);
    scanf("%d",&p.y);
    printf("%d,%d\n",p.x,p.y);
    return p;
}

void output(struct point p){
    printf("%d,%d",p.x,p.y);
}*/

//指针方法
#include<stdio.h>

struct point{
    int x;
    int y;
};

struct point* getStruct(struct point *);
void output(struct point);
void print(const struct point *p);

int main(){
    struct point y={0,0};
    //第一种输入输出方式
    getStruct(&y);
    output(y);       
    //第二种输入输出方式 
    output(*getStruct(&y));  //这里*getStruct(&y)就是一个变量，可以这样写：*getStruct(&y)=(struct point){1,2}
    //第三种输入输出方式
    print(getStruct(&y));
    return 0;
}

struct point* getStruct(struct point *p){
    scanf("%d",&p->x);
    scanf("%d",&p->y);
    printf("%d,%d\n",p->x,p->y);
    return p;
}

void output(struct point p){
    printf("%d,%d\n",p.x,p.y);
}

void print(const struct point *p){
    printf("%d,%d\n",p->x,p->y);
}