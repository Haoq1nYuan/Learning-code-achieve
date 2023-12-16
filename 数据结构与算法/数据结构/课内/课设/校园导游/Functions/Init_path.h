// 初始化路径数组
void Init_path (int (*g1)[SIZE + 1], int (*g2)[SIZE + 1])
{
    for (int i = 1; i <= SIZE; i++)
        for (int j = 1; j <= SIZE; j++)
            if (i == j)
            {
                *(g1[i] + j) = 0;
                *(g2[i] + j) = 0;
            }
            else 
            {
                *(g1[i] + j) = 0x3f3f3f3f;
                *(g2[i] + j) = 0x3f3f3f3f;
            }
}