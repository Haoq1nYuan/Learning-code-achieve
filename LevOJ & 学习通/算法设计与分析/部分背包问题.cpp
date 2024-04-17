// 注意本题与分组背包的区别，分组背包要求物品都是一个一个的，而本题的金币可以无限分割。

// #include <iostream>

// using namespace std;

// const int N = 105, M = 1005;

// int n, t, m[N], v, p[N];
// int f[N][M];

// int main ()
// {
//     cin >> n >> t;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> m[i] >> v;
//         p[i] = v / m[i];
//     }

//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= t; j++)
//         {
//             f[i][j] = f[i - 1][j];

//             for (int k = 1; k <= j && k <= m[i]; k++)
//                 f[i][j] = max(f[i][j], f[i - 1][j - k] + k * p[i]);
//         }

//     cout << f[n][t] << endl;

//     return 0;
// }

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105, M = 1005;

int n, t;
double ans;

struct coins
{
    int m, v;
    double p;

    bool operator< (const coins k)const
    {
        return p > k.p;
    }
} C[N];

int main ()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        int m, v;
        cin >> m >> v;

        C[i] = {m, v, (double)v / m};
    }

    sort(C + 1, C + 1 + n);

    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sum + C[i].m <= t) 
        {
            ans += C[i].v;
            sum += C[i].m;
        }
        else 
        {
            ans += (t - sum) * C[i].p;
            break;
        }
    }

    printf("%d\n", (int)ans);

    return 0;
}