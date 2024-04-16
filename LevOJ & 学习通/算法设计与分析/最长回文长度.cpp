#include <iostream>
#include <cstring>

using namespace std;

const int N = 1005;

string a, b;

int f[N][N];

int main ()
{   
    while (cin >> a)
    {
        int len = 0;
        for (auto ch : a) 
        {
            b = ch + b;
            len ++;
        }

        a = ' ' + a;
        b = ' ' + b;

        memset(f, 0, sizeof f);

        for (int i = 1; i <= len; i++)
            for (int j = 1; j <= len; j++)
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);

                if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }

        cout << f[len][len] << endl;
    }

    return 0;
}