//https://www.acwing.com/problem/content/3305/

//中缀转后缀再计算
#include<stdio.h>
#include<string.h>
#define N 100010

//ex[N]为中缀表达式（大于9的数字未合并，例如1000在ex中存储为ex[1]=1,ex[2]=0,ex[3]=0,ex[4]=0）
//last[N]是只含符号的后缀表达式，num[N]是只含数字的后缀表达式
//last[N]和num[N]共用同一种下标
char ex[N], last[N];
int num[N];

//k用来遍历ex[N]，count为last[N]和num[N]的公共下标
int k, count;

//ans栈用来计算答案，stk栈用来存放中缀转后缀时的字符，idx作为下标
int ans[N];
char stk[N];
int idx;

//中缀转后缀，将数字存放在num数组中
void change ( int botton )  //botton表示该函数调用中相对而言的栈底下标，可能是0，也可能是'('所在的下标
{
    while ( k+1 <= strlen(ex+1) )
    {
        k++;
        if ( ex[k] >= '0' && ex[k] <= '9' ) //如果中缀表达式该位置表示数字,则将其后所有数字组成一个整体得到后缀表达式中的数字并存放在num数组中
        {
            num[++count] = ex[k++] - '0';
            while ( ex[k] >= '0' && ex[k] <= '9' ) 
                num[count] = num[count] * 10 + ( ex[k++] - '0' );
            k--;
        }
        else if ( ex[k] == '*' || ex[k] == '/' )  //如果中缀表达式该位置是*和/，则将栈顶同优先级的*或/弹出到后缀表达式中，直到栈顶是+或-
        {
            int j;
            for ( j = idx; j > botton; j-- )
            {
                if ( stk[j] == '*' || stk[j] == '/' ) last[++count] = stk[j];
                else break;
            }
            idx = j;
            stk[++idx] = ex[k];
        }
        else if ( ex[k] == '+' || ex[k] == '-' )  //如果中缀表达式该位置是+或-，则需要将栈中符号依次放入后缀表达式中，最后在栈中放入该位置的+或-
        {
            int j;
            for ( j = idx; j > botton; j-- )
                last[++count] = stk[j];
            idx = j;
            stk[++idx] = ex[k];
        }
        else if ( ex[k] == '(' )  //如果中缀表达式该位置为左括号，则递归调用转换函数，把改位置看作新的转换函数中的栈底下标
        {
            stk[++idx] = '(';
            change(idx);
        }
        else if ( ex[k] == ')' )  //如果碰到右括号，则将栈顶到botton的所有符号弹出到后缀表达式中，左括号除外，更新idx为botton-1
        {
            int j;
            for ( j = idx; j > botton; j-- ) last[++count] = stk[j];
            idx = j-1;
            return;
        }
    }

    return;
}

//计算后缀表达式
void calculate ()
{
    for ( int i = 1; i <= count; i++ )
    {
        if ( last[i] == 0 ) ans[++idx] = num[i]; //如果last[i]为0，说明后缀表达式在此处是数字，存放在num[i]中
        else if ( last[i] == '+' )
        {
            int sum = ans[idx-1] + ans[idx];
            ans[--idx] = sum;
        }
        else if ( last[i] == '-' )
        {
            int minor = ans[idx-1] - ans[idx];  //注意减法和除法的前后运算对象
            ans[--idx] = minor;
        }
        else if ( last[i] == '*' )
        {
            int plus = ans[idx-1] * ans[idx];
            ans[--idx] = plus;
        }
        else if ( last[i] == '/' )
        {
            int divide = ans[idx-1] / ans[idx];
            ans[--idx] = divide;
        }
    }   
}

int main ( int argc, char *argv[] )
{
    gets(ex+1);
    
    change(0);

    while (idx) last[++count] = stk[idx--];  //调用完函数后需要将栈中的残留符号依次放入后缀表达式中

    calculate();

    printf( "%d\n", ans[1] );

    return 0;
}

//中缀直接求值(C++)--以后再来
