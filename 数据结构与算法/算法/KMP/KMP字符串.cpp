//https://www.acwing.com/problem/content/833/

//STL --- TLE
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int n, m;
string a, b;
int num[N], tem, count;

int main ()
{
    cin >> n >> a >> m >> b;

    while ( b.find(a) >= 0 && b.find(a) < b.size() )
    {
        num[++count] = tem + b.find(a);
        tem += b.find(a)+1;
        b = b.substr(b.find(a)+1);
    }
    
    for ( int i = 1; i <= count; i++ ) cout << num[i] << ' ';
    
    return 0;
}

//KMPËã·¨
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

const int N = 10010;
typedef long long ll;

int main ()
{
    

    return 0;
}