// 景点的添加
struct pos
{
    int x = 0, y = 0;
    bool operator< (const pos &p) const
    {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};

void Add (map<pos, Sight> &S1, unordered_map<string, Sight> &S2)
{
    int x, y;
    string id, name, intro, comment;
    cout << "请依次输入你想添加的景点坐标，编号，名称，简介及学生评论：";
    cin >> x >> y >> id >> name >> intro >> comment;

    // 建立坐标与景点之间的索引
    pos p = {x, y};
    S1[p] = Sight(x, y, id, name, intro, comment);

    // 建立名称与景点之间的索引
    S2[name] = Sight(x, y, id, name, intro, comment);
}

void Add_sight (map<pos, Sight> &S1, unordered_map<string, Sight> &S2)
{
    for (int i = 1; i <= 4; i++) Add(S1, S2);
}