# include <iostream>

# define LIST_INIT_SIZE 100
# define ElemType int

using namespace std;

typedef struct
{
    ElemType * elem;
    int length;
    int listsize;
} SqList;

// key 为值，cin 为键, pos 为操作下标, e 为操作元素，h 为操作方式, flag 表示是否有序
ElemType key;
int num, pos, e;
string h;
bool flag = true;

void InitList_Sq (SqList &L) 
{
    L.elem = new ElemType[LIST_INIT_SIZE];
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
}

void ListInsert_Sq (SqList &L, int var, int a)
{
    L.length ++;
    for (int i = L.length - 1; i > var; i--)
        L.elem[i] = L.elem[i - 1];
    
    L.elem[var] = a;
}

void ListDelet_Sq (SqList &L, int i, ElemType &e)
{
    e = L.elem[i];
    for (int j = i + 1; j < L.length; j++)
        L.elem[j - 1] = L.elem[j];
    
    L.length --;
}

int ListLocate_Sq (SqList L, ElemType e)
{
    int pos = -1;
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == e) pos = i;
    return pos;
}

void Mergelist_Sq (SqList &L1, SqList &L2, bool flag)
{
    int i = 0, j = 0;
    if (flag)
    {
        while (i < L1.length && j < L2.length)
            if (L1.elem[i] < L2.elem[j]) i++;
            else 
            {
                ListInsert_Sq(L1, i, L2.elem[j]);
                j++;
            }

        while (j < L2.length)
        {
            ListInsert_Sq(L1, i, L2.elem[j]);
            j++, i++;
        }
    }
    else
    {
        for (int j = 0; j < L2.length; j++)
            if (ListLocate_Sq(L1, L2.elem[j]) == -1) ListInsert_Sq(L1, L1.length, L2.elem[j]);
    }
}

void Show_Sq (SqList &L)
{
    for (int i = 0; i < L.length; i++) cout << L.elem[i] << ' ';
    cout << endl;
}

int main ()
{
    SqList L1, L2;
    InitList_Sq(L1);
    InitList_Sq(L2);

    // 插入操作
    cout << "请输入你想创建的顺序表长度：";
    cin >> num;
    
    for (int i = 0; i < num; i++)
    {
        cout << "请输入第" << i + 1 << "个元素值：";
        cin >> key;
        if (i > 0 && key < L1.elem[i - 1]) flag = false;
        ListInsert_Sq(L1, i, key);
    }

    //获取操作方式
    cout << "请输入操作方式: ";
    cin >> h;
    while (h != "E")
    {
        if (h == "D") 
        {
            cout << "请输入你想删除的元素位置: ";
            cin >> pos;
            ListDelet_Sq(L1, pos - 1, e);
            cout << "被删除的元素为: " << e << endl;
            cout << "顺序表更新为：";
            Show_Sq(L1);
        }
        else if (h == "S")
        {
            cout << "请输入你想查找的元素: ";
            cin >> key;
            int var = ListLocate_Sq(L1, key) + 1;
            if (var) cout << "该元素在顺序表中的位置为：" << var << endl;
            else cout << "顺序表中没有指定元素" << endl;
        }

        cout << "请输入操作方式: ";
        cin >> h;
    }

    // 合并两个顺序表
    cout << "请输入你想创建的第二个顺序表长度：";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "请输入第" << i + 1 << "个元素值：";
        cin >> key;
        ListInsert_Sq(L2, i, key);
    }
    
    Mergelist_Sq(L1, L2, flag);
    
    cout << "合并结果为：";
    Show_Sq(L1);

    return 0;
}

/*
样例1：
S1：1 3 5 7 9，并删除第2个元素
S2：2 4 5 6 8
有序合并结果：1 2 4 5 5 6 7 8 9

样例2：
S1：1 2 45 6 889，并删除第1个元素
S2：3 2 4 6 77
无序合并结果：2 45 6 889 3 4 77
*/