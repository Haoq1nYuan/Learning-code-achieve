//https://www.acwing.com/problem/content/837/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <bitset>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
using namespace std;

const int N = 100010;
typedef long long ll;
typedef unsigned long long ull;

int n;
char h[2], str[N];

//son[i][26]表示节点i的儿子情况，son[i][3] = k 表示节点i有儿子'd'，该儿子的节点编号为k，
//所以当我们要去看该儿子节点的儿子时，就可以用 son[k][] 去判断
//所以说，son数组的一维部分存储的是一条由节点下标构成的链表，每个节点儿子的不同选择都会对应一个不同的next指针，指向不同的孙子节点
//cnt存储有多少个以该节点为末尾的字符串，相当于标记，idx为下标，表示共存储了多少字符，也相当于树中的节点下标
//根节点和没有子节点的节点下标都为0
int son[N][26], cnt[N], idx;

void insert ( char *str )
{
    int p = 0;
    for ( int i = 0; str[i]; i++ )
    {
        //将当前字符的数字编号算出来
        int u = str[i] - 'a';
        //判断树中是否存在编号为u的儿子，如果没有，则自己创建一个
        if ( !son[p][u] ) son[p][u] = ++idx;
        //将p指针下移到儿子节点上
        p = son[p][u];
    }

    //最后p的位置就是该字符串的末尾字符的位置，我们将该位置的标记加1
    cnt[p]++;
}

int query ( char *str )
{
    int p = 0;
    for ( int i = 0; str[i]; i++ )
    {
        int u = str[i] - 'a';
        if ( !son[p][u] ) return 0;
        p = son[p][u];
    }

    return cnt[p];
}

int main ()
{   
    cin >> n;
    
    while ( n-- )
    {
        cin >> h >> str;
        if ( h[0] == 'I' ) insert(str);
        else cout << query(str) << endl;
    }

    return 0;
}