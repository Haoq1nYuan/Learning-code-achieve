#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

const int N = 1005;

using namespace std;

int num[N], a, b, x;

void Search (int *num, int target)
{
    for (int i = 1; i <= 1000; i++)
        if (*(num + i) == target) 
        {
            cout << "找到了！顺序查找比较次数为：" << i << endl;
            return;
        }

    cout << "没有找到！" << endl;
}

void BinarySearch (int *num, int target)
{
    int cnt = 0;
    int l = 1, r = 1000, mid;

    while (l < r)
    {
        mid = (l + r) / 2;
        if (num[mid] >= target) r = mid;
        else l = mid + 1;  
        cnt ++;
    } 

    if (num[l] == target) cout << "找到了！折半查找比较次数为：" << cnt << endl;
    else cout << "没有找到！" << endl;
}

int main ()
{
    for (int i = 1; i <= 5; i++)
    {
        cout << "请输入数域的左界与右界：";
        cin >> a >> b;

        default_random_engine e;
        uniform_int_distribution<int> u(a, b);  // 生成[a, b]内的整数
        e.seed(time(0));

        for (int i = 1; i <= 1000; i++) num[i] = u(e);
        sort(num + 1, num + 1001);

        cout << "请输入你想查找的数：";
        cin >> x;

        // 只记录找到的第一个位置！
        Search(num, x);
        BinarySearch(num, x);
    }

    return 0;
}

/* 
样例1：[1, 1000] 334
样例2：[-1000, -1] -87
样例3：[-33, 100] -33
样例4：[100000, 1000000] 999999
样例5：[1, 3] 2
*/