//https://www.acwing.com/problem/content/773/

//朴素写法
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char k[205];
char ans;
int t;

int main ()
{
    cin >> t;
    
    while ( t-- )
    {
        cin >> k;
        
        int count = 1, Max = 0, i;
        
        for ( i  = 1; k[i] != '\0'; i++ ) 
        {
            if ( k[i] == k[i-1] ) 
            {
                count++;
                if ( k[i+1] == '\0' && count > Max )
                {
                    Max = count;  
                    ans = k[i-1];
                }
                else continue;
            }
            else if ( k[i] != k[i-1] ) 
            {
                if ( count > Max )
                {
                    Max = count;  
                    ans = k[i-1];
                }
                count = 1;
            }
        }
        
        cout << ans << " " << Max << endl;
    }
    
    return 0;
}

//精简写法
/* #include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T --)
    {
        int maxn = -1;//maxn记录最大长度
        string str, maxs;//maxs记录最大长度时的字符
        cin >> str;
        for(int i = 0; i < str.size(); i ++)
        {
            int j = i;
            int cnt = 0;
            while(str[j] == str[i] && j < str.size())//当指针j没有越界且与指针i的内容相同时移动
                j ++, cnt ++;
            if(cnt > maxn)//更新最大值
                maxn = cnt, maxs = str[i];
            i = j - 1;//移动指针i
        }
        cout << maxs << " " << maxn << endl;
    }
} */