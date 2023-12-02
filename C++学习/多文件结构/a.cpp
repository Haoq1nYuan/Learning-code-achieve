#include <iostream>
#include "b.cpp"

using namespace std;
using namespace ss;

#ifndef kk
#define kk 

int i = 2;
void ss::fun();

void next ()
{
    fun();
}

int main ()
{
    next();

    cout << i << endl;

    return 0;
}

#endif