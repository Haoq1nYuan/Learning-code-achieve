#include <iostream>

using namespace std;

class CD 
{
    public:
        CD () {cout << "b";}
        ~CD () {cout << "c";}
};

int main ()
{   
    CD a, *b, d[2];

    return 0;
}