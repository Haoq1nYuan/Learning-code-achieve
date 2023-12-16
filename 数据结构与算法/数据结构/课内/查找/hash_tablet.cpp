#include <iostream>

using namespace std;

typedef struct Elem
{
    int key;
    int compareTimes;
    int flag;
} Elem;

typedef struct HashList
{
    Elem *base;
    int length;
} HashList;

void CreateHashList (HashList &HL)
{
    int num[] = {23, 5, 17, 12, 26, 31, 13, 4, 6};

    HL.base = new Elem[13];
    HL.length = 9;

    for (int i = 0; i < 13; i++) 
    {
        HL.base[i].flag = 0;
        HL.base[i].compareTimes = 0;
    }

    for (int i = 0; i < 9; i++)
    {
        int cnt = 1;
        int key = num[i] % 13;
        while (HL.base[key].flag) 
        {
            key = (key + 1) % 13;
            cnt ++;
        }

        HL.base[key].key = num[i];
        HL.base[key].flag = 1;
        HL.base[key].compareTimes = cnt;
    }
}

void PrintHashList (HashList HL)
{
    for (int i = 0; i < 13; i++)
        if (HL.base[i].flag) cout << "HL.base[" << i << "].key: " << HL.base[i].key << endl;
}

void IndexHashList (HashList HL, int x)
{
    int key = x % 13;
    while (HL.base[key].flag && HL.base[key].key != x) key = (key + 1) % 13;

    if (HL.base[key].key == x) cout << "找到了！" << "元素" << x << "在哈希表中第" << key + 1 << "个位置(HL.base[" << key << "])。" << endl;
    else cout << "没找到。" << endl;
}

void DeleteIndex (HashList &HL, int idx)
{
    if (HL.base[idx - 1].flag) 
    {
        cout << "成功删除哈希表中第" << idx << "个位置上的元素(HL.base[" << idx - 1 << "].key): " << HL.base[idx - 1].key << endl;
        HL.base[idx - 1].flag = 0;
        HL.base[idx - 1].key = 0;
        HL.base[idx - 1].compareTimes = 0;
    }
    else cout << "该位置上还没有元素！" << endl;
}

void CalcuASL (HashList HL)
{
    double sum = 0;
    int count = 0;
    for (int i = 0; i < 13; i++)
        if (HL.base[i].flag) 
        {
            sum += HL.base[i].compareTimes;
            count ++;
        }

    cout << "哈希表的平均查找长度为：" << sum / count << endl;
}

void Menu ()
{
    cout << "===================================" << endl;
    cout << "           1.显示哈希表             " << endl;
    cout << "            2.查找元素              " << endl;
    cout << "            3.删除元素              " << endl;
    cout << "            4.计算ASL               " << endl;
    cout << "             5.退出                 " << endl;
    cout << "===================================" << endl;
}

int op, x, idx;

int main ()
{
    HashList HL;
    CreateHashList(HL);

    Menu();

    while (true)
    {
        cout << "请输入你想进行的操作：";
        cin >> op;
        cout << endl;

        if (op == 5) break;
        else if (op == 1) 
        {
            cout << "以下是哈希表的所有元素:" << endl;
            PrintHashList(HL);
        }
        else if (op == 2)
        {
            cout << "请输入你想查找的元素：" << endl;
            cin >> x;
            IndexHashList(HL, x);
        }
        else if (op == 3)
        {
            cout << "你想删除哈希表中哪个位置的元素？(从1开始)";
            cin >> idx;
            DeleteIndex(HL, idx);
        }
        else if (op == 4) CalcuASL(HL);
        else cout << "请输入[1, 5]内的整数！" << endl;

        cout << endl;
    }

    return 0;
}