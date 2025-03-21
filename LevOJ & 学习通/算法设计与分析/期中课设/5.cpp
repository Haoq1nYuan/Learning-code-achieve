#include<bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

typedef pair<int, int> PII;
const int N = 50;

int a[N][N];

const int szx = 20;
const int szy = 40;

string s;

void get_map(string mp)
{
    //cin >> mp;
    for(int i = 1;i <= szx;i ++)
        for (int j = 1;j <= szy;j ++)
        {
            int pos = (i - 1) * szy + j;
            pos --;
            int st = mp[pos] - '0';
            a[i][j] = st;
        }

    return;
}

pair<int, int> get_ghost_pos1(string p)
{ 
    int x1 = (p[0] - '0') * 10 + p[1] - '0';
    int y1 = (p[2] - '0') * 10 + p[3] - '0';
    return {x1 ,y1};
}

pair<pair<int, int>, pair<int, int>> get_ghost_pos2(string p)
{
    int x1 = (p[0] - '0') * 10 + p[1] - '0';
    int y1 = (p[2] - '0') * 10 + p[3] - '0';
    int x2 = (p[4] - '0') * 10 + p[5] - '0';
    int y2 = (p[6] - '0') * 10 + p[7] - '0';
    return {{x2, y2},{x1 ,y1}};
}

PII preghost1;

pair<PII, PII> preghost2;

int person_x = 0;
int person_y = 0;

void init_mp()
{
    get_map(s);
    int cnt = 0;

    for(int i = 1;i <= szx;i ++)
    {
        for(int j = 1;j <= szy;j ++)
        {
            if (a[i][j] == 5) a[i][j] = 8;
            if (a[i][j] == 6) a[i][j] = 10;
            if (a[i][j] & 1) 
            {
                person_x = i;   // 
                person_y = j;   // 
            }
            if ((a[i][j] >> 3) & 1)
            {
                if (cnt == 0)
                {
                    preghost1.first = i;
                    preghost1.second = j;
                    cnt ++;
                }
                else
                {
                    preghost2.first = preghost1;
                    preghost2.second.first = i;
                    preghost2.second.second = j;
                }
            }
        }
    }
}

void react_ghost()
{
    if (s.size() == 8)
    {
        auto ghost = get_ghost_pos2(s); 

        int x1 = preghost2.first.first;
        int y1 = preghost2.first.second;

        int x2 = preghost2.second.first;
        int y2 = preghost2.second.second;

        a[x1][y1] ^= (1ll << 3);
        a[x2][y2] ^= (1ll << 3);

        a[ghost.first.first][ghost.first.second] ^= (1ll << 3);
        a[ghost.second.first][ghost.second.second] ^= (1ll << 3);

        preghost2 = ghost;
    }
    else if (s.size() == 4)
    {
        int x = preghost1.first;
        int y = preghost1.second;

        a[x][y] ^= (1ll << 3);

        auto ghost = get_ghost_pos1(s);

        a[ghost.first][ghost.second] ^= (1ll << 3);

        preghost1 = ghost;
    }

}

int seed = 135;
int nowv = 0;
const int mod = 1e9 + 7;

int my_rand(int l,int r)
{
    nowv += seed;
    nowv %= mod;
    nowv = (nowv * nowv) % mod;

    nowv += (5 * seed)/ 3;
    nowv %= mod;

    return (nowv % (r - l + 1) + l);
}

void D()
{
    a[person_x][person_y] ^= 1;
    person_x ++;
    a[person_x][person_y] ^= 1;
    cout << "D" << endl;
}

void U()
{
    a[person_x][person_y] ^= 1;
    person_x --;
    a[person_x][person_y] ^= 1;
    cout << "U" << endl;
}

void L()
{
    a[person_x][person_y] ^= 1;
    person_y --;
    a[person_x][person_y] ^= 1;
    cout << "L" << endl;
}

void R()
{
    a[person_x][person_y] ^= 1;
    person_y ++;
    a[person_x][person_y] ^= 1;
    cout << "R" << endl;
}

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int link[szx + 1][szy + 1];       // 豆子坐标链接到豆子编号
int link_back[szx * szy + 1][2];  // 豆子编号链接到豆子坐标

int dist_p[szx + 1][szy + 1];     // 存放吃豆人到豆子(i, j)的最短路径长
int dist_g1[szx + 1][szy + 1];    // 存放鬼1到豆子(i, j)的最短路径长
int dist_g2[szx + 1][szy + 1];    // 存放鬼2到豆子(i, j)的最短路径长

int move_p[szx + 1][szy + 1][2];  // 存放吃豆人到豆子(i, j)的路径的初始移动方向

int idx_been;                     // 豆子编号

