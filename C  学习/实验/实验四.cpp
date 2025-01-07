#include <iostream>

using namespace std;

class intSet
{
    public:
        intSet ();
        intSet (int a[], int size);
        void Empty ();     //清空集合
        bool IsEmpty ();   //判断集合是否为空
        bool IsMemberOf (int a);   //判断某个整数是否在该集合内
        bool Add (int a);   //向集合中增加一个元素
        bool Sub (int a);    //从集合中删除一个元素
        bool IsEqual (intSet &set);   //判断两个集合是否相等
        intSet Intersction (intSet &set);   //求两个集合的交集
        intSet Merge (intSet &set);    //求两个集合的并集
        void Copy (intSet &set);     //完成集合的复制
        void Print ();
    private:
        int element[100];
        int EndPosition;   //指示集合的最后一个元素位置
};

intSet::intSet ()
{
    EndPosition = -1;
}

intSet::intSet (int a[], int size)
{
    for (int i = 0; i < size; i++) element[i] = a[i];
    EndPosition = size - 1;
}

void intSet::Empty ()
{
    for (int i = 0; i <= EndPosition; i++) element[i] = 0;
    EndPosition = -1;
}

bool intSet::IsEmpty ()
{
    return EndPosition == -1;
}

bool intSet::IsMemberOf (int a)
{
    for (int i = 0; i <= EndPosition; i++)
        if (element[i] == a) return true;
    
    return false;
}

bool intSet::Add (int a)
{
    for (int i = 0; i <= EndPosition; i++) if (element[i] == a) return false;

    EndPosition ++;
    element[EndPosition] = a;
    return true;
}

bool intSet::Sub (int a)
{
    for (int i = 0; i <= EndPosition; i++)
        if (element[i] == a) 
        {
            for (int j = i + 1; j <= EndPosition; j++) element[j - 1] = element[j];
            EndPosition --;

            return true;
        }
    
    return false;
}

bool intSet::IsEqual (intSet &set)
{
    if (EndPosition != set.EndPosition) return false;

    for (int i = 0; i <= EndPosition; i++)
        if (element[i] != set.element[i]) return false;
    
    return true;
}

intSet intSet::Intersction (intSet &set)
{
    intSet k;
    int cnt[100] = {0};

    for (int i = 0; i <= EndPosition; i++) cnt[element[i]]++;

    for (int i = 0; i <= set.EndPosition; i++) 
        if (++ cnt[set.element[i]] == 2) k.Add(set.element[i]);
        
    return k;
}

intSet intSet::Merge (intSet &set)
{
    intSet k;

    for (int i = 0; i <= EndPosition; i++) k.Add(element[i]);

    for (int i = 0; i <= set.EndPosition; i++)
        if (!k.IsMemberOf(set.element[i])) k.Add(set.element[i]);

    return k;
}

void intSet::Copy (intSet &set)
{
    EndPosition = set.EndPosition;
    for (int i = 0; i <= EndPosition; i++) element[i] = set.element[i];
}

void intSet::Print ()
{
    for (int i = 0; i <= EndPosition; i++) cout << element[i] << ' ';
    cout << endl;
}

int main ()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b[4] = {1, 3, 7, 11};
    int num;

    intSet set1(b, 4);
    intSet set2(a, 10);
    intSet k;

    cout << "set1: ";
    set1.Print();
    cout << "set2: ";
    set2.Print();

    cout << "Is set1 empty: " << set1.IsEmpty() << endl;
    cout << "Is set2 empty: " << set2.IsEmpty() << endl;

    cout << endl << "Please type one number for checking: ";
    cin >> num;
    cout << "Is " << num << " in set1: " << set1.IsMemberOf(num) << endl;
    cout << "Is " << num << " in set2: " << set2.IsMemberOf(num) << endl;

    cout << endl << "Please type one number for adding(set2): ";
    cin >> num;
    if (set2.Add(num)) cout << "After adding " << num << ", set2: ", set2.Print();
    else cout << num << " is already in set2." << endl;

    cout << endl << "Please type one number for subing(set2): ";
    cin >> num;
    if (set2.Sub(num)) 
    {
        cout << "After subing " << num << ", set2: ";
        set2.Print();
    }
    else cout << num << " is not a member of the set2." << endl;

    cout << endl << "Is set1 equal to set2: " << set1.IsEqual(set2) << endl;

    k = set1.Intersction(set2);
    cout << endl << "Intersction for set1 and set2: ";
    k.Print();

    k = set1.Merge(set2);
    cout << "Merge for set1 and set2: ";
    k.Print();

    set1.Copy(set2);
    cout << endl << "After copying set2, set1: ";
    set1.Print();

    set1.Empty();
    cout << endl << "Is set1 empty after deleting: " << set1.IsEmpty() << endl;

    return 0;
}