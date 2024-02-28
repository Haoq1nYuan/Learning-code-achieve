#include <iostream>
typedef int ElemType;

using namespace std;

typedef struct StackNode
{
    StackNode* next;
    ElemType data; 
} StackNode;

void Init (StackNode *S)
{
    S = NULL;
}

bool Push (StackNode *S, ElemType data)
{
    StackNode *p = new StackNode;
    p->data = data;
    p->next = S;
    S = p;
    return true;
}

bool Pop (StackNode *S, ElemType &data)
{
    if (!S) return false;
    StackNode *p = S;
    data = S->data;
    S = S->next;
    delete p;
    return true;
}

bool getTop (StackNode *S, ElemType &data)
{
    if (!S) return false;
    data = S->data;
    return true;
}

int main ()
{
    StackNode *S;
    Init(S);


    return 0;
}