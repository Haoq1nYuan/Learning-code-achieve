// 主函数
#include <string>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <sstream>

#define SIZE 100

using namespace std;

#include "./Class/Sight.h"
#include "./Functions/Add_path.h"
#include "./Functions/Add_sight.h"
#include "./Functions/Delete_sight.h"
#include "./Functions/Update_sight.h"
#include "./Functions/Search_sight.h"
#include "./Functions/Init_path.h"
#include "./Functions/Update_path.h"
#include "./Functions/Delete_path.h"
#include "./Algorithms/Floyd.h"
#include "./Algorithms/Show_all_paths.h"
#include "./Algorithms/Multi_Floyd.h"

map<pos, Sight> Sights_pos;                 // 在坐标和景点信息之间建立索引
unordered_map<string, Sight> Sights_name;   // 在名称和景点信息之间建立索引
int Weight_for_cars[SIZE + 1][SIZE + 1];    // 存储节点 i 到 j 的机动车道路权
int Weight_for_people[SIZE + 1][SIZE + 1];  // 存储节点 i 到 j 的人行道路权

int main ()
{   
    // 初始化路权数组
    Init_path(Weight_for_cars, Weight_for_people);

    // 存景点
    Add_sight(Sights_pos, Sights_name);

    // // 改信息
    // Upgrade_sight(Sights_pos, Sights_name);  

    // // 查找景点
    // Search_sight(Sights_name);
    
    // 存路径
    Add_path(Weight_for_cars, Weight_for_people);

    // // 展示两点间所有路径
    // Show_all_paths(Sights_name, Weight_for_cars, Weight_for_people);

    // 多源最短路
    Floyd(Sights_name, Weight_for_cars, Weight_for_people);

    // // 删除路径
    // Delete_path(Sights_name, Weight_for_cars, Weight_for_people);

    // // 更新多源最短路
    // Floyd(Sights_name, Weight_for_cars, Weight_for_people);

    // // 删除景点 
    // Delete_sight(Sights_pos, Sights_name, Weight_for_cars, Weight_for_people);  

    // // 更新多源最短路
    // Floyd(Sights_name, Weight_for_cars, Weight_for_people);

    // // 更新路权
    // Update_path(Sights_name, Weight_for_cars, Weight_for_people);

    // // 更新多源最短路
    // Floyd(Sights_name, Weight_for_cars, Weight_for_people);

    // 求经过多节点的最短路
    Mutli_Floyd(Sights_name, Weight_for_cars, Weight_for_people);

    return 0;
}

/*
1 2 001 食堂 无 无
3 4 002 文德楼 无 无
5 6 003 明德楼 无 无
7 8 004 尚贤楼 无 无

1 2 1 机动车道
1 4 4 机动车道
1 3 1 机动车道
2 4 2 机动车道
3 4 1 机动车道
1 2 2 人行道
1 4 3 人行道
1 3 1 人行道
2 4 4 人行道
*/