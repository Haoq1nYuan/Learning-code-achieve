#include <iostream>
#include "./class/gen.h"
#include "./class/book.h"
#include "./class/disc.h"
#include "./class/drawing.h"
#include "operations.h"

int main ()
{
    while (true)  
    {
        Menu();
        ifbreak = false;

        while (true)
        {
            std::cout << "请选择对应功能：";    
            std::cin.sync();
            std::getline(std::cin, operation);
            std::cout << std::endl;

            operation.erase(0, operation.find_first_not_of(' '));

            if (!Judge_StoI(operation) || operation == "") 
                std::cout << "[                请输入合法的类别索引！                ]" << std::endl << std::endl;
            else if (stoi(operation) > 8 || stoi(operation) < 0) 
                std::cout << "[                请输入合法的类别索引！                ]" << std::endl << std::endl;
            else break;
        }

        switch (stoi(operation))
        {
            case 0:
                std::cout << "正在退出中...请稍后" << std::endl;
                ifbreak = true;
                break;
            case 1:
                Add_Media();
                break;
            case 2:
                Update_Media();
                break;
            case 3:
                Search_Media();
                break;
            case 4:
                Show_Media();
                break;
            case 5:
                Delete_Media();
                break;
            case 6:
                Count_Media();
                break;
            case 7:
               	if (ifsave)
				{
					std::cout << "[      已经保存过一次，再次保存会导致部分数据重复!     ]" << std::endl << std::endl;
					break;
				}
                else
				{
					Save_Media();
					ifsave = true;
					break;
				}    
                break;
            case 8:
                Read_Media();
                break;
        }

        if (ifbreak)
            if (!ifsave)
            {
                std::cout << "你做出的操作还未保存, 请确认是否退出? (是: Y; 不是: N)" << std::endl << std::endl;
                char a;
                bool ifexit = false;

                while(true)
                {
                    std::cin >> a;
                    if (a == 'Y')
                    {   
                        ifexit = true;
                        break;
                    }
                    else if (a == 'N')
                    {
                        std::cout << std::endl;
                        break;
                    }
                    else std::cout << std::endl << "[                    请输入'Y'或'N'                    ]" << std::endl << std::endl;
                }

                if (ifexit)
                {
                    std::cout << std::endl << "[                       退出成功!                      ]" << std::endl << std::endl;
                    break;
                }
            }
            else
            {
                std::cout << std::endl << "[                       退出成功!                      ]" << std::endl << std::endl;
                break;
            }
    }

    return 0;
}