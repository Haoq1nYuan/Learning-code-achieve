#include <iostream>
using namespace std;

int a, b;

int lcm ( int x, int y )
{
    for ( int i = 1; i <= x*y; i++ )
        if ( i % a == 0 && i % b == 0 ) return i;
    
    return x*y;
}

int main ()
{
    cin >> a >> b;
     
    cout << lcm(a, b) << endl;
    
    return 0;
}