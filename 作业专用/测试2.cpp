#include <iostream>

using namespace std;

class A
{
    public:
        static int a;
        void init () {a = 1;}
        A (int a = 2) {init(); a++;}
};

int A::a = 0;

int main ()
{
    A obj1, obj2(4);

    cout << obj1.a << A::a << endl;

    return 0;
}