#include <iostream>
#include "Timer.cpp"

using namespace std;

int main ()
{
    Timer timer(3, 44);

    cout << timer.Hours() << endl;
    cout << timer.Minutes() << endl;

    timer.Increase();

    return 0;
}