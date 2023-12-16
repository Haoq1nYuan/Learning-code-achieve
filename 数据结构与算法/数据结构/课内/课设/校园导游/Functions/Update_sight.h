// 更新景点信息
pos Update_Position (map<pos, Sight> &s1, unordered_map<string, Sight> &s2, pos tem, string name)
{
    int new_x, new_y;
    cout  << "请输入新的坐标：";
    cin >> new_x >> new_y;

    s2[name].Update_Postion(new_x, new_y);
    pos tem2 = {new_x, new_y};
    s1[tem2] = Sight(s2[name]);
    s1.erase(tem);

    return tem2;
}

void Update_ID (Sight &s1, Sight &s2)
{
    string id;
    cout << "请输入新的编号：";
    cin >> id;

    s1.Update_ID(id);
    s2.Update_ID(id);
}

void Update_Name (map<pos, Sight> &s1, unordered_map<string, Sight> &s2, pos tem, string name)
{
    string new_name;
    cout << "请输入新的名称：";
    cin >> new_name;

    s1[tem].Update_Name(new_name);
    s2[new_name] = Sight(s1[tem]);
    s2.erase(name);
}

void Update_Intro (Sight &s1, Sight &s2)
{
    string intro;
    cout << "请输入新的简介：";
    cin >> intro;

    s1.Update_Intro(intro);
    s2.Update_Intro(intro);
}

void Update_Comment (Sight &s1, Sight &s2)
{
    string comment;
    cout << "请输入新的评价：";
    cin >> comment;

    s1.Update_Comment(comment);
    s2.Update_Comment(comment);
}

void Update_sight (map<pos, Sight> &s1, unordered_map<string, Sight> &s2)
{   
    string name;
    cout << "请输入你想修改的景点名称：";
    cin >> name;

    int x = s2[name].getX();
    int y = s2[name].getY();
    pos tem = {x, y};

    Update_ID(s1[tem], s2[name]);
    Update_Intro(s1[tem], s2[name]);
    Update_Comment(s1[tem], s2[name]);
    pos tem2 = Update_Position(s1, s2, tem, name);  
    Update_Name(s1, s2, tem2, name);                      // 函数顺序不能调换，涉及到map自动创建默认键值对的陷阱问题
}