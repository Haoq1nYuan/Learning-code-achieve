#include <iostream>

using namespace std;

class T
{  
    public:
	    T (int x=0) { p=new int(x);}
	    int Get () {return *p;}
	    ~T () { delete p;}
        T &operator= (const T &);
    private:
	    int *p;
};

T &T::operator= (const T &right)
{
    if(this == &right) return *this;
    delete p; //±ÜÃâÄÚ´æĞ¹Â©
    p = new int; 
    *p = *right.p;
    return *this;
}

int main ()
{
    T t1(5), t2(8);
    cout << "t1=" << t1.Get() << "\tt2=" << t2.Get() << endl;
    t2=t1;  //t2.operator=(t1)
    cout << "t1=" << t1.Get() << "\tt2=" << t2.Get() << endl;

    return 0;
}