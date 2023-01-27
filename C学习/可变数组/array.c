#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"array.h"

const int BLOCK_SIZE=20;

//typedef struct{
//    int *array;
//    int size;
//}Array;

//创建一个数组
Array array_create(int init_size){
    Array a;
    a.size=init_size;
    a.array=(int*)malloc(sizeof(int)*a.size);
    return a;//返回Array的变量本身而非指针
}

//把数组空间回收
void array_free(Array *a){
    free(a->array);
    a->array=NULL;
    a->size=0;
}

//告知数组中还有多少单元可以用
//封装（将a的size保护起来）
int array_size(const Array *a){
    return a->size;     //函数将内部的运算保护起来了
}

//访问数组中的某个单元
int* array_at(Array *a,int index){
    if(index>=a->size){
        array_inflate(a,(index/BLOCK_SIZE+1)*BLOCK_SIZE-a->size);
    }
    return &(a->array[index]);
}

/* int array_get(const Array *a,int index){
    return a->array[index];
}
 
void array_set(Array *a,int index,int value){
    a->array[index]=value;
} */

//让数组长大
void array_inflate(Array *a,int more_size){
    int *p=(int*)malloc(sizeof(int)*(a->size+more_size));
    int i;
    for(i=0;i<a->size;i++){
        p[i]=a->array[i];
    }
    free(a->array);
    a->array=p;
    a->size+=more_size;
}

int main(int argc,char const *argv[]){
    Array a=array_create(100);
    printf("%d\n",array_size(&a));

    //此处直接定义指针，可以直接赋值
    *array_at(&a,0)=10;   
    printf("%d\n",*array_at(&a,0));

    //此处使用另一种方式去给指定位置赋值
    /* array_set(&a,0,10);
    printf("%d\n",array_get(&a,0)); */
    
    int number=0;
    int cnt=0;
    while(number!=-1){
        scanf("%d",&number);  
        if(number!=-1){
            *array_at(&a,cnt++)=number;            
        }
    }
    array_free(&a);
    return 0;
}