#include <iostream>
using namespace std;

const int N = 10010;

class Person
{
    private:  //类私有的变量，只能在类中调用
        int age, height;
        double money;
        string books[N];
    
    public:   //共用的变量，其他地方也可以调用
        string name;
        
        void say ()  //可以在类中包含函数
        {
            cout << "I'm " << name << endl;
        }
        
        void set_age( int a )
        {
            age = a;
        }
        
        int get_age ()
        {
            return age;
        }
        
        void add_money ( double x )
        {
            money += x;
        }
} person_a, person_b, persons[100];

int main ()
{
    Person c;
    
    c.name = "yhq";
    //c.age = 18;  错误，不能访问私有变量
    c.set_age(18);
    c.add_money(100);
    
    c.say();
    cout << c.get_age() << endl;

    return 0;
}

