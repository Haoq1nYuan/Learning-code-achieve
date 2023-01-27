#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main ()
{
    int a[5] = {1, 2, 4, 5, 7, };
    
    cout << upper_bound(a, a+5, 4) << endl;

    int i = upper_bound(a, a+5, 4) - a;
    cout << a[i] << endl;

    cout << *lower_bound(a, a+5, 7) << endl;

    vector<int> k({1, 2, 4, 5, 7, });

    cout << *upper_bound(k.begin(), k.end(), 4) << endl;

    int j = upper_bound(k.begin(), k.end(), 4) - k.begin();
    cout << k[j] << endl;
    vector<int>::iterator it = lower_bound(k.begin(), k.end(), 7);
    cout << *it << endl;

    return 0;
}