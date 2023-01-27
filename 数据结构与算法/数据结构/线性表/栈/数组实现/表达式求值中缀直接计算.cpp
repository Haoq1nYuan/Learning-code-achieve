//https://www.acwing.com/problem/content/3305/

//中缀表达式直接求值
//假设一颗二叉树，节点都是运算符，最后的儿子都是值，
//且节点的优先级和辈分大小成反比，即优先级高的节点先被计算，然后再上升到父节点
//如何判断某棵子树已经被遍历完：当前节点运算符优先级 >= 父节点优先级

#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

//两个栈分别存储数字和符号
stack<int> num;
stack<char> op;

//哈希表存储符号和优先级的对应关系二元组
unordered_map<char, int> pr = {{'+', 1},{'-', 1},{'*', 2},{'/', 2}};

string str;

//计算函数
void eval ()
{
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top(); op.pop();
    int x;
    if ( c == '+' ) x = a + b;
    else if ( c == '-' ) x = a - b;
    else if ( c == '*' ) x = a * b;
    else x = a / b;

    num.push(x);
}

int main ()
{
    cin >> str;
    for ( int i = 0; i < str.size(); i++ ) 
    {
        auto c = str[i];
        if ( isdigit(c) ) 
        //如果c为数字，则将其与其后所有数字计算成整数并压入num栈中
        {
            int ans = 0;
            int j;
            for ( j = i; j < str.size() && isdigit(str[j]); j++ )
                ans = ans*10 + str[j] - '0';

            i = j - 1;  //更新i下标
            num.push(ans);
        }
        else if ( c == '(' ) op.push(c);
        else if ( c == ')' )
        //如果是右括号，则需将左括号之前的所有符号配合num栈中元素计算并压入num栈中
        {
            while ( op.top() != '(' ) eval();
            op.pop();  //弹出左括号
        }
        else 
        //如果是普通运算符，根据优先级的大小关系决定是计算还是压入op栈中
        //对于中缀表达式，先计算的肯定是优先级大的，所以在每一个新运算符压入op栈前一定要判断栈中优先级大的运算符是否都计算完了
        {
            while ( op.size() && pr[op.top()] >= pr[c] ) eval();
            op.push(c);
        }
    }

    while ( op.size() ) eval();  //如果op栈中还有存留，则全部计算完
    
    cout << num.top() << endl;  //最后num栈中只有一个元素，即答案

    return 0;
}