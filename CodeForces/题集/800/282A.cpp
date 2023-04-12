//https://codeforces.com/problemset/problem/282/A

#include <iostream>

using namespace std;

int n, ans;
string a;

int main ()
{
    cin >> n;

    while (n--)
    {
        cin >> a;
        if (a[1] == '+') ans++;
        else if (a[1] == '-') ans--;
    }

    cout << ans << endl;

    return 0;
}