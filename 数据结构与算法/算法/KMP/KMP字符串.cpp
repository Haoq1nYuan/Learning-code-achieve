//https://www.acwing.com/problem/content/833/

//STL --- 15/16 --- TLE
/* #include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int n, m;
string a, b;
int num[N], tem, count;

int main ()
{
    cin >> n >> a >> m >> b;

    while ( b.find(a) >= 0 && b.find(a) < b.size() )
    {
        num[++count] = tem + b.find(a);
        tem += b.find(a)+1;
        b = b.substr(b.find(a)+1);
    }
    
    for ( int i = 1; i <= count; i++ ) cout << num[i] << ' ';
    
    return 0;
}
 */
//KMP算法
/*
KMP算法就相当于一种让步的方法，当子串和母串匹配到不能再匹配时，暴力的做法是直接向后移动一位，
但是很多时候是不需要一位一维地移动的，只需要找到子串[1,j]上第一个满足[1,k] = [j-k+1,j]的点k即可,ne[j] = k
这个k就是下一个最左端和母串匹配的点，之后继续向右判断k+1是否和母串相应位置匹配。
*/
//下标为1
#include <iostream>
using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
char s[M], p[N];

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;

    //求p字符串的next数组，实际上就是子串自己和自己匹配的过程 
    //i代表p串从2开始的所有长度情况，j的位置就是每个长度情况对应的部分匹配值，也就是next数组的元素值
    for (int i = 2, j = 0; i <= n; i ++ ) 
    {
        //如果当前位置不匹配且j不为0，则在子子串中前移j到ne[j]处
        while (j && p[i] != p[j + 1]) j = ne[j];

        //如果当前位置匹配，则后移j
        if (p[i] == p[j + 1]) j ++ ;

        //对于子串中每个长度的子子串，都要存储一个部分匹配值
        ne[i] = j;
    }

    //KMP匹配过程
    for (int i = 1, j = 0; i <= m; i ++ )
    {
        //如果此时j+1与母串失配了，则将子串右移，j变为它左边的ne[j]，一直循环直到j+1能够成功匹配
        while (j && s[i] != p[j + 1]) j = ne[j];

        //如果j+1能够成功匹配,则增加子串匹配长度到j+1
        if (s[i] == p[j + 1]) j ++ ;

        //如果右移后发现字串匹配长度等于字串长度，则说明完全匹配，输出结果，将字串整体右移到下一个部分匹配的位置
        if (j == n)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }

    return 0;
}

//下标为0，不推荐
/* #include <iostream>
using namespace std;

const int M = 100010;

string a, b;
int n, m;
int ne[M];

int main ()
{   
    cin >> n >> a >> m >> b;

    ne[0] = -1;
    for ( int i = 1, j = -1; i < n; i++ )
    {
        while ( j >= 0 && a[i] != a[j+1] ) j = ne[j];
        if ( a[i] == a[j+1] ) j++;
        ne[i] = j;
    } 

    for ( int i = 0, j = -1; i < m; i++ )
    {
        while ( j != -1 && b[i] != a[j+1] ) j = ne[j];
        if ( b[i] == a[j+1] ) j++;
        if ( j + 1 == n )
        {
            cout << i - n + 1 << ' ';
            j = ne[j];
        }
    }

    return 0;
} */