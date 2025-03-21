#include <iostream>
#include <fstream>

using namespace std;

struct student 
{
    int no;
    char name[20];
    double score;
};

int main ()
{
    student stu1 = {1001, "小张", 99.7};
    student stu2 = {1002, "小芳", 45.6};
    student stu3 = {1003, "小王", 87.3};

    ofstream file;
    file.open("./test.dat", ios_base::binary);
    file.write((char *) &stu1, sizeof(stu1));
    file.write((char *) &stu2, sizeof(stu2));
    file.write((char *) &stu3, sizeof(stu3));

    file.close();

    ifstream File("./test.dat", ios_base::binary);
    student stu;
    for (int i = 1; i <= 3; i++)
    {
        File.read((char *) &stu, sizeof(stu));
        cout << "编号：" << stu.no << " 姓名：" << stu.name << " 分数：" << stu.score << endl;
    }

    File.close();

    fstream filee("./test.dat", ios_base::binary);
    filee.seekg(sizeof(stu));
    filee.write((char *) &stu3, sizeof(stu3));  // 如何删除信息
    filee.close();

    File.open("./test.dat", ios_base::binary);

    cout << "删除第二条信息后：" << endl;

    for (int i = 1; i <= 2; i++)
    {
        File.read((char *) &stu, sizeof(stu));
        cout << "编号：" << stu.no << " 姓名：" << stu.name << " 分数：" << stu.score << endl;
    }

    File.close();

    filee.open("./test.dat", ios_base::binary);

    int x;
    cout << "请输入你想查询的信息编号：";
    cin >> x;

    filee.seekg((x - 1) * sizeof(stu));  // 回复指针
    filee.read((char *) &stu, sizeof(stu));
    cout << "第" << x << "条信息为：" << endl;
    cout << "编号：" << stu.no << " 姓名：" << stu.name << " 分数：" << stu.score << endl;

    filee.close();

    return 0;
}