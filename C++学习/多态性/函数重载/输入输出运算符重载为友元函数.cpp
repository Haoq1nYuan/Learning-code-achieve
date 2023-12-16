#include <iostream>

using namespace std;

class complex 
{
    public:	
        complex (double r = 0.0, double i = 0.0) { real=r; imag=i; }	
        friend ostream& operator <<(ostream &out, const complex&);
        friend istream& operator >>(istream &in, complex&);
    private:	
        double real;
        double imag;
};		

ostream & operator << (ostream &out, const complex &c)
{	
    out << "(" << c.real << "," << c.imag << ")";
	return out;
}

istream & operator >> (istream &in, complex &c)
{	
    in >> c.real >> c.imag;
	return in;
}

int main ()
{
    complex c1, c2;

    cout << "input c1:";
    cin >> c1;
    cout << "input c2:";
    cin >> c2;

    cout << "c1:" << c1 << ", c2:" << c2 << endl;

    return 0;
}