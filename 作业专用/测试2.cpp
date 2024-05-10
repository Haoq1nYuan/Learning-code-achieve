#include <iostream>

using namespace std;

int main ()
{   
    int a = -1;
    unsigned int b = 2147483648;

    printf("a = %u = %X = %d\n", a, a, a);
    printf("b = %u = %X = %d", b, b, b);

    return 0;
}