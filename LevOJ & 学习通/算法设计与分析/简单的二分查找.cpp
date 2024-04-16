#include <iostream>

using namespace std;

typedef long long ll;

ll x, y, s;

int main ()
{
    cin >> x >> y >> s;

    ll l = x, r = y;
    while (l <= r)
    {
        ll mid = 0;
        if ((l + r) % 2) mid = (l + r - 1) / 2;
        else mid = (l + r) / 2;

        if (s < mid) 
        {
            r = mid - 1;
            cout << 'L';
        }
        else if (s > mid)
        {
            l = mid + 1;
            cout << 'R';
        }
        else if (s == mid)
        {
            cout << 'G' << endl;
            break;
        }
    }

    return 0;
}