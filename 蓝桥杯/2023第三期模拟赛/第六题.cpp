#include <iostream>

using namespace std;

int w, n;

int main ()
{
    cin >> w >> n;

    n %= 7;

    if ((w + n) % 7 == 0) cout << 7 << endl;
    else cout << (w + n) % 7;

    return 0;
}