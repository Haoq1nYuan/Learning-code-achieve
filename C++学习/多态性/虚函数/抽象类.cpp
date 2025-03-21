#include <iostream>
#include <cmath>

const double PI = 3.1415926535;

using namespace std;

class Shape
{
    public:
        virtual void show()=0;
        virtual double area()=0;
};

class Rectangle: public Shape
{
    public:
        Rectangle() {length = 0; width = 0;}
        Rectangle(double len, double wid)
        {
            length = len;
            width = wid;
        }
        void show() {cout << "length:" << length << '\t' << "width=" << width << endl;}
        double area() {return length * width;}
    private:
        double length, width;
};

class Triangle: public Shape
{
    public:
        Triangle( )
        {
            a = 0;
            b = 0;
            c = 0;
        }
        Triangle(double x, double y,double z)
        {
            a = x;
            b = y;
            c = z;
        }
        void show( )
        {
            cout << "a=" << a << '\t' << "b=" << b << '\t' << "c=" << c << endl;
        }
        double area( )
        {
            double s = (a + b + c) / 2.0;
            return sqrt(s * (s - a) * (s - b) * (s - c));
        }
    private:
        double a,b,c;
};

class Circle: public Shape
{
    public:
        Circle() {radius = 0;}
        Circle(double r) {radius = r;}
        void show() {cout << "radius=" << radius << endl;}
        double area() {return PI * radius * radius;}
    private:
        double radius;
};

int main ()
{
    Shape *s;
    Circle c(10);
    Rectangle r(6,8);
    Triangle t(3,4,5);

    s = &c;
    s->show();
    cout << "圆面积" << c.area() << endl;
    s = &r;
    s->show();
    cout << "矩形面积" << s->area() << endl;
    s = &t;
    s->show();
    cout << "三角形面积" << s->area() << endl;

    return 0;
}