# include <iostream>

# define LIST_INIT_SIZE 100
# define ElemType char

using namespace std;

typedef struct
{
    ElemType * elem;
    int length;
} SqList;

void InitList_Sq (SqList &L, string a) 
{
    L.elem = new ElemType[LIST_INIT_SIZE];
    L.length = 0;

    for (int i = 0; i < a.size(); i++)
    {
        L.elem[i] = a[i];
        L.length ++;
    }
}

void Show_Sq (SqList &L)
{
    for (int i = 0; i < L.length; i++) cout << L.elem[i];
    cout << endl;
}

int main ()
{
    SqList L;
    string s = "ajcniydu";

    InitList_Sq(L, s);
    
    Show_Sq(L);

    return 0;
}

