//https://www.acwing.com/problem/content/description/894/

#include <iostream>

using namespace std;
const int N = 100010;

int c[N], res;

int main ()
{
    int n;
    cin >> n;
    //从第一级台阶开始读入
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &c[i]);
        //对奇数级台阶做异或运算
        if (i % 2) res ^= c[i];
    }
    
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}