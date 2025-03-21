#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main ()
{
    vector<int> a = { 1, 2, 5, 3, 2, };
    vector<int> b(a);

    vector<int>::iterator it = b.begin();

    reverse(it, it + 5);

    for ( int i = 0; i < 5; i++ ) cout << b[i] << ' ';

    return 0;
}