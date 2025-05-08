//https://www.acwing.com/problem/content/874/

#include <iostream>

using namespace std;

int gcd (int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main ()
{
    int n;
    cin >> n;
    
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }

    return 0;
}

//更相减损法
int gcd (int a, int b)
{
    while (a != b)
        if (a > b) a -= b;
        else b -= a;
    return a;
}