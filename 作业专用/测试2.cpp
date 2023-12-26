#include <iostream>

using namespace std;

int divide (int x, int y) throw (int)
{
    if (y == 0) throw x;
    return x / y;
}

int main ()
{
    try 
    {
        cout << divide(5, 2) << endl;
        cout << divide(8, 0) << endl;
        cout << divide(7, 1) << endl;
    }
    catch (int e)
    {
        cout << e << " is divided by 0." << endl;
    }

    return 0;
}