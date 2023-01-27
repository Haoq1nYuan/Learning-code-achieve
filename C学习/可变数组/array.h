//构建函数库
#ifndef _ARRAY_H_
#define _ARRAY_H_

//定义Array结构体
typedef struct{
    int *array;   //定义数组指针  
    int size;                                
}Array;  //此处不建议直接定义指针

Array array_create(int init_size);  //创建一个数组
void array_free(Array *a);   //把数组空间回收
int array_size(const Array *a);   //告知数组中还有多少单元可以用
int* array_at(Array *a,int index);  //访问数组中的某个单元
void array_inflate(Array *a,int more_size);  //让数组长大

#endif