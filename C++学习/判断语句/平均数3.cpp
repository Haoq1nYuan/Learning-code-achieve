#include <iostream>
#include <cstdio>

using namespace std;

double a, b, c, d, e;

int main ()
{
    cin >> a >> b >> c >> d;

    double ave = ( a*2 + b*3 + c*4 + d ) / 10;

    printf( "Media: %.1lf\n", ave );

    if ( ave >= 7 ) cout << "Aluno aprovado.";
    else if ( ave < 5 ) cout << "Aluno reprovado.";
    else 
    {
        cout << "Aluno em exame." << endl;

        cin >> e;

        printf( "Nota do exame: %.1lf\n", e );

        if ( (ave + e) / 2 >= 5 ) cout << "Aluno aprovado." << endl;
        else cout << "Aluno reprovado." << endl;

        printf( "Media final: %.1lf", (ave + e) / 2 );
    }

    return 0;
}