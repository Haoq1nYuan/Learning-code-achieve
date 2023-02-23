//https://www.acwing.com/problem/content/description/869/

#include <iostream>
#include <cmath>

using namespace std;

int n;

void divide (int u)
{
    //因为u中只可能存在一个比sqrt(u)大的质因子
    //所以可以直接枚举到 u / i
    for (int i = 2; i <= u / i; i++)
        //每碰到一个素数，合数就会不断除以那个素数直到变成
        //新的不能被原素数整除合数
        //所以此处的i肯定是下一个素数
        if (u % i == 0)  
        {
            int s = 0;
            //不断除以新素数
            while (u % i == 0)
            {
                u /= i;
                s++;
            }
            
            cout << i << ' ' << s << endl;
        }
    
    //单独处理大于sqrt(n)的质因子
    if (u > 1) cout << u << ' ' << 1 << endl;  
    puts("");
}

int main ()
{
    cin >> n;
    
    while (n--)
    {
        int a;
        cin >> a;
        divide(a);
    }
    
    return 0;
}