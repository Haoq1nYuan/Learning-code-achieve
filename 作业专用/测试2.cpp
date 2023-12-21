#include <map>
#include <iostream>

using namespace std;

map<int, int> type;

int main ()
{
    type[101] = 1;
    type[99] = 2;
    type[7] = 3;

    for (auto i = type.begin(); i != type.end(); i++) cout << i->first << ' ';

    return 0;
}