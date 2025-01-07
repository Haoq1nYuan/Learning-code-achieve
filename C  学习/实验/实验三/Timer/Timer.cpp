#include <iostream>
#include "Timer.h"

using namespace std;

void Timer::Increase ()
{
    minutes++;
    if (minutes > 59)
    {
        minutes -= 60;
        hours++;
    }

    if (hours > 23) hours = 0;

    cout << "\nIt is now " << hours << ":" << minutes;
}

Timer::Timer (int hour, int minute): minutes(minute), hours(hour) {}