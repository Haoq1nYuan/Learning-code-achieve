#include <iostream>

using namespace std;

int main ()
{
    int n; 

    while (scanf("%d", &n) != EOF)
    {
        int num[100000] = {0};

        num[0] = 1, num[1] = 1;

        //i表示 2 — n 之间的数
        for (int i = 2; i <= n; i++)
        {
            int tem = 0;
            //在当前有限的存储长度内存储乘积
            for (int j = 1; j <= num[0]; j++)
            {
                num[j] = num[j] * i + tem;
                tem = num[j] / 10;
                num[j] %= 10; 
            }

            //如果有进位，则扩展数组的存储长度
            //注意，此处不一定只扩展一位
            while (tem)
            {
                num[0]++;
                num[num[0]] = tem % 10;
                tem /= 10;
            }
        }

        for (int i = num[0]; i >= 1; i--) cout << num[i];
        puts("");
    }

    return 0;
}