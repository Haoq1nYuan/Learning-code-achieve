#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    vector<int> a;
    a.reserve(2);

    a[0] = 1;
    a[1] = 2; 

    int * a_p = a.data();

    cout << a_p[0] << ' ' << a_p[1] << endl;

    return 0;
}