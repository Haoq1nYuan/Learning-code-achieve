#include <stdio.h>

int main ()
{
    int flag = 1;
    while (flag)
    {
        char tem[25];  // 读入的字符串存储在tem中
        int idx = 0;

        gets(tem);

        while (tem[idx]) idx++;
        if (tem[idx - 1] == 'E') flag = 0;

        /*
        其他代码
        */
    }

    return 0;
}