#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> Available = {3, 3, 2};
vector<vector<int>> Max = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
vector<vector<int>> Allocation = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
vector<vector<int>> Need = {{7, 4, 3}, {1, 2, 2}, {6, 0, 0}, {0, 1, 1}, {4, 3, 1}};

vector<int> banker_safe_check (vector<int> Available, vector<vector<int>> Max, 
            vector<vector<int>> Allocation, vector<vector<int>> Need) 
{
    vector<bool> Finish(5, false);
    vector<int> SafeOrder;
    vector<int> Work = Available;  // 临时变量，存储Available

    while (SafeOrder.size() < 5) 
    {
        bool found = false;
        for (int i = 0; i < 5; ++i) 
        {
            if (!Finish[i]) 
            {
                bool canFinish = true;
                for (int j = 0; j < 3; ++j) 
                {
                    if (Need[i][j] > Work[j]) 
                    {
                        canFinish = false;
                        break;
                    }
                }

                if (canFinish) 
                {
                    for (int j = 0; j < 3; ++j) 
                    {
                        Work[j] += Allocation[i][j];
                    }
                    Finish[i] = true;
                    SafeOrder.push_back(i);
                    found = true;
                }
            }
        }

        if (!found) 
        {
            return {};  
        }
    }
    return SafeOrder;
}

bool banker_resource_request (vector<int> &Available, vector<vector<int>> &Allocation, 
            vector<vector<int>> &Need, vector<int> Request, int num) 
{
    // 判断请求资源是否合理
    for (int i = 0; i < 3; i++) 
    {
        if (Request[i] > Need[num][i]) 
        {
            cout << "需求过大，无法满足请等待！\n";
            return false;
        }
    }

    // 判断资源是否足够
    for (int i = 0; i < 3; i++) 
    {
        if (Request[i] > Available[i]) 
        {
            cout << "资源不足，请等待！\n";
            return false;
        }
    }

    // 尝试分配资源
    for (int i = 0; i < 3; i++) 
    {
        Available[i] -= Request[i];
        Allocation[num][i] += Request[i];
        Need[num][i] -= Request[i];
    }

    // 检查是否安全
    vector<int> SafeOrder = banker_safe_check(Available, Max, Allocation, Need);
    if (SafeOrder.empty()) 
    {
        // 恢复资源分配
        for (int i = 0; i < 3; i++) 
        {
            Available[i] += Request[i];
            Allocation[num][i] -= Request[i];
            Need[num][i] += Request[i];
        }
        cout << "请求后系统不安全，撤销操作。\n";
        return false;
    } 
    else 
    {
        cout << "请求后系统安全，安全序列为：";
        for (int i : SafeOrder) 
        {
            cout << i << " ";
        }
        cout << "\n";
        return true;
    }
}

int main ()
{
    // 1) 检测当前进程集合是否存在安全序列
    cout << "1) 检测当前进程集合是否存在安全序列：" << endl;
    vector<int> safe_sequence = banker_safe_check(Available, Max, Allocation, Need);
    if (!safe_sequence.empty()) {
        cout << "当前进程存在安全序列：";
        for (int i : safe_sequence) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cout << "当前进程不存在安全序列。\n";
    }

    // 2) 进程 1 发起资源请求 {1, 0, 2}
    cout << "\n2) 进程 1 发起资源请求 {1, 0, 2}: " << endl;
    vector<int> Request1 = {1, 0, 2};
    banker_resource_request(Available, Allocation, Need, Request1, 1);

    // 3) 进程 4 发起资源请求 {3, 3, 0}
    cout << "\n3) 撤销2), 进程 4 发起资源请求 {3, 3, 0}: " << endl;
    for (int i = 0; i < 3; i++) 
    {
        Available[i] += Request1[i];
        Allocation[1][i] -= Request1[i];
        Need[1][i] += Request1[i];
    }
    vector<int> Request2 = {3, 3, 0};
    banker_resource_request(Available, Allocation, Need, Request2, 4);

    // 4) 进程 0 发起资源请求 {0, 2, 0}
    cout << "\n4) 进程 0 发起资源请求 {0, 2, 0}: " << endl;
    vector<int> Request3 = {0, 2, 0};
    banker_resource_request(Available, Allocation, Need, Request3, 0);

    // 5) 在 4) 执行后的基础上，进程 3 发起资源请求 {0, 1, 0}
    cout << "\n5) 在4)执行后的基础上，进程 3 发起资源请求 {0, 1, 0}: " << endl;
    vector<int> Request4 = {0, 1, 0};
    banker_resource_request(Available, Allocation, Need, Request4, 3);

    return 0;
}

