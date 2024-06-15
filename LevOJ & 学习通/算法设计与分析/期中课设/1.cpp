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

int link[szx + 1][szy + 1];
int link_back[szx * szy + 1][2];
int dist_p[szx + 1][szy + 1];
int dist_g1[szx + 1][szy + 1];
int dist_g2[szx + 1][szy + 1];
int pre_path[szx + 1][szy + 1][2];

struct dist
{
    int dist_p, dist_g;
    int tarx, tary;

    bool operator< (const dist d)const
    {
        if (dist_p != d.dist_p) return dist_p < d.dist_p;
        else return dist_g > d.dist_g;
    }
} final_dist[szx * szy + 1];

bool used[szx * szy + 1];

int idx_been = 1;

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

    queue<PII> kk;
    kk.push({x, y});

    while (kk.size())
    {
        auto tem = kk.front();
        kk.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = tem.first + dx[k], ny = tem.second + dy[k];

            if (nx >= 1 && nx <= szx && ny >= 1 && ny <= szy && !used[link[nx][ny]])
                if (mode == 1 && (a[nx][ny] < 4 || a[nx][ny] == 10) && dist_p[nx][ny] == -1)
                {
                    pre_path[nx][ny][0] = tem.first, pre_path[nx][ny][1] = tem.second; 
                    dist_p[nx][ny] = dist_p[tem.first][tem.second] + 1;
                    kk.push({nx, ny});
                }
                else if (mode == 2 && a[nx][ny] < 4 && dist_g1[nx][ny] == -1)
                {   
                    dist_g1[nx][ny] = dist_g1[tem.first][tem.second] + 1;
                    kk.push({nx, ny});
                }
                else if (mode == 3 && a[nx][ny] < 4 && dist_g2[nx][ny] == -1)
                {
                    dist_g2[nx][ny] = dist_g2[tem.first][tem.second] + 1;
                    kk.push({nx, ny});
                }
        }
    }
}

char solve()
{
    /*  
        不要改动a数组的信息！
        a[i][j] = 0  时 为空地
        a[i][j] = 1  时 为人
        a[i][j] = 2  时 为豆子
        a[i][j] = 4  时 为墙
        a[i][j] = 8  时 为鬼
        a[i][j] = 10 时 为鬼和豆子
        不要改动person_x, person_y变量!
        person_x   是吃豆人的x坐标
        person_y   是吃豆人的y坐标
    */    
    
    if (idx_been == 1)
        for (int i = 1; i <= szx; i ++)
            for (int j = 1; j <= szy; j ++)
                if (a[i][j] == 2 || a[i][j] == 10)
                {
                    link[i][j] = idx_been;
                    link_back[idx_been][0] = i, link_back[idx_been++][1] = j;
                }

    bfs(1, person_x, person_y);
    
    if (preghost2.second.first) 
    {
        bfs(3, preghost2.first.first, preghost2.first.second);
        bfs(3, preghost2.second.first, preghost2.second.second);
    }
    else bfs(2, preghost1.first, preghost1.second);

    for (int i = 1; i < idx_been; i++) 
    {
        final_dist[i].dist_p = dist_p[link_back[i][0]][link_back[i][1]];
        final_dist[i].dist_g = dist_g1[link_back[i][0]][link_back[i][1]];
        if (preghost2.second.first) final_dist[i].dist_g = min(final_dist[i].dist_g, dist_g2[link_back[i][0]][link_back[i][1]]);
        final_dist[i].tarx = link_back[i][0];
        final_dist[i].tary = link_back[i][1];
    }

    sort(final_dist + 1, final_dist + idx_been);

    int ans_idx = 0;
    for (int i = 1; i < idx_been; i++)
    {
        if (used[i]) continue;
        
        if (final_dist[i].dist_p < final_dist[i].dist_g) 
        {
            ans_idx = i;
            break;
        }
        else continue;
    }

    if (ans_idx == 0) ans_idx == 1;

    int st_x = final_dist[ans_idx].tarx, st_y = final_dist[ans_idx].tary;
    while (!(pre_path[st_x][st_y][0] == person_x && pre_path[st_x][st_y][1] == person_y))
    {
        int temx = pre_path[st_x][st_y][0], temy = pre_path[st_x][st_y][1];
        st_x = temx, st_y = temy;
    }

    int move_x = st_x - person_x, move_y = st_y - person_y;

    if (st_x == final_dist[ans_idx].tarx && st_y == final_dist[ans_idx].tary) used[link[st_x][st_y]] = true;
 
    if (move_x == -1 && move_y == 0) return 'U';
    else if (move_x == 0 && move_y == -1) return 'L';
    else if (move_x == 1 && move_y == 0) return 'D';
    else return 'R';
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

// 44