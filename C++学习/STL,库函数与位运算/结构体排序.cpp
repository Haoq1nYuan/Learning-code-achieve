//升序排列重载sort()
/* #include <iostream>
#include <algorithm>
using namespace std;

struct Rec 
{
    int a, b;
}k[5];

bool cmp ( Rec c, Rec d )
{   
    return c.a < d.a;
}

int main ()
{
    for ( int i = 0; i < 5; i++ ) 
        cin >> k[i].a >> k[i].b; 
    
    sort(k, k+5, cmp);

    for ( int i = 0; i < 5; i++ ) cout << k[i].a << " " << k[i].b << endl; 

    return 0;
} */

//升序排列内嵌重载
/* #include <iostream>
#include <algorithm>
using namespace std;

struct Rec 
{
    int a, b;

    bool operator< (const Rec& p)const
    {
        return a > p.a;
    }
}k[5];

int main ()
{
    for ( int i = 0; i < 5; i++ ) 
        cin >> k[i].a >> k[i].b;
    
    sort(k, k+5);

    for ( int i = 0; i < 5; i++ ) cout << k[i].a << " " << k[i].b << endl; 

    return 0;
} */

//结构体内嵌重载+vector容器
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rec 
{
    int a, b;

    bool operator< (const Rec& p)const
    {
        if ( a != p.a ) return a > p.a;
        else return b > p.b;
    }
};

int main ()
{
    vector<Rec> k = {{1,2},{4,7},{4,6},{7,4},{8,10}};
    
    sort(k.begin(), k.end());

    for ( int i = 0; i < k.size(); i++ ) cout << k[i].a << " " << k[i].b << endl; 

    return 0;
}