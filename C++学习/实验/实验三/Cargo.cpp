#include <iostream>

using namespace std;

class Cargo 
{
    public:
        Cargo (int w);
        ~Cargo ();
        int Weight ();
        static int TotalWeight ();

    private:
        int weight;
        static int totalWeight;
};  

int Cargo::totalWeight = 0;

Cargo::Cargo (int w)
{
    weight = w;
    totalWeight += weight;
}

Cargo::~Cargo () {}

// 单箱货物重量
int Cargo::Weight ()
{
    return weight;
}

// Cargo类所有对象总重
int Cargo::TotalWeight ()
{
    return totalWeight;
}

int main ()
{
    Cargo c1(30), c2(45);

    cout << "The weight of c1 is: " << c1.Weight() << endl;
    cout << "The weight of c2 is: " << c2.Weight() << endl;
    cout << "The totalweight is: " << Cargo::TotalWeight() << endl;

    return 0;
}