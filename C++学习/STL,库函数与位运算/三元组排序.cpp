//https://www.acwing.com/problem/content/864/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

const int N = 10010;

struct kk
{
    int n;
    double m;
    string k;
    bool operator< (const kk & oo)const
    {
        return n < oo.n;
    }
}t[N];

int x, a;
double y;
string z;

int main ()
{
    cin >> a;
    for ( int i = 0; i < a; i++ )
        cin >> t[i].n >> t[i].m >> t[i].k;
    
    sort(t, t+a);

    for ( int i = 0; i < a; i++ )
        printf( "%d %.2lf %s\n", t[i].n, t[i].m, t[i].k.c_str() );

    return 0;
}