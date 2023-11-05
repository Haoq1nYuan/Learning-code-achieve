// #include <iostream>
// using namespace std;

// const int N = 100010, M = 1000010;

// int n, m;
// int ne[N];
// char s[M], p[N];

// int main()
// {
//     cin >> n >> p + 1 >> m >> s + 1;

//     //求p字符串的next数组，实际上就是子串自己和自己匹配的过程 
//     //i代表p串从2开始的所有长度情况，j的位置就是每个长度情况对应的部分匹配值，也就是next
//     //数组的元素值
//     for (int i = 2, j = 0; i <= n; i ++ ) 
//     {
//         //如果当前位置不匹配且j不为0，则在子子串中前移j到ne[j]处
//         while (j && p[i] != p[j + 1]) j = ne[j];

//         //如果当前位置匹配，则后移j
//         if (p[i] == p[j + 1]) j ++ ;

//         if (p[j + 1] != p[i + 1]) ne[i] = j;
//         else ne[i] = ne[j];
//     }

//     //KMP匹配过程
//     for (int i = 1, j = 0; i <= m; i ++ )
//     {
//         //如果此时j+1与母串失配了，则将子串右移，j变为它左边的ne[j]，
//         //一直循环到j+1能够成功匹配
//         while (j && s[i] != p[j + 1]) j = ne[j];

//         //如果j+1能够成功匹配,则增加子串匹配长度到j+1
//         if (s[i] == p[j + 1]) j ++ ;

//         //如果右移后发现字串匹配长度等于字串长度，则说明完全匹配，
//         //输出结果，将字串整体右移到下一个部分匹配的位置
//         if (j == n)
//         {
//             printf("%d ", i - n);
//             j = ne[j];
//         }
//     }

//     return 0;
// }

// 课内方法
#include <iostream>

using namespace std;

string a, b;
int n, m;
int ne[100000];

int main ()
{
    cin >> n >> a >> m >> b;

    a = ' ' + a;
    b = ' ' + b;

    int i = 1, j = 0;
    ne[1] = 0;
    while (i <= n)
        if (j == 0 || a[i] == a[j])
        {
            i ++;
            j ++;

            if (a[i] != a[j]) ne[i] = j;  // 如果前移之后失配了，则直接更新ne[i]
            else ne[i] = ne[j];           // 如果前移之后仍匹配，那么事实上这一段前移就是多余的，我们希望在迁移过后就是失配，所以我们不断更新ne[i]
        }
        else j = ne[j];

    i = 1, j = 1;
    while (i <= n && j <= m)
        if (i == 0 || a[i] == b[j])
        {
            i ++;
            j ++;

            if (i > n)
            {
                cout << j - n - 1 << ' ';
                i = ne[i];
            }
        }
        else i = ne[i];

    return 0;
}