bool used[szx * szy + 1];         // 判重数组，确保每个豆子只被吃一次
bool flag1, flag2;                // flag1判断吃豆人是否与鬼1相距为1，flag2判断吃豆人是否与鬼2相距为1

char last_move, last_last_move;   // 存放吃豆人上一时刻的行动及上上时刻的行动

struct dist                       // 存放所有合法策略
{
    int dist_p, dist_g;
    int tarx, tary;

    bool operator< (const dist d)const
    {
        if (dist_p != d.dist_p) return dist_p > d.dist_p;
        else return dist_g < d.dist_g;
    }
};

struct node                        // BFS中队列元素，存放当前遍历的节点位置及该点所在路径对应的吃豆人初始移动方向
{
    int x, y, move_x, move_y;
};

void bfs (int mode, int x, int y)
{
    if (mode == 1) 
    {
        memset(dist_p, -1, sizeof dist_p);
        dist_p[x][y] = 0;
    }
    else if (mode == 2)
    {
        memset(dist_g1, -1, sizeof dist_g1);
        dist_g1[x][y] = 0;
    }
    else if (mode == 3)
    {
        memset(dist_g2, -1, sizeof dist_g2);
        dist_g2[x][y] = 0;
    }

    queue<node> kk;
    kk.push({x, y, 0, 0});

    while (kk.size())
    {
        auto tem = kk.front();
        kk.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = tem.x + dx[k], ny = tem.y + dy[k];
            int move_x = tem.move_x, move_y = tem.move_y;
            if (tem.move_x + tem.move_y == 0) move_x = nx - tem.x, move_y = ny - tem.y;

            if (nx >= 1 && nx <= szx && ny >= 1 && ny <= szy && !used[link[nx][ny]])
                if (mode == 1 && (a[nx][ny] < 4 || a[nx][ny] == 10) && dist_p[nx][ny] == -1)
                {
                    move_p[nx][ny][0] = move_x, move_p[nx][ny][1] = move_y;
                    dist_p[nx][ny] = dist_p[tem.x][tem.y] + 1;
                    kk.push({nx, ny, move_x, move_y});
                }
                else if (mode == 2 && a[nx][ny] != 4 && dist_g1[nx][ny] == -1)
                {   
                    dist_g1[nx][ny] = dist_g1[tem.x][tem.y] + 1;
                    kk.push({nx, ny});
                }
                else if (mode == 3 && a[nx][ny] != 4 && dist_g2[nx][ny] == -1)
                {
                    dist_g2[nx][ny] = dist_g2[tem.x][tem.y] + 1;
                    kk.push({nx, ny});
                }
        }
    }
}

