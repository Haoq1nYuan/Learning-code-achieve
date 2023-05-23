#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 505;

int n, m;
int st[N];

struct Q
{
    int time, fine;

    bool operator< (const Q& k)const 
    {
        return fine > k.fine;
    }
} q[N];

int main ()
{
    while (scanf("%d", &m) != EOF)
    {
        memset(st, 0, sizeof(st));
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> q[i].time;
        for (int i = 1; i <= n; i++) cin >> q[i].fine;

        sort(q + 1, q + 1 + n);

        for (int i = 1; i <= n; i++)
            for (int j = q[i].time; j >= 1; j--)
            {
                if (!st[j])
                {
                    st[j] = 1;
                    break;
                }

                if (j == 1) m = m - q[i].fine;
            }

        cout << m << endl;
    }

    return 0;
}