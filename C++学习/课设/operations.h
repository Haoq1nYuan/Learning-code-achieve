#pragma once
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <map>
#include <fstream>
#include <string>

#define MAXSIZE 100

// 操作索引
string operation;
bool ifsave = true;
bool ifbreak;

// 构建各类媒体与其编号的索引
std::unordered_map<std::string, disc> Disc_id_list;
std::unordered_map<std::string, book> Book_id_list;
std::unordered_map<std::string, drawing> Drawing_id_list;

// 判重以及编号标题链接
std::map<int, int> ID_list;
std::unordered_map<std::string, std::vector<std::string>> Name_to_ID;

// 媒体信息提示列表
std::map<int, std::vector<std::string>> title = {{1, {"编号", "标题", "作者", "评级", "生产商", "生产时间", "视频时长"}},
                                                 {2, {"编号", "标题", "作者", "评级", "出版社", "ISBN号", "总页数"}},
                                                 {3, {"编号", "标题", "作者", "评级", "所属国家", "长(cm)", "宽(cm)"}}};

std::map<int, std::string> guide = {{1, "----------------------------------------------- 视 频 光 盘 ------------------------------------------------"},
                                    {2, "-------------------------------------------------- 书  籍 --------------------------------------------------"}, 
                                    {3, "-------------------------------------------------- 图  画 --------------------------------------------------"},
                                    {4, "------------------------------------------------------------------------------------------------------------"}};

// 信息读入相关变量
std::stringstream information;
std::string tem;
std::vector<string> infor;

int type, Type;
string old_name;
string Name, Id;
double Len, Wid;
string oper;

//-----------主控页面-----------//

void Menu()
{
    std::cout << "[==================||媒体库管理系统||==================]" << std::endl;
    std::cout << "[-----------------------||MENU||-----------------------]" << std::endl;
    std::cout << "|                     0. 退出系统                      |" << std::endl;
    std::cout << "|                     1. 添加信息                      |" << std::endl;
    std::cout << "|                     2. 修改信息                      |" << std::endl;
    std::cout << "|                     3. 查询信息                      |" << std::endl;
    std::cout << "|                     4. 显示信息                      |" << std::endl;
    std::cout << "|                     5. 删除信息                      |" << std::endl;
    std::cout << "|                     6. 统计信息                      |" << std::endl;
    std::cout << "|                     7. 保存信息                      |" << std::endl;
    std::cout << "|                     8. 读取信息                      |" << std::endl;
    std::cout << "[======================================================]" << std::endl;
}

//-----------输入信息-----------//

bool Input(int mode)
{
    infor.clear();
    information.clear();

    std::cout << "[  " << title[type][0] << ", " << title[type][1] << ", " << title[type][2] << ", " << title[type][3]
        << ", " << title[type][4] << ", " << title[type][5] << ", " << title[type][6] << "  ]" << std::endl;

    std::cin.sync();
    getline(std::cin, tem);
    information << tem;

    while (information >> tem) infor.push_back(tem);

    if (infor.size() != 7)
    {
        std::cout << std::endl;
        std::cout << "[            输入信息数量有误，请重新输入！            ]" << std::endl << std::endl;
        return false;
    }
    else if ((ID_list[stoi(infor[0])] && mode) || (!mode && ID_list[stoi(infor[0])] && infor[0] != Id))
    {
        std::cout << std::endl;
        std::cout << "[               编号已经存在，请重新输入！              ]" << std::endl << std::endl;
        return false;
    }
    else if (infor[3] != "未评级" && infor[3] != "一般" && infor[3] != "成人" && infor[3] != "儿童")
    {
        std::cout << std::endl;
        std::cout << "[   评级分为：未评级，一般，成人，儿童。请重新输入！   ]" << std::endl << std::endl;
        return false;
    }
    else
    {
    	ifsave = false;
    	return true;
	}

	return true;
}

//-----------异常处理-----------//

bool Judge_StoD(string len, string wid)
{
    try
    {
        Len = stod(len);
        Wid = stod(wid);
    }
    catch (const std::exception&)
    {
        std::cout << std::endl << "[               图画的尺寸必须是浮点数！               ]" << std::endl << std::endl;
        return false;
    }

    return true;
}

