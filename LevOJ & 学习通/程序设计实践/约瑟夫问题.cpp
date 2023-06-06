#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m;
int st[N];

int main ()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(st, 0, sizeof(st));

        int count = 0, i = -1, k = 0;
        bool flag = false;
        while (!flag)
        {
            i = (i + 1) % n;

            if (st[i]) continue;

            if (++count == m) 
            {
                st[i] = 1;
                k++;
                cout << i + 1 << ' ';
                count = 0;
            }

            if (k == n) flag = true;
        }
        puts("");
    }

    return 0;
}