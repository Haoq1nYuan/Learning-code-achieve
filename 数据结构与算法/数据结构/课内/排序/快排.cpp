#include <iostream>
#include <random>
#include <ctime>

#define ElemType int
#define LIST_INIT_SIZE 100

using namespace std;

int num[LIST_INIT_SIZE], a, b, x;

typedef struct
{
    ElemType * elem;
    int length;
} SqList;

void InitList_Sq (SqList &L, int *num) 
{
    L.elem = new ElemType[LIST_INIT_SIZE];
    L.length = 0;

    for (int i = 0; i < LIST_INIT_SIZE; i++)
    {
        L.elem[i] = num[i];
        L.length ++;
    }
}

void Show_Sq (SqList &L)
{
    cout << "排完序后的顺序表为：" << endl;

    for (int i = 0; i < L.length; i++)
        cout << L.elem[i] << ' ';
    
    cout << endl;
}

void Clear_Sq (SqList &L)
{
    delete L.elem;
    L.length = 0;
}

int Partition (SqList &L, int l, int r, int x = 0x3f3f3f3f)
{
    ElemType pivot;
    if (x == 0x3f3f3f3f) pivot = l;
    else pivot = x;

    while (l < r)
    {
        while (l < r && L.elem[r] >= L.elem[pivot]) r--;
        L.elem[l] = L.elem[r];
        while (l < r && L.elem[l] <= L.elem[pivot]) l++;
        L.elem[r] = L.elem[l];
    }

    L.elem[l] = L.elem[pivot];

    return l;
}

void Qsort (SqList &L, int l, int r)
{
    if (l < r)
    {
        int mid = Partition(L, l, r);
        Qsort(L, l, mid - 1);
        Qsort(L, mid + 1, r);
    }
}

int main ()
{
    SqList l;

    for (int i = 1; i <= 5; i++)
    {
        cout << "请输入数域的左界与右界：";
        cin >> a >> b;

        default_random_engine e;
        uniform_int_distribution<int> u(a, b);  // 生成[a, b]内的整数
        e.seed(time(0));

        for (int i = 0; i < LIST_INIT_SIZE; i++) num[i] = u(e);
    
        InitList_Sq(l, num);

        cout << "请你随机选取顺序表中的一个数做枢轴，请输入[0, 100)范围内的一个数作为索引：";
        cin >> x;
        cout << "你选择的枢轴是num[" << x << "]: " << num[x] << endl;

        int mid = Partition(l, 0, LIST_INIT_SIZE - 1, x);
        Qsort(l, 0, mid - 1);
        Qsort(l, mid + 1, LIST_INIT_SIZE - 1);

        Show_Sq(l);
        Clear_Sq(l);
    }

    return 0;
}

/*
样例1：[1, 100] 56
样例2：[-100, -1] 87
样例3：[1 4] 34
样例4：[100000, 1000000] 67
样例5：[-23, 789] 48
*/