bool Judge_StoI(string tem)
{
    try 
    {
        for(int i = 0; i < tem.size(); i++)
        {
            if(!i && tem.size() > 1) continue;
            if(tem[i] < '0' || tem[i] > '9') throw 0;
        }
    }
    catch (int e)
    {
        if (!e) return false;
    }

    return true;
}

//-----------添加信息-----------//

template <typename Media, typename A, typename B>
void Add_Each_Media(Media& m, string id, string title, string author, string rating, string other_1, A other_2, B other_3)
{
    m[id] = { id, title, author, rating, other_1, other_2, other_3 };
}

void Add_Media()
{
    if (MAXSIZE == ID_list.size())
    {
        std::cout << "[              媒体库已满！请先删除媒体。              ]" << std::endl << std::endl;
        return;
    }

    while (true)
    {
        std::cout << "请选择你想添加媒体类别(1: 视频光盘, 2: 书籍, 3: 图画): ";
        std::cin.sync();
        std::getline(std::cin, oper);
        std::cout << std::endl;

        oper.erase(0, oper.find_first_not_of(' '));  // 删除前部的空格，允许误输入

        if (!Judge_StoI(oper) || oper == "") // 拦截非数字输入
            std::cout << "[                请输入合法的类别索引！                ]" << std::endl << std::endl;
        else if (stoi(oper) > 3 || stoi(oper) < 1)  // 拦截范围越界输入
            std::cout << "[                请输入合法的类别索引！                ]" << std::endl << std::endl;
        else break;
    }

    type = stoi(oper);
    std::cout << "请输入媒体的各项信息，每项信息之间用空格隔开: " << std::endl;

    while (true)
        if (!Input(1)) continue;
        else
        {
            if (type== 1) Add_Each_Media(Disc_id_list, infor[0], infor[1], infor[2], infor[3], infor[4], infor[5], infor[6]);
            if (type == 2) 
            {
                if (!Judge_StoI(infor[6])) 
                {
                    std::cout << std::endl << "[                书籍的页数必须是整数！                ]" << std::endl << std::endl;
                    continue;
                }
                else Add_Each_Media(Book_id_list, infor[0], infor[1], infor[2], infor[3], infor[4], infor[5], stoi(infor[6]));
            }
            if (type == 3)
            {
                if (!Judge_StoD(infor[5], infor[6])) continue;
                Add_Each_Media(Drawing_id_list, infor[0], infor[1], infor[2], infor[3], infor[4], Len, Wid);
            }

            break;
        }

    ID_list[stoi(infor[0])] = type;
    Name_to_ID[infor[1]].push_back(infor[0]);
    std::cout << std::endl << "[                    媒体添加成功！                    ]" << std::endl << std::endl;
}

//-----------修改信息-----------//

template <typename Media, typename A, typename B>
void Update_Each_Media(Media& m, string id, string title, string author, string rating, string other_1, A other_2, B other_3)
{
    old_name = m[Id].title();
    m[Id].edit(id, title, author, rating, other_1, other_2, other_3);

    if (Id != id)
    {
        m[id] = m[Id];
        m.erase(Id);

        ID_list.erase(stoi(Id));
        ID_list[stoi(id)] = type;
    }
    else ID_list[stoi(id)] = type;

    if (title != old_name)
    {
        Name_to_ID[old_name].push_back(infor[0]);
        Name_to_ID[infor[1]] = Name_to_ID[old_name];
        Name_to_ID.erase(old_name);
    }
    else Name_to_ID[title].push_back(id);
}

