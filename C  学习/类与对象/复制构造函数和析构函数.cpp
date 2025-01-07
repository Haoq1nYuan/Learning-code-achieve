#include <iostream>

using namespace std;

class Point
{
    public:
        Point(int xx = 0, int yy = 0)
        {
            x = xx;
            y = yy;
            cout << "k" << endl;
        }
        Point(Point &p);
    
        int getX()
        {
            return x;
        }
        int getY()
        {
            return y;
        }

        ~Point()
        {
            cout << "执行析构函数" << endl;
        }
    private:
        int x, y;
};

Point::Point(Point &p)
{
    x = p.x;
    //y = p.y;
    cout << "复制构造函数调用成功" << endl;
}

int main ()
{
    Point a(1, 2);
    Point b(a);

    cout << b.getY() << endl;

    return 0;
}