//强制转换得整数部分
#include <iostream>
#include <cstdio>

using namespace std;

double n;
int a[7] = { 100, 50, 20, 10, 5, 2, };
double b[6] = { 1.00, 0.50, 0.25, 0.10, 0.05, 0.01, };
int count;

int main ()
{
    cin >> n;
    
    int num = (int)n;
    cout << "NOTAS:" << endl;
    for ( int i = 0; i < 6; i++ ) 
    {
        printf( "%d nota(s) de R$ %d.00\n", num/a[i], a[i] );
        num -= num/a[i] * a[i];
    }
    
    double min = num + n - (int)n + 0.001; //精度问题，0.01被存储为0.009999999
    cout << "MOEDAS:" << endl;
    for ( int i = 0; i < 6; i++ )
    {
        count = 0;
        while ( min >= b[i] )
        {
            min -= b[i];
            count++;
        }
        printf( "%d moeda(s) de R$ %.2lf\n", count, b[i] );
    }
    
    return 0;
}

//放大法
#include <iostream>
#include <cstdio>

using namespace std;

double m;
int n;
int a[7] = { 10000, 5000, 2000, 1000, 500, 200, };
int b[6] = { 100, 50, 25, 10, 5, 1, };

int main ()
{
    cin >> m;

    n = m * 100;

    cout << "NOTAS:" << endl;
    for ( int i = 0; i < 6; i++ ) 
    {
        printf( "%d nota(s) de R$ %d.00\n", n/a[i], a[i]/100 );
        n %= a[i];
    }

    cout << "MOEDAS:" << endl;
    for ( int i = 0; i < 6; i++ ) 
    {
        printf( "%d moeda(s) de R$ %.2lf\n", n/b[i], 1.0*b[i]/100 );
        n %= b[i];
    }

    return 0;
}