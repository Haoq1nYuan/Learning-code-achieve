#include <iostream>
#include <cmath>

using namespace std;

const int N = 46350;

typedef long long ll;

int k, x;
ll a[N];

void init ()
{
    for (int i = 1; i <= 46350; i++)
        a[i] = 2 * a[i - 1] + 1;
}

int main ()
{
    init();

    cin >> k;

    while (k--)
    {
        cin >> x;

        int l = 1, r = N;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (a[mid] <= x && a[mid + 1] >= x) l = mid;
            else r = mid - 1;
        }

        int st = a[l];

        int num = x - st;
        num %= 9;

        if (num == 0) num = 9;
        cout << num << endl;
    }

    return 0;
}