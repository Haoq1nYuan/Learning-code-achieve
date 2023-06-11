#include <iostream>

using namespace std;

int n;

int main ()
{
    cin >> n;

    int x = n;
    for (int i = 1; i <= 4; i++) n = n * 10 + x % 10, x /= 10;

    cout << n << endl;

    return 0;
}