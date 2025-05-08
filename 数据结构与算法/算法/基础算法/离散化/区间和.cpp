//https://www.acwing.com/problem/content/804/

//离散化的只是下标，不要将其他含义的数据也离散化
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;

//a数组存储所有坐标插入的值，s数组存储a数组的前缀和
int a[N], s[N];

//alls存储所有待离散化的坐标值
vector<int> alls;
//add存储x和c；query存储查询操作的左右边界
vector<PII> add, query;

//alls中元素下标从0开始
//找到alls中比x大的第一个值对应的下标，
//就相当于找到排序去重后x在alls中对应的下标，并使其+1
//这样映射后的所有元素下标最小是1，方便前缀和
int find (int x)
{
    int l = 0, r = alls.size() - 1;
    
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    
    //此处将离散后的映射的值都+1，保证所有下标从1开始
    return r + 1;
}

int main ()
{
    cin >> n >> m;
    
    //将数据录入
    while (n--)
    {
        int x, c;
        cin >> x >> c;
        
        add.push_back({x, c});
        
        //此处只需插入下标即可，c不用插入
        alls.push_back(x);
    }
    
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        
        query.push_back({l, r});
        
        alls.push_back(l);
        alls.push_back(r);
    }
    
    //先排序，后去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    //执行更改操作
    for (auto item : add)
    {
        int x = find(item.first);   // 得到映射后的索引值（例：1，3，7 -> 1，2，3）
        a[x] += item.second;
    }
    
    //维护前缀和数组
    int len = alls.size();
    for (int i = 1; i <= len; i++ ) s[i] = s[i-1] + a[i];
    
    //执行查询操作
    for (auto item : query)
    {
        int l = find(item.first);
        int r = find(item.second);
        
        cout << s[r] - s[l-1] << endl;
    }
    
    return 0;
}

//map做法
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define pii pair<int, int>
const int inf = 1e9 + 5;
vector<pii> a;
map<int, int> mp;

int main()
{
    int n, m;
    cin >> n >> m;
    while(n --)
    {
        int x, c;
        cin >> x >> c;
        if(mp.find(x) == mp.end()) mp[x] = c;  //x未出现过
        else mp[x] += c;  //x出现过
    }
    //这些操作完成过后map已经自动将所有元素去重并且排好序了

    int sum = 0;
    for(pii x : mp)  //计算前缀和
    {
        a.push_back({x.first, sum});  //这里的sum不包含x.first上的值，方便使用upper_bound()
        sum += x.second;
    }
    a.push_back({inf, sum});  //最后加一个无穷大的点，方便处理
    //因为mp是有序的，所以a是有序的
    while(m --)
    {
        int l, r;
        cin >> l >> r;
        
        //此处要注意，pair的排序原则就是先比较第一个元素的大小关系，然后再比较第二个元素的大小关系
        //lower_bound 找到大于的点
        //pair中第二个元素，也就是前缀和，我们将它设为无穷小，可以保证找到第一个大于等于l的点
        //同理，派人中第二个元素设为无穷大，就可以保证渠道第一个大于r的点
        auto p1 = lower_bound(a.begin(), a.end(), (pii){l , -inf}); 
        auto p2 = lower_bound(a.begin(), a.end(), (pii){r , inf});  

        //以前缀和的方式来看，需要s[r] - s[l - 1]，但是这里a中k下标对应的前缀和并不含k，
        //不过我们在进行lower_bound操作时找到的正是 l 和 r + 1
        //这里 a[l] = c[0] + c[1] + …… + c[l - 1]
        //a[r + 1] = c[0] + …… + c[r]，二者相减本质上是相同的
        cout << p2 -> second - p1 -> second << endl;
    }
    return 0;
}
