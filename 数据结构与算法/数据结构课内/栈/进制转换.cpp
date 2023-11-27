#include <iostream>
#define INITSIZE 10

using namespace std;

typedef int Elemtype;

typedef struct
{
    Elemtype data[INITSIZE];
    int top;
    int StackSize;
} SqStack;

void InitStack (SqStack &s)
{
    s.top = 0;
    s.StackSize = INITSIZE;
}

void Push (SqStack &s, Elemtype x)
{
    s.data[s.top++] = x;
}

void Pop (SqStack &s, Elemtype &x)
{
    x = s.data[--s.top];
}

bool StackEmpty (SqStack s)
{
    return s.top == 0;
}

string Conversion (SqStack s, int a, int cet)
{   
    string ans, tem;

    if (!a) 
    {
        ans = '0';
        return ans;
    }

    while (a)
    {
        Push(s, a % cet);
        a /= cet;
    }

    while (!StackEmpty(s))
    {
        Elemtype x;
        Pop(s, x);

        if (x < 10) ans = ans + char(x + '0');
        else ans = ans + char(x + 'A' - 10);
    }

    return ans;
}

int main()
{
    SqStack s;
    InitStack(s);

    int a, n = 5, cet[3] = {2, 8, 16};
    string ans;

    for (int i = 1; i <= 5; i++)
    {
        cout << "请输入第" << i << "个非负十进制数样例：";
        cin >> a; 

        for (int j = 0; j <= 2; j++)
        {
            ans = Conversion(s, a, cet[j]); 
            cout << "转换为" << cet[j] << "进制后的结果为：" << ans << endl;
        }

        cout << endl;
    }

    return 0;
}

/*
                     2      8     16
输入: 12     输出:  1100    14     C
输入：26     输出： 11010    32    1A
输入：100    输出：1100100  144    64
输入：0      输出：   0      0      0
输入：77     输出：1001101  115    4D
*/