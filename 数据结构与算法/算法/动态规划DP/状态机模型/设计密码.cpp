// https://www.acwing.com/problem/content/1054/

// KMP+状态机
/*
密码串记作M，模式串记作T
f[i][j]：密码串构造到i位置，且满足M[1…i-1]与T[1…j-1]匹配的所有情况的集合，属性是count

特殊点：
这里的状态转移是从i转移到i+1，所以思考方式也需要转变为“预测未来的状态”而非“讨论可能转变为当前状态的过去状态”

状态：
对于每一个i，都有至多26个字母能够选择，每一种字母都可能改变M[1…i]与T[1…j]的匹配情况，有可能是j回退到模式串中ne[j]的位置，
也可能是j回退到模式串开头0的位置，亦可能是前移一位（依然匹配），对于这些不同的匹配情况所对应的j的终点位置，我们就可以把它看作各种状态（节点），
显然这些状态可以可视化为匹配i后j在模式串中的位置，共有m+1种（[0…m]，包含完全匹配的情况，需要忽略）。
换言之，由i转移到i+1的所有情况就是从j位置向模式串中其他位置（m位置除外）发射一根箭头，至多有26根。

为什么要使用KMP：
密码串被构造到任意长度时都能够快速判断其与模式串的匹配情况，省去了大量繁琐的判断匹配情况的操作，并且ne数组求一遍就可以一直使用。
*/

#include <iostream>

using namespace std;

const int N = 60, mod = 1e9 + 7;

int n;
string t;    // 模式串
int f[N][N], ans;
int ne[N];

int main ()
{
    cin >> n >> t;
    t = ' ' + t;
    int m = t.size() - 1;
    
    // 求模式串的next数组
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && t[i] != t[j + 1]) j = ne[j];
        if (t[i] == t[j + 1]) j++;
        ne[i] = j; 
    }
    
    f[0][0] = 1;   // 程序入口
    for (int i = 0; i < n; i++)      // i从0开始，因为本题状态的转移方式是从i转移到i+1
        for (int j = 0; j < m; j++)  
            for (char k = 'a'; k <= 'z'; k++)  // k表示母串中的待匹配位置
            {
                int u = j;  // u表示模式串j位置更新过后在t串中的位置
                while (u && k != t[u + 1]) u = ne[u];   
                if (k == t[u + 1]) u++;        // 此时u就表示模式串中由j出发的箭头终点位置，即状态转移的终点状态
                
                // 如果此时模式串与母串未全部匹配，说明是一个合法情况
                if (u < m) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod;  // 针对所有的字母k，不断累加指向u状态的初状态
            }
    
    // 对n位置所有非完全匹配情况进行累加，得出最终答案
    for (int i = 0; i < m; i++) ans = (ans + f[n][i]) % mod;
    
    cout << ans << endl;
    
    return 0;
}

// 更直观的写法
#include <iostream>

using namespace std;

const int mod = 1e9 + 7, N = 55;

int n, f[N][N], ne[N];  // f[i][j]: 密码串构造到i位置的所有构造方法集合中最多的方案数
string t;

int main () {
    
    cin >> n >> t;
    t = ' ' + t;
    int len = t.size() - 1;
    
    for (int i = 2, j = 0; i < len; i++) {
        while (j && t[i] != t[j + 1]) j = ne[j];
        
        if (t[i] == t[j + 1]) j++;
        
        ne[i] = j;
    }
    
    f[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {  
        for (int j = 0; j < len; j++) {
            for (char k = 'a'; k <= 'z'; k++) {
                int u = j;
                
                while (u && k != t[u + 1]) u = ne[u];
                
                if (k == t[u + 1]) u++;
                
                if (u != len) f[i][u] = (f[i][u] + f[i - 1][j]) % mod;  
                // f[i][u] 而非 f[i + 1][u]
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < len; i++) ans = (ans + f[n][i]) % mod;
    cout << ans << endl;
    
    return 0;
}