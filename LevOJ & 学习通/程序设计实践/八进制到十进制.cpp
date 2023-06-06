#include <iostream>
#include <cmath>

using namespace std;

int n;

int main ()
{
    while (cin >> n, n)
    {
        int ans = 0, p = 0;
        while (n)
        {
            int k = n % 10;
            n /= 10;
            p++;
            ans += k * pow(8, p - 1);
        }

        cout << ans << endl;
    }

    return 0;
}