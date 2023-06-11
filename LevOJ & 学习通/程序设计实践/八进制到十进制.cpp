#include <iostream>
#include <cmath>

using namespace std;

int n, jz;

int main ()
{
    while (cin >> n >> jz, n)
    {
        int ans = 0, p = 0;
        while (n)
        {
	        ans += n % 10 * pow(jz, p);
            n /= 10;
            p++;
        }

        cout << ans << endl;
    }

    return 0;
}