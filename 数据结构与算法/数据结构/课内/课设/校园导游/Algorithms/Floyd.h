//单源最短路
void Print_path (int i, int j, int b, int path[SIZE + 1][SIZE + 1])
{
    if (i != j) Print_path(i, path[i][j], b, path);

    if (j != b) cout << j << "->";
    else cout << j;
}

void Floyd (unordered_map<string, Sight> m, int (*G1)[SIZE + 1], int (*G2)[SIZE + 1])
{
    int g[SIZE + 1][SIZE + 1], path[SIZE + 1][SIZE + 1];

    string na, nb, type;
    int a, b;
    cout << "你想求哪两个景点间的何种性质的最短路径：";
    cin >> na >> nb >> type;
    a = stoi(m[na].getID()), b = stoi(m[nb].getID());

    if (type == "机动车道")
        for (int i = 1; i <= SIZE; i++) 
            for (int j = 1; j <= SIZE; j++) 
            {
                path[i][j] = i;
                g[i][j] = *(G1[i] + j);
            }
    else if (type == "人行道")
        for (int i = 1; i <= SIZE; i++) 
            for (int j = 1; j <= SIZE; j++) 
            {
                path[i][j] = i;
                g[i][j] = *(G2[i] + j);
            }
    
    for (int k = 1; k <= SIZE; k++)
        for (int i = 1; i <= SIZE; i++)
            for (int j = 1; j <= SIZE; j++)
                if (g[i][j] > g[i][k] + g[k][j]) 
                {
                    g[i][j] = g[i][k] + g[k][j];
                    path[i][j] = path[k][j];
                }

    if (g[a][b] == 0x3f3f3f3f) 
    {
        cout << "“" << na << "”到“" << nb << "”之间不存在最短路径！" << endl;
        return;
    }
    
    cout << "“" << na << "”到“" << nb << "”的" << type << "最短路径长为：" << g[a][b] << endl;
    cout << "具体路线为：";

    Print_path(a, b, b, path);
    cout << endl;
}