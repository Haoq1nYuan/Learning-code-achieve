//https://www.acwing.com/problem/content/1462/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <bitset>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
using namespace std;

const int N = 100010;
typedef long long ll;
typedef unsigned long long ull;

int n, k;
char color[110];
string a;

bool check ( int len ) 
{

}

int main ()
{
    cin >> n >> a;

    for ( auto &c : a ) color[++k] = c;

    int l = 1, r = k;
    while ( l > r )
    {
        int mid = (l + r) / 2;

        if ( check(mid) ) r = mid;
        else l = mid - 1;
    }

    cout << l;

    return 0;
}