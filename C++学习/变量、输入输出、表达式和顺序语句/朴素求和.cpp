//https://www.acwing.com/problem/content/80/

//要求：1+2+3+……+n
#include <iostream>
using namespace std;

int n;

int getSum ( int num )
{
    int res = num;
    num > 0 && ( res += getSum(num-1) );  //如果num为0则直接返回
    return res;
}

int main ()
{
    cin >> n;

    cout << getSum(n);

    return 0;
}