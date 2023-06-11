//数组解法
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


//vector
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100010;

int n;
int t[N];

int main ()
{
    while (scanf("%d", &n) != EOF)
    {
        vector<int> c;
        c.push_back(1);

        for (int i = 1; i <= n; i++)
        {
            vector<int> b;
            int k = i;
            while (k)
            {
                b.push_back(k % 10);
                k /= 10;
            }

            memset(t, 0, sizeof(t));
            for (int i = 0; i < b.size(); i++)
            {
                int tem = 0;
                for (int j = 0; j < c.size(); j++) 
                {
                    tem = b[i] * c[j];
                    t[i + j + 1] += (tem + t[i + j]) / 10;
                    t[i + j] = (tem + t[i + j]) % 10;
                }
            }

            int length = c.size() + b.size() - 1;
            while (length && t[length] == 0) length--;

            c.clear();
            for (int i = 0; i <= length; i++) c.push_back(t[i]);
        }

        for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
        puts("");
    }

    return 0;
}