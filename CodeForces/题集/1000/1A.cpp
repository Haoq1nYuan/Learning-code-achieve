//https://codeforces.com/problemset/problem/1/A

#include <iostream>

using namespace std;

typedef long long ll;

int n, m, a;
ll sum;

int main ()
{
    cin >> n >> m >> a;

    int r = n / a;
    int c = m / a; 

    sum = (ll)r * c;
    if (n % a) sum += m / a + (m % a ? 1 : 0);
    if (m % a) sum += n / a + (n % a ? 1 : 0);
    if (n % a && m % a) sum--;

    cout << sum << endl;

    return 0;
}