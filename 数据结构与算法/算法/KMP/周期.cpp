//https://www.acwing.com/problem/content/143/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000010;

int n;
char p[N];
int ne[N];

int main ()
{
    int cnt = 1;
    while (cin >> n, n)
    {
        memset(ne, 0, 4 * n);
        
        cin >> (p + 1);
        
        for (int i = 2, j = 0; i <= n; i++)
        {
            while (j && p[i] != p[j + 1]) j = ne[j];
            
            if (p[i] == p[j + 1]) j++;
            
            ne[i] = j;
        }
        
        cout << "Test case #" << cnt++ << endl;
        
        for (int i = 2; i <= n; i++)
        {
            //画图即可理解，i - ne[i] 都是一个可能的循环节
            int t = i - ne[i];
            //此处对题设条件及循环节的定义进行判断
            if (i % t == 0 && i / t > 1)
                cout << i << ' ' << i / t << endl;
        }

        puts("");
    }
    
    return 0;
}