#include <iostream>
#define INITSIZE 100
#define ADDSIZE 10

typedef float ElemType;

using namespace std;

typedef struct
{
	ElemType *base;
	ElemType *top;
	int StackSize;
} Stack;

void InitStack (Stack &s)
{
	s.base = new ElemType[INITSIZE];
	s.top = s.base;
	s.StackSize = INITSIZE;
}

void Push (Stack &s, ElemType x)
{
	*s.top++ = x;
}

void Pop (Stack &s)
{
	--s.top;
}

ElemType Top (Stack s)
{
	return *(s.top - 1);
}

bool IsEmpty (Stack s)
{
	return s.top == s.base;
}

bool IsFull (Stack s)
{
	return s.top - s.base == s.StackSize;
	// 两个指向同一数组的指针相减的结果
	// 是他们指向的元素在数组中的下标之差 
}

ElemType operate (ElemType a, ElemType b, char c)
{
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else if (c == '*') return a * b;
	else if (c == '/') return a / b;
}

int compare (char a, char top)
{
	if (top == '#') 
        if (a == '#') return 0;
        else return 1;
	else if (top == '(') 
        if (a == ')') return 0;
        else return 1;
	else if (top == ')') return -1;
	else if (top == '/' || top == '*')
		if (a == '(') return 1;
		else return -1;
	else if (top == '-' || top == '+')
		if (a == '(' || a == '*' || a == '/') return 1;
		else return -1;
}

int main ()
{
	Stack optr, opnd;
	InitStack(optr);
	InitStack(opnd);
	Push(optr, '#');
	
	string a;
	cout << "请输入一段中缀表达式：" << endl;
	cin >> a;
	a = a + '#';

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= '0' && a[i] <= '9') 
        {
            int k = i + 1, sum = int(a[i] - '0');
        
            while (a[k] >= '0' && a[k] <= '9') sum = sum * 10 + int(a[k++] - '0');
            if (k != i + 1) i = k - 1;
        
            Push(opnd, sum);
        }
		else
		{
			char top = char(Top(optr));
		
			int result = compare(a[i], top); // a[i] > top -> 1, a[i] = top -> 0, a[i] < top -> -1
	
			if (result == -1)     
			{
                char top_n = top;
                do
                {
                    Pop(optr);
                    ElemType y = Top(opnd);
                    Pop(opnd);
                    ElemType x = Top(opnd);
                    Pop(opnd);

                    ElemType ans = operate(x, y, top_n);
                    Push(opnd, ans);

                    top_n = char(Top(optr));
                } while (compare(a[i], top_n) == -1);

                if (!compare(a[i], top_n)) Pop(optr);
                if (compare(a[i], top_n) == 1) Push(optr, a[i]);
			}
			else if (!result) Pop(optr);
			else if (result == 1) Push(optr, a[i]);
        }
	}
	
	cout << "表达式求值结果为：" << Top(opnd) << endl; 
	
	return 0;
}

/*
样例输入       样例输出
1+2*3            7 
7*(1+2/3)-43  -31.3333
56*8-7*(5-8)    469
*/
