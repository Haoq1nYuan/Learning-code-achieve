// #include <iostream>

// using namespace std;

// class CRectangle 
// {
//     public:
//         bool set(float xx, float yy)
//         {
//             if (xx <= 0 || xx >= 50 || yy < 0 || yy > 50) return false;
//             x = xx;
//             y = yy;
//             return true;
//         }
//         float get()
//         {
//             return x * 2 + y * 2;
//         }
//         ~CRectangle(){};
    
//     private:
//         float x = 1, y = 1;
// };

// int main ()
// {
//     CRectangle c;
//     float x, y;

//     cout << "请输入你想设置的长和宽：" << endl;
//     cin >> x >> y;

//     while (!c.set(x, y))
//     {
//         cout << "输入范围不合法！请输入(0,50)内的数字" << endl;
//         cout << "请输入你想设置的长和宽：" << endl;
//         cin >> x >> y;
//     }

//     cout << "周长为：" << c.get() << endl;

//     return 0;
// }


// #include <iostream>

// using namespace std;

// class Complex
// {
//     public: 
//         Complex(float init_a, float init_b): a(init_a), b(init_b)
//         {
//             cout << "创建复数类成功！" << endl;
//         }
//         Complex(float init_a): Complex(init_a, 0) {}
//         void add(Complex com);
//         void show();

//     private:
//         float a = 0, b = 0;
// };

// void Complex::add(Complex com)
// {
//     a += com.a;
//     b += com.b;
// }

// void Complex::show()
// {
//     if (b > 0) cout << a << '+' << b << 'i' << endl;
//     else if (b == 0) cout << a << endl;
//     else cout << a << '-' << (-1) * b << 'i' << endl;
// }

// int main ()
// {
//     Complex c1(3, 5);
//     Complex c2(4.5);

//     c1.add(c2);
//     c1.show();

//     return 0;
// }

#include <iostream>

using namespace std;

class Rational
{
    public:
        Rational(int init_x = 1, int init_y = 1);
        void Add(Rational b);
        void Sub(Rational b);
        void Mul(Rational b);
        void Div(Rational b);
        void Show();
    
    private:
        int x, y;
};

// 求最大公约数
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

Rational::Rational(int init_x, int init_y): x(init_x), y(init_y)
{
    int tem = gcd(x > 0 ? x : (-1) * x, y);
    x /= tem, y /= tem;
    cout << "创建对象成功！" << endl;
}

// 加法运算
void Rational::Add(Rational r)
{
    int x2 = r.x, y2 = r.y;
    x *= y2, x2 *= y, y *= y2;
    x += x2;

    int tem = gcd(x > 0 ? x : (-1) * x, y);
    x /= tem, y /= tem;
}

// 减法运算
void Rational::Sub(Rational r)
{
    int x2 = r.x, y2 = r.y;
    x *= y2, x2 *= y, y *= y2;
    x -= x2;

    int tem = gcd(x > 0 ? x : (-1) * x, y);
    x /= tem, y /= tem;
}

// 乘法运算
void Rational::Mul(Rational r)
{
    int x2 = r.x, y2 = r.y;
    x *= x2, y *= y2;

    int tem = gcd(x > 0 ? x : (-1) * x, y);
    x /= tem, y /= tem;
}

// 除法运算
void Rational::Div(Rational r)
{
    int x2 = r.x, y2 = r.y;
    x *= y2, y *= x2;

    if (y < 0) x *= -1, y *= -1;

    int tem = gcd(x > 0 ? x : (-1) * x, y);
    x /= tem, y /= tem;
}

void Rational::Show()
{
    cout << "X/Y形式: " << x << '/' << y << endl;
    cout << "小数形式：" << (float)x / (float)y << endl;
}

int main ()
{   
    Rational r1(3, 12);
    Rational r2(-6, 7);

    cout << "r1:" << endl;
    r1.Show();
    cout << "r2:" << endl;
    r2.Show();

    r1.Add(r2);
    cout << "r1 + r2:" << endl;
    r1.Show();

    r1.Sub(r2);
    cout << "r1 - r2:" << endl;
    r1.Show(); 

    r1.Mul(r2);
    cout << "r1 * r2:" << endl;
    r1.Show();

    r1.Div(r2);
    cout << "r1 / r2:" << endl;
    r1.Show(); 

    return 0;
}