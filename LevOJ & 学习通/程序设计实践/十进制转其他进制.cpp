#include <iostream>

using namespace std;

const int N = 10010;

int n, jz;
int t[N], k;

int main ()
{
    cin >> n >> jz;

    while (n / jz)
    {
        t[++k] = n % jz;
        n /= jz;
    }
    t[++k] = n;

    for (int i = k; i; i--) cout << t[i];

    return 0;
}