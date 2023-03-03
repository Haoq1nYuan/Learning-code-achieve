//https://www.acwing.com/problem/content/127/

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 50010;

PII com[N];

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        int w, s;
        scanf("%d%d", &w, &s);
        com[i] = {w + s, w};
    }
    
    sort(com, com + n);
    
    //sum存储当前的牛上方所有牛的重量之和
    //res存储最大风险值，贪心算法使其相对最小
    int res = -2e9, sum = 0;
    for (int i = 0; i < n; i++)
    {
        int w = com[i].second, s = com[i].first - w;
        res = max(res, sum - s);
        //更新sum
        sum += w;
    }
    
    cout << res << endl;
    
    return 0;
}