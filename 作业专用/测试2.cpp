#include <iostream>

using namespace std;

int kk (int a, int b)
{
    return b ? kk(b, a % b) : a;
}

int main ()
{
    cout << 1 % -1 << endl;

    return 0;
}