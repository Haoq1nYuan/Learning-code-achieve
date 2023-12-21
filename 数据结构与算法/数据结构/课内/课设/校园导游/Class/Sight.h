//景点类
class Sight
{
    public:
        Sight(int x = 0, int y = 0, string id = "", string name = "", string intro = "", string comment = "");
        Sight(const Sight &s);
        void Update_Postion(int new_x, int new_y);    // 更新坐标
        void Update_ID(string new_id);                // 更新编号
        void Update_Name(string new_name);            // 更新名称
        void Update_Intro(string new_intro);          // 更新简介
        void Update_Comment(string new_comment);      // 更新评价
        string getID();   // 返回编号
        int getX();       // 返回x坐标
        int getY();       // 返回y坐标
        void Show ();   
        ~Sight();
    private:
        string ID, Name, Intro, Comment;
        int X, Y;
};

Sight::Sight(int x, int y, string id, string name, string intro, string comment)
{
    X = x;
    Y = y;
    ID = id;
    Name = name;
    Intro = intro;
    Comment = comment;
}

Sight::Sight(const Sight &s)
{
    X = s.X;
    Y = s.Y;
    ID = s.ID;
    Name = s.Name;
    Intro = s.Intro;
    Comment = s.Comment;
}

void Sight::Update_Postion(int new_x, int new_y)
{
    X = new_x;
    Y = new_y;
}

void Sight::Update_ID(string new_id)
{
    ID = new_id;  
}

void Sight::Update_Name(string new_name)
{
    Name = new_name;
}

void Sight::Update_Intro(string new_intro)
{
    Intro = new_intro;
}

void Sight::Update_Comment(string new_comment)
{
    Comment = new_comment;
}

string Sight::getID()
{
    return ID;
}

int Sight::getX()
{
    return X;
}

int Sight::getY()
{
    return Y;
}

void Sight::Show()
{
    cout << "以下是" << Name << "的景点信息：" << endl;
    cout << "位置：(" << X << "," << Y << ")" << endl;
    cout << "景点编号：" << ID << endl;
    cout << "景点简介：" << Intro << endl;
    cout << "景点评论：" << Comment << endl;
}

Sight::~Sight() {}