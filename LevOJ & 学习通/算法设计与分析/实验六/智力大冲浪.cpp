#include <iostream>
#include <algorithm>

using namespace std;

const int N = 505;

int n, m;
bool st[N];

struct activity
{
    int t, c;

    operator< (const activity a)const
    {
        return c > a.c;
    }
} a[N];

int main ()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].t;
    for (int i = 1; i <= n; i++) cin >> a[i].c;

    sort(a + 1, a + 1 + n);

    int cur_time = 0;
    for (int i = 1; i <= n; i++)
    {
        int flag = false; 
        for (int j = a[i].t; j >= 1; j--)  // ©©╨Сее
            if (!st[j]) 
            {
                st[j] = true;
                flag = true;
                break;
            }
        
        if (!flag) m -= a[i].c;
    }

    cout << m << endl;

    return 0;
}