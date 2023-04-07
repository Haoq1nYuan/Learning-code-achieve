#include <iostream>

using namespace std;

long long a;

int main ()
{
    cin >> a;
    a /= 1000;

    int hour = (a / 3600) % 24;
    int min = (a % 3600) / 60;
    int sec = a % 60;

    if (hour < 10) cout << 0 << hour << ':';
    else cout << hour << ':';

    if (min < 10) cout << 0 << min << ':';
    else cout << min << ':';

    if (sec < 10) cout << 0 << sec;
    else cout << sec;

    return 0;
}