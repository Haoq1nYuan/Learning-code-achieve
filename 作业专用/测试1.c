#include <stdio.h>

int main ()
{
    float a = 8.356888;

    printf( "%lf", (float)((int)(a*1000+5)/10)/100 );

    return 0;
}