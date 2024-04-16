#include <iostream>

using namespace std;

const int N = 45;

typedef long long ll;

int x;
ll num[N];

int main ()
{   
    num[1] = num[2] = num[3] = 1;

    for (int i = 4; i <= 40; i++)
    {
        num[i] = num[i - 1] + num[i - 2] + num[i - 3];
    }

    cin >> x;

    cout << num[x] << endl;

    return 0;
}