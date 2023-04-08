#include <iostream>

using namespace std;

const int N = 100010;

int n, a[N], s[N], e[N];
int ans, ans2;
int eee;

int main ()
{ 
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        e[i] = a[i] % 10;

        int tem = a[i];
        while (tem) 
        {
            if (tem / 10 == 0) s[i] = tem;
            tem /= 10;
        }
    }

    eee = e[1];
    for (int i = 2; i <= n; i++)
        if (eee != s[i]) ans++;
        else eee = e[i];

    eee = s[n];
    for (int i = n - 1; i; i--)
        if (eee != e[i]) ans2++;
        else eee = s[i];

    cout << min(ans, ans2) << endl;

    return 0;
}