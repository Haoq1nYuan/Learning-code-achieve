// 景点信息的查询
void Search_sight (unordered_map<string,Sight> m)
{
    string name;
    cout << "请输入一个景点名称：";
    cin >> name;

    if (m.find(name) != m.end()) m[name].Show();
    else cout << "景点不存在！" << endl;
}