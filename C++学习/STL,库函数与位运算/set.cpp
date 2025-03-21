#include <iostream>
#include <set>
using namespace std;

int main ()
{
    multiset<int> a;

    cout << a.size() << endl;

    a.insert(5);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(3);

    cout << *a.begin() << endl;

    cout << *(++a.begin()) << endl;

    cout << *(--a.end()) << endl;

    cout << a.count(3) << endl;

    cout << *lower_bound(a.begin(), a.end(), 2) << " " << *a.upper_bound(3) << endl;

    cout << a.size() << endl;

    cout << *a.erase(a.begin()) << endl;

    cout << *(--a.end()) << endl;

    cout << a.size();

    return 0;
}