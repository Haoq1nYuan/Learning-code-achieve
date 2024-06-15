#include <iostream>

using namespace std;

const int N = 10005;

int n, m;
string str[N];

int main ()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int len;
        cin >> len >> str[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;

        cout << str[x] << endl;
    } 

    return 0;
}