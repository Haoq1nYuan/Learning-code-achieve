// 投机取巧做法
// #include <iostream>

// using namespace std;

// const int N = 35;

// int n, f[N];

// int main ()
// {   
//     f[1] = 1, f[2] = 2, f[3] = 4, f[4] = 7;
//     for (int i = 5; i <= 30; i++) f[i] = f[i - 1] + f[i - 2] + f[i - 4];

//     while (scanf("%d", &n) != EOF)
//     {
//         cout << f[n] << endl;
//     }

//     return 0;
// }

// 大整数加法
#include <iostream>
#include <vector>

using namespace std;

const int N = 1005;

int n;
vector<int> x[N];

vector<int> add (vector<int> a, vector<int> b)
{
    vector<int> c;

    int tem = 0, i, j;
    for (i = 0, j = 0; i < a.size() && j < b.size(); i++, j++)
    {
        tem += a[i] + b[j];
        c.push_back(tem % 10);
        tem /= 10;
    }

    while (j < b.size())
    {
        tem += b[j++];
        c.push_back(tem % 10);
        tem /= 10;
    }

    if (tem) c.push_back(tem);

    return c;
}

int main ()
{
    x[1].push_back(1);
    x[2].push_back(2);
    x[3].push_back(4);
    x[4].push_back(7);

    for (int i = 5; i <= 1000; i++) x[i] = add(x[i - 4], add(x[i - 2], x[i - 1]));

    while (scanf("%d", &n) != EOF)
    {
        for (int i = x[n].size() - 1; i >= 0; i--) cout << x[n][i];
        cout << endl;
    }

    return 0;
}