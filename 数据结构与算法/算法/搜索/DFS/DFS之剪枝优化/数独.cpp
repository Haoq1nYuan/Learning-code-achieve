// https://www.acwing.com/problem/content/168/

//暴力解法
#include <iostream>

using namespace std;

const int N = 10;

string str;
int g[N][N];

bool check (int a, int x, int y)
{
    for (int i = 1; i <= 9; i++)
        if ((g[x][i] == a && i != y) || (g[i][y] == a && i != x)) return false;
    
    for (int i = (x - 1) / 3 * 3 + 1; i <= (x - 1) / 3 * 3 + 3; i++)
        for (int j = (y - 1) / 3 * 3 + 1; j <= (y - 1) / 3 * 3 + 3; j++)
            if (g[i][j] == a && i != x && j != y) return false;
    
    return true;
}

bool dfs (int x, int y)
{
    if (x == 10)
    {
        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++) 
                cout << g[i][j];
        cout << endl;
        
        return true; 
    }

    if (g[x][y]) 
    {
        if (dfs(y == 9 ? x + 1 : x, y == 9 ? 1 : y + 1)) return true;
    }
    else
    {
        for (int a = 1; a <= 9; a++)
            if (check(a, x, y))
            {   
                g[x][y] = a;
                if (dfs(y == 9 ? x + 1 : x, y == 9 ? 1 : y + 1)) return true;
                else g[x][y] = 0;
            }
    }
    
    return false;
}

int main ()
{
    while (cin >> str, str != "end")
    {
        int idx = 0;
        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++)
            {
                g[i][j] = str[idx] == '.' ? 0 : int(str[idx] - '0');
                idx++;
            }
             
        dfs(1, 1);
    }
    
    return 0;
}

// 优化
/*
优化搜索顺序：优先选择可取数值少的格子填入
位运算优化：
1. 使用9位01串表示一行，一列和一个九宫格中可取的数值，当需要求出一个格子合法的所有取值时，
只要将三个01串与起来即可，最终得到的01串中1的编号索引就是该格子上的所有合法取值。
2. 在得到某个格子上的合法取值01串后，可以使lowbit算法将遍历次数从9降低为合法取值的数目，即只遍历所有的合法取值。
*/

// 注意：由于本题使用位运算，所以格子下标从(0, 0)开始
/* 01串：010010110，1表示可取，0表示不可取
   数值：123456789，可取数值为2，3，5，8  */

#include <iostream>
#include <algorithm>

using namespace std;

// ------------------------------------------------------ //

const int N = 9, M = 1 << N;

// ones[i]存i的二进制表示（01串）中有多少个1
// map[i]负责求经过lowbit运算后的二进制结果中1的位置（从左往右从0开始），例：map[000001000] = 3
int ones[M], map[M];

// rows[i]表示第i行中当前可取的数值索引串
// cols[i]表示第i列中当前可取的数值索引串
// cell[i]表示以(i, j)为左上角的宫中当前可取的数值索引串
int rows[N], cols[N], cell[3][3];

// s负责存储格内原始数据
string s;

// ------------------------------------------------------ //

int lowbit (int a)
{
    return a & (-a);  
    // lowbit(x)返回一个01串，该串中只有一个位置为1，即x中最低位1的位置
    // 例：lowbit(010100100) = 000000100
}

void init ()
{
    // 初始化：每行每列每个九宫格中所有数都能选
    for (int i = 0; i < N; i++) rows[i] = cols[i] = (1 << N) - 1;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cell[i][j] = (1 << N) - 1;
}

void update (int x, int y, int a, int mode) // mode为1表示填入，mode为0表示删除
{
    int v = 1 << a;  // 求得待填入数值a + 1对应的二进制数位，若待填入数值为5，则a = 4, v = 000010000
    
    if (mode)  // 填入
    {
        rows[x] -= v;
        cols[y] -= v;
        cell[x / 3][y / 3] -= v;
        s[x * N + y] = '1' + a;
    }
    else  // 删除
    {
        rows[x] += v;
        cols[y] += v;
        cell[x / 3][y / 3] += v; 
        s[x * N + y] = '.';
    }
}

int get (int x, int y)
{
    return rows[x] & cols[y] & cell[x / 3][y / 3];   
}

bool dfs (int cnt)
{
    if (!cnt) return true; // 没有空格子时，得到最终答案。
    
    // 下面先求出当前所有空格中能填数值数量最少的那个格子(x, y)——优化搜索顺序
    int x, y;
    int minv = 10; // 用于寻找最小ones值，即最少的可选数值数量
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (s[i * N + j] == '.')
            {
                int state = get(i, j);
                if (ones[state] < minv)
                {
                    minv = ones[state];
                    x = i, y = j;
                }
            }

    int state = get(x, y); // 重新求出(x, y)的可取值情况
    for (int k = state; k; k -= lowbit(k))  // 依次遍历(x, y)上每一个可取数值
    {
        int tem = map[lowbit(k)]; // 得到具体数值的-1值

        update(x, y, tem, 1);
        if (dfs(cnt - 1)) return true;
        update(x, y, tem, 0);  // 恢复现场
    }
    
    return false;
}

// ------------------------------------------------------ //

int main ()
{
    // 初始化map数组
    for (int i = 0; i < N; i++) map[1 << i] = i; 
    
    // 初始化ones数组
    for (int i = 0; i < M; i++)  // 从 000000000(2) 枚举到 111111111(2)，对应所有的取值情况
        for (int j = i; j; j -= lowbit(j))  // 删去j中最低位的1
            ones[i] += 1;    // 将每一种取值情况对应的01串中1的数量存在ones中
    
    // 开始读入数据
    while (cin >> s, s != "end")
    {
        init();  // 初始化rows，cols，cell
        
        int cnt = 0; // 记录待填入数值的格子数量
        
        // 遍历初始数独数据，将已给出的数值添加入rows，cols，cell中
        for (int i = 0, k = 0; i < N; i++)
            for (int j = 0; j < N; j++, k++)
                if (s[k] != '.')
                {
                    int tem = s[k] - '1';
                    update(i, j, tem, 1);
                }
                else cnt++;
         
        // 初始化完成后，开始dfs
        dfs(cnt);
        
        cout << s << endl;
    }
    
    return 0;
}