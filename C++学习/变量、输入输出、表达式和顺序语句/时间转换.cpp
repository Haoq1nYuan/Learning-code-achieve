#include <iostream>
#include <cstdio>

using namespace std;

int n, hour, minu, sec;

int main ()
{
    cin >> n;

    hour = n/3600;
    n -= hour*3600;
    minu = n/60;
    n -= minu*60;
    sec = n;
    
    printf( "%d:%d:%d\n", hour, minu, sec );

    return 0;
}