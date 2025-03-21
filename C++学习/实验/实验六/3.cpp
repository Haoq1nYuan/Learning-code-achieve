#include <iostream>

using namespace std;

class rational 
{
    public:
        rational(int x = 0, int y = 1);
        void print();
        friend rational operator+ (const rational &a, const rational &b);
        friend rational operator- (const rational &a, const rational &b);
    private:
        int num, den;
        void optimi();
};   

rational::rational(int x, int y)
{
    num = x;
    den = y;
}

void rational::print()
{
    cout << num << "/" << den << endl;
}

rational operator+ (const rational &a, const rational &b)
{
    return rational(a.num * b.den + b.num * a.den, a.den * b.den);
}

rational operator- (const rational &a, const rational &b)
{
    return rational(a.num * b.den - b.num * a.den, a.den * b.den);
}

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void rational::optimi()
{
    int tem = gcd(num, den);
    num /= tem;
    den /= tem;
}

int main ()
{
    rational r1(3, 4), r2(56, 7), r3;

    r3 = r1 + r2;
    r3.print();

    r3 = r1 - r2;
    r3.print();

    return 0;
}