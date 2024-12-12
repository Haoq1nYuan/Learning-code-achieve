#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int parCode[7] = {16, 32, 64, 128, 256, 512, 1024};
int parInsideCode[8] = {1, 1, 2, 4, 8, 16, 32, 64};
int parInsideSart[8] = {0, 16, 32, 64, 128, 256, 512, 1024};
int flag, testNum;

void parGenerate (string &result, int testNum)
{
    int low = 0, high = 7;
    for (int i = 0; i < 3; i ++)
    {
        int mid = (low + high) / 2;
        if (testNum >= parCode[mid])
        {
            result = result + '1';
            low = mid + 1;
            flag = mid;
        }
        else 
        {
            result = result + '0';
            high = mid - 1;
            flag = mid - 1;
        }
    }
}

void parInsideGenerate (string &result, int testNum, int parStart,  int parSpace)
{
    int low = 0, high = 17, mid = 8;
    for (int i = 0; i < 4; i++)
    {
        int cost = parStart + parSpace * mid;
        if (cost > testNum) 
        {
            result = result + '0';
            high = mid;
            mid = (low + high) / 2;
        }
        else 
        {
            result = result + '1';
            low = mid;
            mid = (low + high) / 2;
        }
    }
}

int main () 
{
    while (1)
    {
        cout << "请输入编码的值：";
        cin >> testNum;
        
        string result; //字节用来存储编码出来的pcm码

        //判断极性码
        if (testNum < 0) result = result + '0';
        else result = result + '1';
        
        //去符号
        testNum = fabs(testNum);    

        //确定段落码
        parGenerate(result, testNum);               

        //量化间隔级数
        int parSeq = flag + 1;                   

        int parStart = parInsideSart[parSeq];    //段落起始电平
        int parSpace = parInsideCode[parSeq];    //量化间隔

        // 确定段内码
        parInsideGenerate(result, testNum, parStart, parSpace);

        cout << "编译出来的pcm码组: " << result << endl;
    }

    return 0;
}