void Update_Media()
{
    if (ID_list.size())
    {
        while (true)
        {
            std::cout << "请输入你想修改的媒体编号：";
            std::cin.sync();
            std::getline(std::cin, Id);
            std::cout << std::endl;

            Id.erase(0, Id.find_first_not_of(' '));

            if (!Judge_StoI(Id) || Id == "") 
                std::cout << "[                  请输入合法的编号！                  ]" << std::endl << std::endl;
            else break;
        }

        if (!ID_list[stoi(Id)])   // 当查询不存在的键时，map会自动创建一个默认值来匹配这个不存在的键。
        {
            ID_list.erase(stoi(Id));
            std::cout << "[                 不存在该编号的媒体！                 ]" << std::endl << std::endl;
        }
        else 
        {
            type = ID_list[stoi(Id)];
            std::cout << "请输入更新的各项媒体信息，每项信息之间用空格隔开：" << std::endl;

            while (true)
                if (!Input(0)) continue;
                else
                {
                    if (type == 1) Update_Each_Media(Disc_id_list, infor[0], infor[1], infor[2], infor[3], infor[4], infor[5], infor[6]);
                    if (type == 2) 
                    {
                        if (!Judge_StoI(infor[6])) 
                        {
                            std::cout << std::endl << "[                书籍的页数必须是整数！                ]" << std::endl << std::endl;
                            continue;
                        }
                        else Add_Each_Media(Book_id_list, infor[0], infor[1], infor[2], infor[3], infor[4], infor[5], stoi(infor[6]));
                    }
                    if (type == 3)
                    {
                        if (!Judge_StoD(infor[5], infor[6])) continue;
                        Update_Each_Media(Drawing_id_list, infor[0], infor[1], infor[2], infor[3], infor[4], Len, Wid);
                    }

                    break;
                }

            std::cout << std::endl << "[                  媒体信息修改成功！                  ]" << std::endl << std::endl;
            ifsave = false;
        }
    }
    else std::cout << "[                    当前媒体库为空！                  ]" << std::endl << std::endl;
}

//-----------查询信息-----------//

template <typename Media>
void Search_Media_in_Type(Media m)
{
    using std::left;
    std::cout << std::endl << "找到了！媒体信息如下：" << std::endl << std::endl;
    std::cout << guide[Type] << std::endl;
    std::cout << left << std::setw(10) << title[Type][0] << left << std::setw(20) << title[Type][1] << left << std::setw(20)
                << left << title[Type][2] << left << std::setw(10) << title[Type][3] << left << std::setw(20) << title[Type][4]
                << left << std::setw(20) << title[Type][5] << left << std::setw(10) << title[Type][6] << std::endl;
    std::cout << guide[4] << std::endl;

    for (auto i = ID_list.begin(); i != ID_list.end(); i++) 
        if (i->second == Type) std::cout << m[std::to_string(i->first)] << std::endl;
}

template <typename Media>
void Search_Media_in_Title_or_Id(Media m)
{	
	using std::left;
    std::cout << guide[Type] << std::endl;
    std::cout << left << std::setw(10) << title[Type][0] << left << std::setw(20) << title[Type][1] << left 
	          << std::setw(20) << title[Type][2] << left << std::setw(10) << title[Type][3] << left << std::setw(20)
	          << title[Type][4] << left << std::setw(20) << title[Type][5] << left << std::setw(10) << title[Type][6] << std::endl;
    std::cout << guide[4] << std::endl;

    std::cout << m[Id] << std::endl << std::endl;
}

