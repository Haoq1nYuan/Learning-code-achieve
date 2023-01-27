#include<stdio.h>

struct point{
    int x;
    int y;
};

struct rectangle{
    struct point p1;
    struct point p2;
};

void printRect(struct rectangle r){
    printf("<%d,%d>to<%d,%d>\n",r.p1.x,r.p1.y,r.p2.x,r.p2.y);
}

int main(){
    int i;
    struct rectangle rects[]={
        {{1,2},{3,4}},
        {{5,6},{7,8}}
    };
    for(i=0;i<2;i++){
        printRect(rects[i]);
    }
    return 0;
}