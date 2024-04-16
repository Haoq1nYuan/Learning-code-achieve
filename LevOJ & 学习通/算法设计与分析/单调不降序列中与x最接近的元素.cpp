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

        bool flag = false;

        int l = 1, r = n, mid = 0;
        while (l + 1 < r)
        {
            mid = (l + r) / 2;

            if (h[mid] < x) l = mid + 1;
            else if (h[mid] > x) r = mid - 1;
            else 
            {
                flag = true;
                break;
            }
        } 

        if (flag) cout << x;
        else cout << (abs(h[mid] - h[l]) <= abs(h[mid] - h[r]) ? h[l] : h[r]) << endl;
    }

    return 0;
} 
