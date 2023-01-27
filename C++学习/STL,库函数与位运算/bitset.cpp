#include <iostream>
#include <bitset>
using namespace std;

int main ()
{
    bitset<100> a;
    
    a.set(5);

    cout << a[4];


    return 0;
}