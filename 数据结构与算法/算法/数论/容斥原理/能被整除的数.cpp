//https://www.acwing.com/problem/content/892/

#include <iostream>

using namespace std;
typedef long long ll;

int p[20];

int main ()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> p[i];
    
    int res = 0;
    //枚举从 0000……1 ~ 111……111（m位二进制数）的每一个集合状态，
    //并得到每一个集合状态对应的数目
    //每一个集合状态都包含着至少一个事件
    // 1 << m 表示 1 右移 m 位，是第一个大于 11111……111（m位） 的二进制数
    for (int i = 1; i < 1 << m; i++)
    {
        //t存储选中集合对应质数的乘积
        //s表示选中的集合数量
        int t = 1, s = 0;
        //枚举当前状态的每一个二进制位
        for (int j = 0; j < m; j++)
            //如果 i 的二进制数某一位是 1 才操作，
            //为 0 表示该位置对应的事件不存在集合内，所以无需操作
            if (i >> j & 1)
            {
                //如果乘积大于0，则n/t = 0，
                //即当前集合中所有元素都不能被任何一个质数整除，
                //直接跳到下一个循环即可
                if ((ll)t * p[j] > n)
                {
                    t = -1;
                    break;
                }
                else
                {
                    //更新所有质数乘积
                    t *= p[j];
                    //如果选中，则更新s
                    s++;
                }
            }
            
        //如果 t = -1，说明
        if (t != -1)
        {
            //根据容斥原理，奇数个元素的集合系数为1，反之为-1
            //这里 n/t 就是集合内元素个数（下取整）
            if (s % 2) res += n / t;
            else res -= n / t;
        }
    }
    
    cout << res << endl;
    
    return 0;
}