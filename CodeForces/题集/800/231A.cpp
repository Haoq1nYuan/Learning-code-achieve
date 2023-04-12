//https://codeforces.com/problemset/problem/231/A

#include <iostream>

using namespace std;

int n, a, b, c, cnt;

int main ()
{
    cin >> n;

    while (n--)
    {
        cin >> a >> b >> c;
        if (a + b + c > 1) cnt++;
    }

    cout << cnt << endl;

    return 0;
}