#include <iostream>
#define Elemtype Treelist

using namespace std;

typedef struct Tree
{
    char data;
    struct Tree *lc, *rc;
} Tree, *Treelist;

typedef struct 
{
    Elemtype data[30];
    int top;
} SqStack;

void InitStack (SqStack &S)
{
    S.top = -1;
}

void Push (SqStack &S, Elemtype x)
{
    S.data[++S.top] = x;
}

void Pop (SqStack &S, Elemtype &x)
{
    x = S.data[S.top--];
}

bool StackEmpty (SqStack S)
{
    return S.top == -1;
}

void CreateBiTree (Treelist &t)
{
    char ch;
    cin >> ch;
    if (ch == '#') t = nullptr;
    else 
    {
        t = new Tree;
        t -> data = ch;
        CreateBiTree(t -> lc);
        CreateBiTree(t -> rc);
    }
}

void preorderTree (Treelist t)
{
    SqStack x;
    InitStack(x);
    Treelist p = t;

    while (p || !StackEmpty(x))
        if (p)
        {
            cout << p -> data << ' ';
            Push(x, p);
            p = p -> lc;
        }
        else
        {
            Pop(x, p);
            p = p -> rc;
        }
}

void inorderTree (Treelist t)
{
    SqStack x;
    InitStack(x);
    Treelist p = t;

    while (p || !StackEmpty(x))
        if (p)
        {
            Push(x, p);
            p = p -> lc;
        }
        else
        {
            Pop(x, p);
            cout << p -> data << ' ';
            p = p -> rc;
        }
}

void postorderTree (Treelist t)
{
    SqStack x;
    InitStack(x);
    Treelist p = t;

    char tag[30] = {'0'};

    while (p || !StackEmpty(x))
        if (p)
        {
            Push(x, p);
            tag[x.top] = '0';
            p = p -> lc;
        }
        else 
        {
            while (tag[x.top] == '1')
            {
                Pop(x, p);
                cout << p -> data << ' ';
            }

            if (x.top == -1) break;

            Pop(x, p);
            Push(x, p);
            p = p -> rc;
            tag[x.top] = '1';
        }
}

int main ()
{
    Treelist T;

    CreateBiTree(T);

    cout << "先序遍历序列为：";
    preorderTree(T);
    cout << endl;

    cout << "中序遍历序列为：";
    inorderTree(T);
    cout << endl;

    cout << "后序遍历序列为：";
    postorderTree(T);
    cout << endl;

    return 0;
}


// ABC##DE#G##F###