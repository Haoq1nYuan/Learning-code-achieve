#include <iostream>
#include "b.cpp"

using namespace std;

#ifndef kk
#define kk 

int i = 2;
void fun();

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