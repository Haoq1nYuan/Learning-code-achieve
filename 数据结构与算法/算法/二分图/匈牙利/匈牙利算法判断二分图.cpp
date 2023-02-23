//https://www.acwing.com/problem/content/863/

#include <iostream>
#include <cstring>

using namespace std;
const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
/*
st数组的作用：
比如说，当我们遍历到男k时，男k喜欢女s，
我们可以先让st[s] = true，表示女s已经被男k预定了
但是女s已经被男j选中了，不过没关系，我们通过find(match[s])
迭代操作去看一看，是否男j还有其他的选择，因为此时st[s]为真
所以女s不能再被男j选中，男j只能选其他他喜欢且未被预定的女生
如果男j把所有满足条件的女生都看过一遍发现还是不能配对，
那么我们不改变男j和女s的匹配情况，男k只能孤独一生了。
*/
bool st[N];
//match[i] = j表示当前女i和男j配对
int match[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find (int x)
{
    //遍历所有女生
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        //如果男生喜欢该女生
        if (!st[j])
        {
            //先将该女生预定
            st[j] = true;
            //查看是否该女生当前没有人爱或是爱她的人还能爱其他人
            if (match[j] == 0 || find(match[j]))
            {
                //如果可以，那么把这位女生让给男x
                match[j] = x;
                return true;
            }
        }
    }

    //如果所有女生都无法和男x配对，那么男x就孤独一生
    return false;
}

int main ()
{
    cin >> n1 >> n2 >> m;

    memset(h, -1, sizeof(h));

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }

    int res = 0;
    //遍历所有男生
    for (int i = 1; i <= n1; i++)
    {
        //此处一定要初始化st数组
        //因为每一次找女朋友的预定情况是不一样的
        memset(st, false, sizeof(st));
        if (find(i)) res++;
    }

    cout << res;

    return 0;
}