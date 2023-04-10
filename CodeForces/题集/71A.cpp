//https://codeforces.com/problemset/problem/71/A

#include <iostream>
#include <algorithm>

using namespace std;

int n;
string a;
char be, en;

int main ()
{
    cin >> n;

    while (n--)
    {
        cin >> a;
    
        int cnt = 0;
        for (auto k : a) cnt++;

        if (cnt > 10) 
        {
            be = a[0];
            reverse(a.begin(), a.end());
            en = a[0];

            cout << be << cnt - 2 << en << endl;
        }
        else cout << a << endl;
    }

    return 0;
}