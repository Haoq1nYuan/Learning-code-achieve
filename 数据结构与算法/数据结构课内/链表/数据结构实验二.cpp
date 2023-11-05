# include <iostream>
# define ElemType int 

using namespace std;

typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode, *linkList;

// 使用尾插法创建单链表
void CreateList_L (linkList &L, int num)
{
    L = new LNode;
    L -> next = NULL;
    linkList pl = L;

    int data;
    for (int i = 1; i <= num; i++)
    {
        cin >> data;
        linkList p = new LNode;
        p -> data = data;
        p -> next = NULL;
        pl -> next = p;
        pl = p;
    }
}

// 合并两个非递减链表
void MergeList_L (linkList &La, linkList &Lb, linkList &Lc)
{
    linkList pa = La -> next;
    linkList pb = Lb -> next;
    Lc = La;
    linkList pc = Lc;

    while (pa && pb)
        if (pa -> data <= pb -> data)
        {
            pc -> next = pa;
            pc = pa;
            pa = pa -> next;
        }
        else
        {
            pc -> next = pb;
            pc = pb; 
            pb = pb -> next;
        }
    
    pc -> next = pa ? pa : pb;
}

// 删除链表中重复元素: 2种方式
void PurgeList_L (linkList &Lc)
{
    linkList pc = Lc -> next;

    while (pc)
    {
        linkList q = pc -> next;

        while (q && q -> data == pc -> data)
        {
            linkList r = q;
            q = r -> next;
            delete r;
            pc -> next = q;
        }

        pc = pc -> next;
    }

    // while (pc && pc -> next)
    //     if (pc -> data == pc -> next -> data)
    //     {
    //         linkList r = pc -> next;
    //         pc -> next = r -> next;
    //         delete r;
    //     }
    //     else pc = pc -> next;
}

// 输出链表元素
void ShowList_L (linkList &L)
{
    linkList pL = L -> next;

    while (pL)
    {
        cout << pL -> data << ' ';
        pL = pL -> next;
    }

    cout << endl;
}

int main ()
{
    linkList La, Lb, Lc;    

    CreateList_L(La, 5);
    CreateList_L(Lb, 6);

    

    MergeList_L(La, Lb, Lc);

    cout << "合并后的链表元素为：" << endl; 
    ShowList_L(Lc);

    PurgeList_L(Lc);

    cout << "去重后的链表元素为：" << endl;
    ShowList_L(Lc);

    return 0;
}
