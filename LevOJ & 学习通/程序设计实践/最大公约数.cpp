#include <iostream>

using namespace std;

int n, a, b;

int gcd (int a, int b)
{
    return a % b ? gcd(b, a % b) : b;
}

int main ()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++) 
        {
            cin >> a >> b;

            cout << gcd(a, b) << endl;
        }    
    }

    return 0;
}