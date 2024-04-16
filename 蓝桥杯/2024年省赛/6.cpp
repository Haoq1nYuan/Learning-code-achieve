#include <iostream>
#include <cmath>

using namespace std;

const int N = 1000;

int n, a[N];
int s[N];

int ans = 0x3f3f3f3f;

int main ()
{       
    cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for (int len1 = 1; len1 < n; len1++)
        for (int l1 = 1; l1 + len1 - 1 < n; l1++)
        {
            int r1 = l1 + len1 - 1;

            for (int len2 = 1; len2 + r1 <= n; len2 ++)
                for (int l2 = r1 + 1; l2 + len2 - 1 <= n; l2++)
                {
                    int r2 = l2 + len2 - 1;

                    int aa = s[r1] - s[l1 - 1], bb = s[r2] - s[l2 - 1];
                    
                    ans = min(ans, abs(aa - bb));
                }
        }

    cout << ans << endl;

    return 0;
}