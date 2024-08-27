// #include <iostream>
// #include <cstring>

// using namespace std;

// void Get (char* res)
// {
//     *res++ = 'k';
//     *res++ = 'a';
//     *res++ = '\0';
// }

// int main ()
// {
//     char* tem = new char[100]{};
//     char* tem2 = new char[100]{};

//     // *tem2++ = '1';
//     // *tem2++ = ',';
    
//     Get(tem);

//     strcpy(tem2, tem);

//     // for (int i = 0; i < strlen(tem); i++) *tem2++ = *(tem + i);

//     // *tem2++ = '\0';
//     // if (strlen(tem)) tem2 -= strlen(tem) + 1;
//     // else tem2 -= 2 + 1;

//     delete[] tem;

//     cout << tem2 << endl;

//     tem2 = {};

//     cout << tem2 << endl;

//     return 0;
// }


#include <iostream>
#include <vector>

using namespace std;

class test 
{
    public:
        test();
        void* Run();
        int Get();
    private:
        vector<int> tem;
};

test::test() {}

void* test::Run()
{
    tem.clear();

    tem.emplace_back(2);

    return tem.data();
}

int test::Get()
{
    return tem.size();
}

int main ()
{
    test t;

    cout << t.Run() << endl;
    cout << t.Get() << endl;
    cout << t.Run() << endl;
    cout << t.Get() << endl;

    return 0;
}