void Search_Media()
{
    if (ID_list.size())
    {
        while (true)
        {
            std::cout << "你想以哪种方式查询(1: 按标题, 2: 按编号, 3: 按类别): ";
            std::cin.sync();
            std::getline(std::cin, oper);

            oper.erase(0, oper.find_first_not_of(' '));

            if(!Judge_StoI(oper) || oper == "") 
                std::cout << std::endl << "[                请输入合法的类别索引！                ]" << std::endl << std::endl;
            else if (stoi(oper) > 3 || stoi(oper) < 1) 
                std::cout << std::endl << "[                请输入合法的类别索引！                ]" << std::endl << std::endl;
            else break;
        }

        type = stoi(oper);

        if (type == 1)
        {
            std::cout << "请输入你想查询的媒体标题：";
            std::cin.sync();
			std::getline(std::cin, Name);

            if (!Name_to_ID[Name].size()) 
                std::cout << std::endl << "[                   该标题不存在！                     ]" << std::endl;
            else
            {
                std::cout << std::endl << "找到了！媒体信息如下：" << std::endl << std::endl;

                for (int i = 0; i < Name_to_ID[Name].size(); i++)
                {
                    Type = ID_list[stoi(Name_to_ID[Name][i])];
                    Id = Name_to_ID[Name][i];

                    if (Type == 1) Search_Media_in_Title_or_Id(Disc_id_list);
                    if (Type == 2) Search_Media_in_Title_or_Id(Book_id_list);
                    if (Type == 3) Search_Media_in_Title_or_Id(Drawing_id_list);
                }
            }
        }
        else if (type == 2)
        {
            while (true)
            {
                std::cout << "请输入你想查询的媒体编号：";
                std::cin.sync();
                std::getline(std::cin, Id);
                std::cout << std::endl;

                Id.erase(0, Id.find_first_not_of(' '));

                if (!Judge_StoI(Id) || Id == "") 
                    std::cout << "[                  请输入合法的编号！                  ]" << std::endl << std::endl;
                else break;
            }

            if (!ID_list[stoi(Id)]) 
            {
                ID_list.erase(stoi(Id));
                std::cout << "[                    该编号不存在！                    ]" << std::endl;
            }
            else
            {
                std::cout << std::endl << "找到了！媒体信息如下：" << std::endl << std::endl;
                Type = ID_list[stoi(Id)];

                if (Type == 1) Search_Media_in_Title_or_Id(Disc_id_list);
                if (Type == 2) Search_Media_in_Title_or_Id(Book_id_list);
                if (Type == 3) Search_Media_in_Title_or_Id(Drawing_id_list);
            }
        }
        else
        {
            while (true)
            {
                std::cout << "请输入你想查询的媒体类别(1: 视频光盘, 2: 书籍, 3: 图画): ";
                std::cin.sync();
                std::getline(std::cin, oper);

                oper.erase(0, oper.find_first_not_of(' '));

                if (!Judge_StoI(oper) || oper == "") 
                    std::cout << std::endl << "[                请输入合法的类别索引！                ]" << std::endl << std::endl;
                else if (stoi(oper) > 3 || stoi(oper) < 1) 
                    std::cout << std::endl << "[                请输入合法的类别索引！                ]" << std::endl << std::endl;
                else break;
            }

            Type = stoi(oper);

            if (Type == 1) 
            {
                if (!Disc_id_list.size()) std::cout << std::endl << "[                 视频光盘类没有物品！                 ]" << std::endl;
                else Search_Media_in_Type(Disc_id_list);
            }
            if (Type == 2) 
            {
                if (!Book_id_list.size()) std::cout << std::endl << "[                   书籍类没有物品！                   ]" << std::endl;
                else Search_Media_in_Type(Book_id_list);
            }
            if (Type == 3) 
            {
                if (!Drawing_id_list.size()) std::cout << std::endl << "[                   图画类没有物品！                   ]" << std::endl;
                else Search_Media_in_Type(Drawing_id_list);
            }
        }

        std::cout << std::endl;
    }
    else std::cout << "[                    当前媒体库为空！                  ]" << std::endl << std::endl;
}

//-----------展示信息-----------//

template <typename Media>
void Show_Each_Type(Media m, int type)
{
	using std::left;
    std::cout << guide[type] << std::endl;
    std::cout << left << std::setw(10) << title[type][0] << left << std::setw(20) << title[type][1] << left << std::setw(20) << left
	<< title[type][2] << left << std::setw(10) << title[type][3] << left << std::setw(20) << title[type][4] << left
	<< std::setw(20) << title[type][5] << left << std::setw(10) << title[type][6] << std::endl;
    std::cout << guide[4] << std::endl;         

    for (auto i = ID_list.begin(); i != ID_list.end(); i++)
        if (i->second == type) std::cout << m[std::to_string(i->first)] << std::endl;

    std::cout << std::endl;
}

void Show_Media()
{
    if (ID_list.size())
    {
        std::cout << "以下是媒体库内所有媒体的信息：" << std::endl << std::endl;
        if (Disc_id_list.size()) Show_Each_Type(Disc_id_list, 1);
        if (Book_id_list.size()) Show_Each_Type(Book_id_list, 2);
        if (Drawing_id_list.size()) Show_Each_Type(Drawing_id_list, 3);
    }
    else std::cout << "[                    当前媒体库为空！                  ]" << std::endl << std::endl;
}

//-----------删除信息-----------//

template <typename Media>
void Delete_Each_Media(Media& m)
{
    Name = m[Id].title();
    m.erase(Id);
}

