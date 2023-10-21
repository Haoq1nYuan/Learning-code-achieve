# include <iostream>

# define LIST_INIT_SIZE 100
# define ElemType int

using namespace std;

typedef struct
{
    ElemType * elem;
    int length;
} SqList;

void InitList_Sq (SqList &L, int num[], int len) 
{
    L.elem = new ElemType[LIST_INIT_SIZE];
    L.length = 0;

    for (int i = 0; i < len; i++)
    {
        L.elem[i] = num[i];
        L.length ++;
    }
}

void ListInsert_Sq (SqList &L, int var, int a)
{
    L.length ++;
    for (int i = L.length - 1; i > var; i--)
        L.elem[i] = L.elem[i - 1];
    
    L.elem[var] = a;
}

void ListJoin_Sq (SqList &L1, SqList &L2)
{
    int i = 0, j = 0;
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

void Show_Sq (SqList &L)
{
    for (int i = 0; i < L.length; i++) cout << L.elem[i];
    cout << endl;
}

int main ()
{
    SqList L1, L2, L;
    int num1[5] = {1, 3, 5, 7, 9};
    int num2[3] = {2, 3, 6};

    InitList_Sq(L1, num1, 5);
    InitList_Sq(L2, num2, 3);

    ListJoin_Sq(L1, L2);
    
    Show_Sq(L1);

    return 0;
}

