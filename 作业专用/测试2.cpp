#include <iostream>

using namespace std;

class Base
{   
    public:
        void set (int n) { x = n; }
        int x;
};

class Derived: public Base
{
    public:
        void set (int i, int j) 
        {
            x = i; 
            y = j; 
        }
        void set (int i, int j, int k)
        {
            Base::set(i);  // 重定义
            x = j;
            y = k;
        }
        void show ()
        {
            cout << "Base class: x = " << Base::x << endl;
            cout << "Derived class: m = " << x << endl;
            cout << "Derived class: n = " << y << endl;
        }
    private:
        int x, y;
};

int main ()
{
    Derived obj;
    obj.set(1, 2, 3);   
    obj.show();

    obj.Base::set(10); // obj.set(10) 不合法
    obj.set(20, 30);
    obj.show();

    return 0;
}