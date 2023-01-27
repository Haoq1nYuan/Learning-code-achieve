#include <iostream>
#include <string>
using namespace std;

struct Person
{
    int age;
    double money, height;
    string k;

    //类的构造函数上面建议加上public：
    //每种构造函数都对应着一种情况，结构体体变量定义赋值的时候必须符合这些情况中的至少一种
    Person () {}   //不要求传入参数

    Person ( string _k ) : k(_k) {}  //只要求有一个参数传入

    //如果要求传入所有参数
/*     Person ( int _age, int _height, double _money ) 
    {
        age = _age;
        height = _height;
        money = _money;
    }  */
    //简写，提高效率
    Person ( int _age, double _height, double _money ) : age(_age), height(_height), money(_money) {}
};

int main ()
{
    Person p = { "dhduqof" };  //此处可以赋3个值/1个值/不赋值，没赋的值自动为0

    cout << p.age << endl << p.height << endl << p.money << endl << p.k << endl;

    return 0;
}