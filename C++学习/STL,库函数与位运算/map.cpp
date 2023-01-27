#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main ()
{
    map<int, vector<int>> a, b;
    //a.insert({1, {}});

    //a[0] = vector<int>({1});
    a.insert(pair<int, vector<int>>(1, {1}));
    //a.insert({0, {1}});

    cout << a[1].size() << endl;

    a[0] = vector<int>({1, 2, 3});

    cout << a[0][1] << endl;  

    cout << a.begin()->second[1] << endl;

    cout << a.size() << endl;

    cout << a.find(0)->second[0] << endl;

    return 0;
}