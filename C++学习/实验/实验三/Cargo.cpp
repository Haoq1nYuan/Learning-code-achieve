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
    cout << Weight() << " pounds have been purchased, ";
    cout << "now we have " << totalWeight << " pounds." << endl;
}

Cargo::~Cargo () 
{
    totalWeight -= weight;
    cout << weight << " pounds have been sended, ";
    cout << totalWeight << " pounds left." << endl;
}

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

    return 0;
}