#include <iostream>
#include <cmath>

using namespace std;

const int N = 600010;

int m, a, b;
int suma, sumb;

int get_prime (int n)
{
    int sum = 1;
    int len = sqrt(n);

    for (int i = 2; i < len; i++)
        if (n % i == 0)
            sum += i + n / i;

    if (n % len == 0) sum += len;

    return sum;
}

int main ()
{
    cin >> m;

    while (m--)
    {
        cin >> a >> b;

        suma = get_prime(a);
        sumb = get_prime(b);

        if (a == sumb && b == suma) puts("Yes");
        else puts("No");
    }

    return 0;
}