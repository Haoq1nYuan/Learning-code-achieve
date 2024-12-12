#include<stdio.h>
#include<stdlib.h>

#define PAGE_SIZE 4096 //页表中每页 4KB
#define PAGE_NUM 1024 //总共 1024 个页表项
#define MEMORY_NUM 4 //物理内存块数
#define FAULT_ERROR -1 //发生缺页
#define PAGEOVER_ERROR -2 //地址越界错误

typedef struct {
    //unsigned shift:12 ; //位移量，页内地址
    unsigned pageID:12 ; //页号
    unsigned status:1 ; //状态位
    unsigned modify:1 ; //修改位
    unsigned access:8 ; //访问字段
    unsigned disk_add; //外存地址
    unsigned mem_add; //物理块号
} PageTable;

PageTable Page_table[PAGE_NUM];
typedef unsigned long ADDRESS; //用作地址类型
int Memory[MEMORY_NUM] = {0}; //模拟物理内存块
int fifo_queue[MEMORY_NUM]; // FIFO 队列，保存当前在物理内存中的页号 
int queue_front = 0; // 队列头 
int queue_rear = 0; // 队列尾

//页表初始化
void Init_Pagetable (PageTable *Page_table) {
    for (int i=0;i<PAGE_NUM;i++) { //i 对应页号
        Page_table[i].pageID=0;
        //Page_table[i].shift=0;
        Page_table[i].status=0;
        Page_table[i].modify=0;
        Page_table[i].access=0;
    }

    //假设把页号 0~3 放入了物理内存中
    for (int j=0; j<MEMORY_NUM; j++) {
        Page_table[j].pageID=j;
        Page_table[j].status=0x1;
        Page_table[j].access|=128; //最高位置 1，按位或 0x80
        Page_table[j].mem_add=j; //假设存入编号为 j 的物理块内
        Memory[j]=j; //模拟，物理内存中用页号填充
    }
}

//模拟设备右移页表中的访问字段 access
void RightShift_Access() {
    for(int i=0;i<PAGE_NUM;i++) {
        if (Page_table[i].status == 0x1)
            Page_table[i].access = Page_table[i].access >> 1;
    }
}

//在页表中查找是否某个地址的状态
int Search_Pagetable (unsigned page_no) {
    if (Page_table[page_no].status == 0x1) {
        Page_table[page_no].access |= 128;
        return page_no;
    } else {
        return FAULT_ERROR;
    }
}

//地址变换：把普通地址转换为页号与页内地址，返回页号（页内地址不参与本次实验）
unsigned Transfer2PageNo(ADDRESS addr) {
    unsigned page_no = addr / PAGE_SIZE;
    printf("page_no=%d\n", page_no);

    if(page_no>=PAGE_NUM)
        return PAGEOVER_ERROR; //如果页号超过了最大页号，返回越界错误
    return page_no;
}

// FIFO 页面置换算法 
bool FIFO(unsigned page_no) { 
    int replace_page = fifo_queue[queue_front]; // FIFO 队列头部的页号即为被替换页 
    queue_front = (queue_front + 1) % MEMORY_NUM; // 更新队列头位置 

    printf("被淘汰页面编号= %d\n", replace_page); 
    printf("置换前物理块内容：%d\n", Memory[Page_table[replace_page].mem_add]);
    
    // 执行页面置换     
    Page_table[replace_page].status = 0; 
    Page_table[page_no].status = 0x1; 
    Page_table[page_no].access |= 128; // 最高位置1 
    Page_table[page_no].mem_add = Page_table[replace_page].mem_add; 
    Memory[Page_table[page_no].mem_add] = page_no; // 更新物理内存块的内容 
    fifo_queue[queue_rear] = page_no; // 将新的页号加入 FIFO 队列尾部 
    queue_rear = (queue_rear + 1) % MEMORY_NUM; // 更新队列尾位置 
    
    printf("置换后物理块内容：%d\n", Memory[Page_table[page_no].mem_add]); 
    return true;
}

// LRU 页面置换算法
bool LRU (unsigned page_no) {
    // 找到最少访问的页面替换
    int min_access = 256;
    int replace_page = -1;

    for (int i = 0; i < PAGE_NUM; i++) {
        if (Page_table[i].status == 0x1 && Page_table[i].access < min_access) {
            min_access = Page_table[i].access;
            replace_page = i;
        }
    }   

    if (replace_page != -1) {
        printf("被淘汰页面编号= %d\n", replace_page);
        printf("置换前物理块内容：%d\n", Memory[Page_table[replace_page].mem_add]); 
        // 执行页面置换 
        Page_table[replace_page].status = 0; 
        Page_table[page_no].status = 0x1; 
        Page_table[page_no].access |= 128; // 最高位置1 
        Page_table[page_no].mem_add = Page_table[replace_page].mem_add; 
        Memory[Page_table[page_no].mem_add] = page_no; // 更新物理内存块的内容 
        printf("置换后物理块内容：%d\n", Memory[Page_table[page_no].mem_add]); 
        return true;
    } else {
        return false;
    }
}

//缺页中断处理，同时调用页面置换算法
void Fault_Interrupt (unsigned page_no, bool(*Schedule)(unsigned page_no)) {
    //首先保护 CPU 现场，此处不需要实现
    bool result = Schedule(page_no); //Schedule 是传递过来的函数指针
    if (result)
        printf("置换成功!\n");
}

int main () {
    //初始化
    Init_Pagetable(Page_table);

    //访问字段右移
    //对访问字段右移操作的测试
    printf("Before shifting, Page_table[0].disk_add=%d\n", Page_table[0].disk_add);
    RightShift_Access();
    printf("Page_table[0].access=%d\n", Page_table[0].access);
    printf("Page_table[0].disk_add=%d\n", Page_table[0].disk_add);

    //此处修改为循环处理多个访问请求，以实现一个地址序列的存储管理
    // unsigned page_no;
    // page_no = Transfer2PageNo(0xFF00);
    // printf("%d belongs to page_no:%d\n",0xFF00, page_no);
    // int result;
    // result = Search_Pagetable(0); //先访问一次 0 号页面，更新修改其 access 字段
    // result = Search_Pagetable(page_no);
    // printf("result=%d\n", result);
    // if (result == FAULT_ERROR) {
    //     //如果缺页，调用缺页中断处理程序
    //     Fault_Interrupt(page_no,LRU);
    // }
    ADDRESS addresses[] = {0xFF00, 0X2000, 0X8000, 0X12000};
    int num_requests = sizeof(addresses) / sizeof(addresses[0]);

    for (int i = 0; i < num_requests; i++) {
        unsigned page_no = Transfer2PageNo(addresses[i]);
        printf("%lu belongs to page_no:%d\n", addresses[i], page_no);
        int result = Search_Pagetable(page_no);
        printf("result=%d\n", result);
        if (result == FAULT_ERROR) {
            Fault_Interrupt(page_no, LRU);
        }
    }

    return 0;
}