void Delete_Media()
{
    if (ID_list.size())
    {
        while (true)
        {
            std::cout << "请输入你想删除的媒体编号：";
            std::cin.sync();
            std::getline(std::cin, Id);

            Id.erase(0, Id.find_first_not_of(' '));

            if (!Judge_StoI(Id) || Id == "") 
                std::cout << std::endl << "[                  请输入合法的编号！                  ]" << std::endl << std::endl;
            else break;
        }

        if (!ID_list[stoi(Id)]) 
        {
            ID_list.erase(stoi(Id));
            std::cout << std::endl << "[                    该编号不存在！                    ]" << std::endl << std::endl;
        }
        else 
        {
            type = ID_list[stoi(Id)];

            if (type == 1) Delete_Each_Media(Disc_id_list);
            if (type == 2) Delete_Each_Media(Book_id_list);
            if (type == 3) Delete_Each_Media(Drawing_id_list);

            ID_list.erase(stoi(Id));
            for (auto i = Name_to_ID[Name].begin(); i != Name_to_ID[Name].end(); i++)
                if (*i == Id)
                {
                    Name_to_ID[Name].erase(i);
                    break;
                }

            std::cout << std::endl << "[                      删除成功！                      ]" << std::endl << std::endl;
            ifsave = false;
        }
    }
    else std::cout << "[                    当前媒体库为空！                  ]" << std::endl << std::endl;
}

//-----------统计信息-----------//

void Count_Media()
{
    std::cout << "当前媒体库中媒体数为：" << ID_list.size() << std::endl;
    std::cout << "当前媒体库中视频光盘类媒体数为：" << Disc_id_list.size() << std::endl;
    std::cout << "当前媒体库中书籍类媒体数为：" << Book_id_list.size() << std::endl;
    std::cout << "当前媒体库中图画类媒体数为：" << Drawing_id_list.size() << std::endl << std::endl;
}

//-----------保存信息-----------//

template <typename Media>
void writeMapToFile(Media m, const std::string& filename, int type, int mode)
{
    std::ofstream outFile(filename);

    if (outFile.is_open())
	{
        for (auto i = ID_list.begin(); i != ID_list.end(); i++)
            if (i->second == type) outFile << m[std::to_string(i->first)] << std::endl;

        outFile.close();
        if (mode) std::cout << "[                      保存成功！                      ]" << std::endl << std::endl;
    } 
    else std::cout << "[           未能成功打开文件，请检查相关原因           ]" << std::endl << std::endl;
}

void Save_Media()
{
    std::cout << "开始保存视频光盘类媒体信息..." << std::endl << std::endl;
	writeMapToFile(Disc_id_list, "data/Disc.txt", 1, 1);
    std::cout << "开始保存书籍类媒体信息..." << std::endl << std::endl;
	writeMapToFile(Book_id_list, "data/Book.txt", 2, 1);
    std::cout << "开始保存图画类媒体信息..." << std::endl << std::endl;
	writeMapToFile(Drawing_id_list, "data/Drawing.txt", 3, 1);
}

//-----------读取信息-----------//

void readLinesAndSplit(const std::string& filename, int type)
{
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;

        while (std::getline(inFile, line)) {
        	if(!line.size())continue;
            std::istringstream iss(line);
            std::vector<std::string> tokens;

            // 使用空格作为分隔符将每行数据存入数组
            std::string token;
            iss >> std::ws;
            while (iss >> token) tokens.push_back(token);

            if (type == 1) Add_Each_Media(Disc_id_list, tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6]);
            if (type == 2) Add_Each_Media(Book_id_list, tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], stoi(tokens[6]));
            if (type == 3) Add_Each_Media(Drawing_id_list, tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], stod(tokens[5]), stod(tokens[6]));

            ID_list[stoi(tokens[0])] = type;
    		Name_to_ID[tokens[1]].push_back(tokens[0]);
        }

        inFile.close();
        ifsave = false;
        std::cout << "[                      读取成功！                      ]" << std::endl << std::endl;
    } 
    else std::cout << "[           未能成功打开文件，请检查相关原因           ]" << std::endl << std::endl;
}

void Read_Media()
{
    Disc_id_list.clear();
    Book_id_list.clear();
    Drawing_id_list.clear();
    ID_list.clear();
    Name_to_ID.clear();

    std::cout << "开始读入视频光盘类媒体信息..." << std::endl << std::endl;
	readLinesAndSplit("data/Disc.txt", 1);
    writeMapToFile(Disc_id_list, "data/backup/Disc.txt", 1, 0);
    std::cout << "开始读入书籍类媒体信息..." << std::endl << std::endl;
	readLinesAndSplit("data/Book.txt", 2);
    writeMapToFile(Book_id_list, "data/backup/Book.txt", 2, 0);
    std::cout << "开始读入图画类媒体信息..." << std::endl << std::endl;
	readLinesAndSplit("data/Drawing.txt", 3);
    writeMapToFile(Drawing_id_list, "data/backup/Drawing.txt", 3, 0);
}