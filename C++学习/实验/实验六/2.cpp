#include <iostream>
#include <cmath>

using namespace std;

class Point
{
    public:
        Point(int xx = 0, int yy = 0)
        {
            x = xx;
            y = yy;
        }
        Point operator- (const Point &p) const;
        friend ostream& operator<< (ostream &out, const Point &p);
    private:
        int x, y;
};

Point Point::operator- (const Point &p) const
{
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

ostream& operator<< (ostream &out, const Point &p)
{
    out << "(" << p.x << "," << p.y << ")" << endl;
    return out;
}

int main ()
{
    Point p1, p2(3, 4);

    cout << "p1: " << p1 << "p2: " << p2;
    cout << p1 - p2 << endl;

    return 0;
}