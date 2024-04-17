#include <iostream>
#include <cmath>

using namespace std;

const int N = 100005;

int n, m, h[N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;

        int l = 1, r = n, mid = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;

            if (h[mid] < x) l = mid + 1;
            else if (h[mid] > x) r = mid - 1;
            else break;
        } 

        if (h[mid] == x) cout << h[mid] << endl;
        else if (h[mid] < x)
        {
            if (mid < n) cout << ((abs(x - h[mid]) <= abs(x - h[mid + 1])) ? h[mid] : h[mid + 1]) << endl;
            else cout << h[mid] << endl;
        }
        else 
        {
            if (mid > 1) cout << ((abs(x - h[mid - 1]) <= abs(x - h[mid])) ? h[mid - 1] : h[mid]) << endl;
            else cout << h[mid] << endl;
        }
    }

    return 0;
} 
