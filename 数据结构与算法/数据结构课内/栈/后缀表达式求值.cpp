#include <iostream>
#define INITSIZE 20

using namespace std;

typedef int Elemtype;

typedef struct 
{
    Elemtype data[INITSIZE];
    int top;
} SqStack;

void InitStack (SqStack &S)
{
    S.top = -1;
}

void PushStack (SqStack &S, Elemtype x)
{
    S.data[++S.top] = x;
}

void PopStack (SqStack &S, Elemtype &x)
{
    x = S.data[S.top--];
}

int main()
{
    SqStack s;
    InitStack(s);

    string a;
    cout << "请输入一串后缀表达式：" << endl;
    cin >> a;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= '0' && a[i] <= '9') PushStack(s, int(a[i] - '0'));
        else if (a[i] == '+') 
        {
            int x, y;
            PopStack(s, x);
            PopStack(s, y);
            PushStack(s, x + y);
        }
        else if (a[i] == '-')
        {
            int x, y;
            PopStack(s, x);
            PopStack(s, y);
            PushStack(s, x - y);
        }
        else if (a[i] == '*')
        {
            int x, y;
            PopStack(s, x);
            PopStack(s, y);
            PushStack(s, x * y);
        }
        else
        {
            int x, y;
            PopStack(s, x);
            PopStack(s, y);
            PushStack(s, x / y);
        }
    }

    cout << "最后结果为：" << s.data[0] << endl;

    return 0;
}