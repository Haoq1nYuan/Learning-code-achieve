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

int n, m;
string a, b;

int main ()
{
    cin >> n >> a >> m >> b;

    cout << b.find(a) << endl;

    b = b.substr(b.find(a)+a.size());

    cout << b.find(a) << endl;

    b = b.substr(b.find(a)+a.size());

    cout << b.find(a) << endl;

    return 0;
}