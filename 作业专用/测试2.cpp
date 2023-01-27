#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <set>
using namespace std;

const int N = 10010;
typedef long long ll;

int main () {

    int a[] = {1,2,3,4,4};

    do {
        for ( int i = 0; i < 5; i++ ) cout << a[i] << ' ';
        cout << endl;
    } while ( next_permutation(a, a+5) );
    
    return 0;
}