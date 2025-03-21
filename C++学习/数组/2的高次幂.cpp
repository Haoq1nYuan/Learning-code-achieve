//次幂<=10000
#include <iostream>
#include <cstdio>

using namespace std;

int a[10000] = {1}, size = 1, n;

int main ()
{
    cin >> n;

    while ( n-- )  //取n次^2 --> 1乘n次2
    {
        int t = 0;

        for ( int i = 0; i < size; i++ )
        {
            t += a[i] * 2;   //t先存储每一位乘完2后的结果
            a[i] = t % 10;   //a[i]上还是存放乘完2后 <=9 的部分
            t /= 10;    //得到a[i]上元素值乘完2后 >9 的部分
        }

        if (t) a[size++] = t;    //如果乘完后 >9，则需要进位，在后面一位上存放进位的值
    }

    for (int i = size - 1; i >= 0; i -- ) cout << a[i];
    puts( "" );

    return 0;
}