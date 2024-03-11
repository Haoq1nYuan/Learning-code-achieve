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

string a, b;

int main ()
{
    cin >> a >> b;
    a = ' ' + a, b = ' ' + b;

    for (int i = 1; i < a.size() && i < b.size(); i++)
    {
        cout << a << ' ' << a.substr(1, i) << endl;
        cout << b << ' ' << b.substr(b.size() - i, i) << endl;
        if (a.substr(1, i) != b.substr(b.size() - i, i))
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}