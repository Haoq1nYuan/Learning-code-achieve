//https://codeforces.com/problemset/problem/4/A

#include <iostream>

using namespace std;

int n;

int main ()
{
    cin >> n;

    if (n / 2 == 1 || n % 2) puts("NO");
    else puts("YES");

    return 0;
}