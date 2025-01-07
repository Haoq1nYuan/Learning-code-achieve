#include <iostream>

using namespace std;

class Complex
{
    public:
        Complex (double r, double i = 0.0) {real = r; imag = i;}
        friend Complex operator+ (Complex &c1, Complex &c2);
        friend Complex operator- (Complex &c1, Complex &c2);
        void display () const;
    private:
        double real;
        double imag;
};

Complex operator+ (Complex &c1, Complex &c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator- (Complex &c1, Complex &c2)
{
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

void Complex::display () const
{
    cout << "(" << real << "," << imag << ")" << endl;
}

int main ()
{
    Complex c1(5, 4), c2(2, 10), c3(1);
    cout << "c1=";
    c1.display();
    cout << "c2=";
    c2.display();

    c3 = c1 + c2;
    cout << "c3=c1+c2=";
    c3.display();

    c3 = c1 - c2;
    cout << "c3=c1-c2=";
    c3.display();

    // c3 = c1 + 5;
    // cout << "c3=c1+5=";   此时这里就不行了，因为是非成员函数，所以要求必须传入两个Complex对象
    // c3.display();

    return 0;
}