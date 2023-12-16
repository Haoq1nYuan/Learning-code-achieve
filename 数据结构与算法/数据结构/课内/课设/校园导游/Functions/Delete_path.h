// 删除路径
void Delete_path (unordered_map<string, Sight> m, int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{
    string na, nb, type;
    cout << "你想删除哪两个景点之间何种性质的路径：";
    cin >> na >> nb >> type;

    int a = stoi(m[na].getID());
    int b = stoi(m[nb].getID());

    if (type == "机动车道") 
    {
        *(g1[a] + b) = 0x3f3f3f3f;
        *(g1[b] + a) = 0x3f3f3f3f;
    }
    else if (type == "人行道")
    {
        *(g2[a] + b) = 0x3f3f3f3f;
        *(g2[b] + a) = 0x3f3f3f3f;      
    }
}