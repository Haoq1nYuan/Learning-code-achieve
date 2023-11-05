// acwing版，最舒服的版本
// #include <iostream>
// #define MAXLEN 100

// using namespace std;

// typedef struct 
// {   
//     string s;
//     int length;
// }sstring;

// int ne[MAXLEN];
// string s1, s2;

// void Index (sstring a, sstring b)
// {
//     for (int i = 2, j = 0; i <= a.length; i++)
//     {
//         while (j && a.s[j + 1] != a.s[i]) j = ne[j];

//         if (a.s[j + 1] == a.s[i]) j++;

//         ne[i] = j;
//     }

//     for (int i = 1, j = 0; i <= a.length; i++)
//     {
//         while (j && b.s[j + 1] != a.s[i]) j = ne[j];

//         if (b.s[j + 1] == a.s[i]) j++;

//         if (j == b.length)
//         {
//             cout << i - b.length + 1 << ' ';
//             j = ne[j]; 
//         }
//     }
// }

// int main ()
// {
//     cin >> s1 >> s2;

//     s1 = ' ' + s1;
//     s2 = ' ' + s2;

//     sstring a = {s1, 13};
//     sstring b = {s2, 3};

//     Index(a, b);

//     return 0;
// }

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

    // 求next数组
    int i = 1, j = 0;
    ne[1] = 0;
    while (i <= n)   // 此处要加上等号，否则全串的最大匹配值无法求得
        if (j == 0 || a[i] == a[j])
        {
            i ++;
            j ++;
            ne[i] = j;
        }
        else j = ne[j];

    // KMP
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