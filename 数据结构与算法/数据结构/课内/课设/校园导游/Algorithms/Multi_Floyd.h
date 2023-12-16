// 有中间节点限制的多源最短路
// 不要重复游览某景点
// 求当前路径长度
int Get_dist (int (*g)[SIZE + 1], int st, int en, int k, int must[SIZE + 1])
{
    int distance = g[st][must[1]];
    if (distance == 0x3f3f3f3f) return 0x3f3f3f3f;

    for (int i = 1; i < k; i++)
        if (g[must[i]][must[i + 1]] == 0x3f3f3f3f) return 0x3f3f3f3f;
        else distance += g[must[i]][must[i + 1]];

    if (g[must[k]][en] == 0x3f3f3f3f) return 0x3f3f3f3f;
    else return distance += g[must[k]][en];
}

// 得到路径
void Get_path(int a, int b, int (*path)[SIZE + 1], int &idx, int anspath[SIZE])
{
    if (*(path[a] + b) == -1) return;
    else 
    {
        int k = *(path[a] + b);
        Get_path(a, k, path, idx, anspath);
        anspath[idx++] = k;
        Get_path(k, b, path, idx, anspath);
    }
}

// 保存具体路径
void Save_path (int anspath[SIZE + 1], int (*path)[SIZE + 1], int st, int en, int k, int &idx, int must[SIZE])
{
    anspath[idx++] = 1;
    Get_path(st, must[1], path, idx, anspath);

    for (int i = 1; i < k; i++)
    {
        anspath[idx++] = must[i];
        Get_path(must[i], must[i + 1], path, idx, anspath);
    }

    anspath[idx++] = must[k];
    Get_path(must[k], en, path, idx, anspath);
    anspath[idx++] = en;
}

void Mutli_Floyd (unordered_map<string, Sight> m, int (*G1)[SIZE + 1], int (*G2)[SIZE + 1])
{
    int g[SIZE + 1][SIZE + 1];       // 记录两两景点之间的最短路长
    int path[SIZE + 1][SIZE + 1];    // 记录两两景点之间最短路经的第一个必经点
    memset(path, -1, sizeof(path));  
    int must[SIZE + 1], k = 0;       // 记录途径点
    int anspath[SIZE + 1], idx = 1;  // 记录具体路径

    // 读入各景点
    string na, nb, sight, type;
    stringstream sights;
    cout << "你想求哪两个景点间的何种性质的最短路径：";
    cin >> na >> nb >> type;
    getchar();
    cout << "你还想经过哪几个景点：";
    getline(cin, sight);
    sights << sight;

    // 记录首尾景点
    int a = stoi(m[na].getID());
    int b = stoi(m[nb].getID());
    // 记录途经点
    while (sights >> sight) must[++k] = stoi(m[sight].getID());

    // 初始化
    if (type == "机动车道") 
    {
        for (int i = 1; i <= SIZE; i++) 
            for (int j = 1; j <= SIZE; j++) 
                g[i][j] = *(G2[i] + j);
    }
    else if (type == "人行道")
    {
        for (int i = 1; i <= SIZE; i++) 
            for (int j = 1; j <= SIZE; j++) 
                g[i][j] = *(G2[i] + j);   
    }

    // Floyd
    for (int k = 1; k <= SIZE; k++)
        for (int i = 1; i <= SIZE; i++)
            for (int j = 1; j <= SIZE; j++)
                if (g[i][j] > g[i][k] + g[k][j]) 
                {
                    g[i][j] = g[i][k] + g[k][j];
                    path[i][j] = k;
                }

    // 如果首尾节点之间不存在路径，则退出
    if (g[a][b] == 0x3f3f3f3f) 
    {
        cout << "不存在这样的路径！" << endl; 
        return;
    }

    // 先排序，表示所有途径点的第一种排列方式
    sort(must + 1, must + 1 + k);
    int min_dist = 0x3f3f3f3f;

    // 遍历途径点的所有排列方式
    do 
    {
        int d = Get_dist(g, a, b, k, must);
        if (min_dist > d) 
        {
            min_dist = d;
            Save_path(anspath, path, a, b, k, idx, must);
        }
    } while (next_permutation(must + 1, must + 1 + k));

    // 输出结果
    cout << "从“" << na << "”到“" << nb << "”，经过";
    while (sights >> sight) cout << "“" << sight << "”";
    cout << "的" << type << "最短路径长为：" << min_dist << endl;

    cout << "具体路径为：";
    for (int i = 1; i < idx - 1; i++) cout << anspath[i] << "->";
    cout << anspath[idx - 1] << endl;
}   

