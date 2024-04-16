#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 25;

int n;
ll x[N];

int main ()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> x[i];

        sort(x + 1, x + 1 + n);

        for (int k = 1; k < n; k++)
        {
            x[k + 1] = x[k] * x[k + 1] + 1;

            sort(x + k + 1, x + 1 + n);
        }

        cout << x[n] << endl;
    }

    return 0;
} 