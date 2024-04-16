#include <iostream>

using namespace std;

const int N = 10005;

typedef long long ll;

int n;
ll ans, h[N];

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> h[i];

        h[i] += h[i - 1];
    }

    for (int len = 1; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;

            ans = max(ans, h[j] - h[i - 1]);
        }

    cout << ans << endl;

    return 0;
}