#include <iostream>

using namespace std;

int n, k = 1;
double f;

int main ()
{
    cin >> n >> f;

    while (n >= 1)
    {
        k *= 2;
        n--;
    }
    
    if (f * k - (int)(f * k) >= 0.5) cout << (int)(f * k) + 1;
    else cout << (int)(f * k);

    return 0;
}