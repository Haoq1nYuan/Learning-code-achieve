//https://codeforces.com/problemset/problem/158/A

#include <iostream>

using namespace std;

const int N = 55;

int n, k, a[N];

int main ()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];

    if (a[k] == 0) 
    {
        int i;
        for (i = k; i; i--) if (a[i]) break;
        cout << i << endl;
    }
    else
    {
        for (int i = k; i <= n; i++) 
            if (a[i] != a[i + 1]) 
            {
                cout << i << endl;
                break;
            }
    }

    return 0;
}