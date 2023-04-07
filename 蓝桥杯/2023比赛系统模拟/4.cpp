#include <iostream>

using namespace std;

long long ans;

int main ()
{
    long long n =  2021041820210418;

    for (long long i = 1; i * i * i <= n; i++)
        if (n % i == 0)
            for (long long j = i; i * j * j <= n; j++)
                if (n / i % j == 0)
                {
                    long long k = n / i / j;

                    if (i == j || j == k || k == i) ans += 3;
                    else if (i == j && j == k) ans++;
                    else ans += 6;
                }

    cout << ans << endl;

    return 0;
}