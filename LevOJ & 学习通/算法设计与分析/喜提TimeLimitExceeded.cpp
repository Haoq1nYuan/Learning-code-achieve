#include <iostream>

using namespace std;

const int N = 105;

int n, m, link[N];
string str[N];

int main ()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        link[i] = i;
        cin >> str[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        int tem = link[a];
        link[a] = link[b];
        link[b] = tem;
    }

    for (int i = 1; i <= n; i++)
        cout << str[link[i]] << endl;

    return 0;
}