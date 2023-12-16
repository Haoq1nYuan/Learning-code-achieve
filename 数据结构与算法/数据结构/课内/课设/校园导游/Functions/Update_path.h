// 更新路径信息
void Update (unordered_map<string, Sight> m, int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{
    string na, nb, type;
    cout << "请输入你想修改的路径两端的景点名称及路径性质：";
    cin >> na >> nb >> type;

    int a = stoi(m[na].getID());
    int b = stoi(m[nb].getID());

    int len;
    cout << "请输入你想修改的路径长度：";
    cin >> len;

    if (type == "机动车道") 
    {
        g1[a][b] = len;
        g1[b][a] = len;
    }
    else if (type == "人行道")
    {
        g2[a][b] = len;
        g2[b][a] = len;        
    }
}

void Update_path (unordered_map<string, Sight> m, int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{   
    Update(m, g1, g2);
}   