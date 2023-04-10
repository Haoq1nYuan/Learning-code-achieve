//https://codeforces.com/problemset/problem/1/A

#include <iostream>

using namespace std;

typedef long long ll;

int n, m, a;
ll sum;

int main ()
{
    cin >> n >> m >> a;

    sum = (ll)(n / a) * (m / a);

    if (n % a != 0) sum += n / a + 1;
    if (m % a != 0) sum += m / a + 1;
    if (m % a != 0 && n % a != 0) sum--;

    cout << sum << endl;

    return 0;
}