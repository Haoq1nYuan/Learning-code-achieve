//https://www.acwing.com/problem/content/description/3732/

//差分 + vector容器
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 200010;

int a[N], b[N];

int main ()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        
        vector<int> k;
        k.push_back(0);
        
        for (int i = 1; i <= n; i++)
        {
            k.push_back(0);
            
            if (!a[i]) continue;
            
            int len = min(a[i], i);
            b[i + 1] -= 1;
            b[i - len + 1] += 1;
        }
        
        for (int i = 1; i <= n; i++) 
        {
            k[i] = b[i] + k[i - 1];
            
            if (k[i] >= 1) printf("1 ");
            else printf("0 ");
        }
        puts("");
    }
    
    return 0;
}

//差分 + 数组
#include <iostream>
#include <cstring>

using namespace std;

const int N = 200010;

int a[N], b[N], c[N];

int main ()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        
        memset(b, 0, (n + 2) * 4);
        memset(c, 0, (n + 1) * 4);
    
        for (int i = 1; i <= n; i++)
        {
            c[i] = 0;
            
            if (!a[i]) continue;
            
            int len = min(a[i], i);
            b[i + 1] -= 1;
            b[i - len + 1] += 1;
        }
        
        for (int i = 1; i <= n; i++) 
        {
            c[i] = b[i] + c[i - 1];
            
            if (c[i] >= 1) printf("1 ");
            else printf("0 ");
        }
        puts("");
    }
    
    return 0;
}
