// É¾³ý¾°µã
void Delete_sight(map<pos, Sight> &s1, unordered_map<string, Sight> &s2, int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{
    string name;
    cout << "ÄãÏëÉ¾³ýÄÄ¸ö¾°µã£º";
    cin >> name;
    
    int ID = stoi(s2[name].getID());
    int x = s2[name].getX();
    int y = s2[name].getY();
    pos tem = {x, y};
    s1.erase(tem);
    s2.erase(name);

    for (int i = 1; i <= SIZE; i++)
    {
        if (*(g1[i] + ID) != 0) *(g1[i] + ID) = 0x3f3f3f3f;
        if (*(g1[ID] + i) != 0) *(g1[ID] + i) = 0x3f3f3f3f;
        if (*(g2[i] + ID) != 0) *(g2[i] + ID) = 0x3f3f3f3f;
        if (*(g2[ID] + i) != 0) *(g2[ID] + i) = 0x3f3f3f3f;
    }
}