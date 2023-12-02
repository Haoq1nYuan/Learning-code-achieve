#include <iostream>

using namespace std;

typedef struct Tree
{
    char data;
    struct Tree *lc, *rc;
} Tree, *Treelist;

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
    if (!t) return;
    else
    {
        cout << t -> data << ' ';
        preorderTree(t -> lc);
        preorderTree(t -> rc);
    }
}

void inorderTree (Treelist t)
{
    if (!t) return;
    else 
    {
        inorderTree(t -> lc);
        cout << t -> data << ' ';
        inorderTree(t -> rc);
    }
}

void postorderTree (Treelist t)
{
    if (!t) return;
    else 
    {
        postorderTree(t -> lc);
        postorderTree(t -> rc);
        cout << t -> data << ' ';
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