char solve()
{
    if (person_x == 1 && person_y == 1)  // 一旦地图换新，则重新初始化豆子编号、豆子编号与豆子坐标的链接数组、判重数组
    {
        memset(used, false, sizeof used);
        idx_been = 1;
        for (int i = 1; i <= szx; i ++)
            for (int j = 1; j <= szy; j ++)
                if (a[i][j] == 2 || a[i][j] == 10)
                {
                    link[i][j] = idx_been;
                    link_back[idx_been][0] = i, link_back[idx_been++][1] = j;
                }
    }

    bfs(1, person_x, person_y);          // 对吃豆人进行一次BFS
    
    // 判断鬼2是否存在，如果存在则判断鬼2与吃豆人的距离。
    if (preghost2.second.first && min(abs(person_x - preghost2.first.first) + abs(person_y - preghost2.first.second), 
    abs(person_x - preghost2.second.first) + abs(person_y - preghost2.second.second)) <= 1) 
    {
        if (abs(person_x - preghost2.first.first) + abs(person_y - preghost2.first.second) <= 1) 
        {
            bfs(3, preghost2.first.first, preghost2.first.second);
            flag1 = true;
        }
        if (abs(person_x - preghost2.second.first) + abs(person_y - preghost2.second.second) <= 1) 
        {
            bfs(3, preghost2.second.first, preghost2.second.second);
            flag2 = true;
        }
    }
    else flag1 = false, flag2 = false;

    // 判断鬼1与吃豆人的距离
    if (!preghost2.second.first && abs(person_x - preghost1.first) + abs(person_y - preghost1.second) <= 1) 
    {
        flag1 = true;
        bfs(2, preghost1.first, preghost1.second);
    }
    else flag1 = false;

    priority_queue<dist> final_dist;  // 定义存放策略的优先队列

    for (int i = 1; i < idx_been; i++)   // 将所有策略存放在队列中
    {
        dist d;
        d.dist_p = dist_p[link_back[i][0]][link_back[i][1]];
        if (flag1) d.dist_g = dist_g1[link_back[i][0]][link_back[i][1]];
        if (flag2) d.dist_g = min(d.dist_g, dist_g2[link_back[i][0]][link_back[i][1]]);
        d.tarx = link_back[i][0];
        d.tary = link_back[i][1];

        final_dist.push(d);
    }

    // 进行策略筛选
    int move_x, move_y, st_x, st_y;
    dist ans_dist;
    while (final_dist.size())
    {
        ans_dist = final_dist.top();
        final_dist.pop();

        // 不重复吃同一个豆子
        if (used[link[ans_dist.tarx][ans_dist.tary]]) continue;

        st_x = ans_dist.tarx, st_y = ans_dist.tary;
        move_x = move_p[st_x][st_y][0], move_y = move_p[st_x][st_y][1];

        // 死循环状态脱离策略
        if (last_last_move == 'D' && last_move == 'U' && move_x == 1 && move_y == 0) continue;
        if (last_last_move == 'U' && last_move == 'D' && move_x == -1 && move_y == 0) continue;
        if (last_last_move == 'R' && last_move == 'L' && move_x == 0 && move_y == 1) continue;
        if (last_last_move == 'L' && last_move == 'R' && move_x == 0 && move_y == -1) continue;

        // 若为B情况，则进行距离比较筛选
        if ((flag1 || flag2) && (ans_dist.dist_p < ans_dist.dist_g || 
        (ans_dist.dist_p == ans_dist.dist_g && ans_dist.dist_p > 1))) break;
        
        // 若为A情况，则直接返回最前的策略
        if (!flag1) break;
    }

    // 维护判重数组
    if (person_x + move_x == ans_dist.tarx && person_y + move_y == ans_dist.tary) used[link[st_x][st_y]] = true;
 
    // 维护前一时刻的行动，保存当前时刻的行动
    if (move_x == -1 && move_y == 0) 
    {
        if (last_move == 'D') last_last_move = 'D';
        else last_last_move = ' ';
        last_move = 'U';
    }
    else if (move_x == 0 && move_y == -1) 
    {
        if (last_move == 'R') last_last_move = 'R';
        else last_last_move = ' ';
        last_move = 'L';
    }
    else if (move_x == 1 && move_y == 0) 
    {
        if (last_move == 'U') last_last_move = 'U';
        else last_last_move = ' ';
        last_move = 'D';
    }
    else 
    {
        if (last_move == 'L') last_last_move = 'L';
        else last_last_move = ' ';
        last_move = 'R';
    }

    return last_move;
}

signed main () 
{
    while (cin >> s)
    {
        if(s.size() >= 40) init_mp();
        else react_ghost();

        char x = solve();

        if(x == 'U') U();
        else if(x == 'L') L();
        else if(x == 'R') R();
        else D();

        if((a[person_x][person_y] >> 1) & 1)
            a[person_x][person_y] ^= (1ll << 1);
    }

    return 0;
}

/*
10000000000000000000000000000000000000000200440200022220000020000000200222200000000000020200020002000200022004000200002000020440020020020022020020200000040000000002240000200000202000000024040020000200040444000404000422200000602000002024002004002200000000202000020000200200000000000020222020220202002000020002200020042200022002220400200022000000002020222000000000000000200202020004400000200002000042200000000004002200020000004240200020000000000004202002200022000200000402220000040000000024000200020200200020020202202000000000202000000420220200000204020200000000000000000200020000220022020200020200040000200020000020020022022200004000040000000400000042000002000000000020240022200000042200020000400000204220200024000000000000200200000020400020022000020020000020000000000000000000000000000000000000000000
00000000000000000000000000000000000000001200440200022220000020000000200222200000000000020200020002000200022004000200002000020440020020020022020020200000040000000002240000200000202000000024040020000200040444000404000422200000602000002024002004002200000000202000020000200200000000000020222020220202002000020002200020042200022002220400200022000000002020222000000000000000200202020004400000200002000042200000000004002200020000004240200020000000000004202002200022000200000402220000040000000024000200020200200020020202202000000000202000000420220200000204020200000000000000000200020000220022020200020200040000200020000020020022022200004000040000000400000042000002000000000020240022200000042200020000400000204220200024000000000000200200000020400020022000020020000020000000000000000000000000000000000000000000
00000000000000000000000000000000000000000100440200022220000020000000200222200000000000020200020002000200022004000200002000020440020020020022020020200000040000000002240000200000202000000024040020000200040444000404000422200000602000002024002004002200000000202000020000200200000000000020222020220202002000020002200020042200022002220400200022000000002020222000000000000000200202020004400000200002000042200000000004002200020000004240200020000000000004202002200022000200000402220000040000000024000200020200200020020202202000000000202000000420220200000204020200000000000000000200020000220022020200020200040000200020000020020022022200004000040000000400000042000002000000000020240022200000042200020000400000204220200024000000000000200200000020400020022000020020000020000000000000000000000000000000000000000000
*/

// 110，优化吃豆人下一步移动方向的获取方式。