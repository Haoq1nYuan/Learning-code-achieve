// 路径的添加
void Add(int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{
    while (true)
    {
        cout << "请输入你想添加的路径信息（起点，终点，长度，性质）：";
        int x, y, w;
        string type;
        cin >> x >> y >> w >> type;
        if (type == "机动车道") 
        {
            *(g1[x] + y) = min(*(g1[x] + y), w);
            *(g1[y] + x) = min(*(g1[y] + x), w);
            break;
        }
        else if (type == "人行道")
        {
            *(g2[x] + y) = min(*(g2[x] + y), w);
            *(g2[y] + x) = min(*(g2[y] + x), w);
            break;
        }
        else cout << "请输入正确的道路性质！";
    }
}

void Add_path(int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{
    for (int i = 1; i <= 9; i++)
        Add(g1, g2);
}