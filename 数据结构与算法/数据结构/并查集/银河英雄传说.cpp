//https://www.acwing.com/problem/content/description/240/

#include <iostream>
#include <cmath>

using namespace std;

const int N = 30010;

int t, i, j;
char k[2];
int p[N], d[N], s[N];

int find (int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    
    return p[x];
}

int main ()
{
    cin >> t;
    
    for (int i = 1; i <= 30000; i++)
    {
        p[i] = i;
        s[i] = 1;
    }
    
    while (t--)
    {
        scanf("%s", k);
        
        if (k[0] == 'M')
        {
            scanf("%d%d", &i, &j);
            
            int pi = find(i), pj = find(j);
            if (pi != pj) 
            {
                //题目中将i列接在j列最后一艘战舰后面的意思：
                //就是要让我们更新pj到pj的距离，然后再更新整个pj的size
                //不要去想“如何接到最后一艘”这一操作，并查集将这一操作抽象化为更新距离
                d[pi] = s[pj];
                s[pj] += s[pi];
                p[pi] = pj;
            }
        }
        else
        {
            scanf("%d%d", &i, &j);
            
            if (find(i) == find(j)) printf("%d\n", max(0, abs(d[i] - d[j]) - 1));
            else puts("-1");
        }
    }
    
    return 0;
}