// 约瑟夫问题
#include <stdio.h>
#include <string.h>

const int N = 105;

int main ()
{
    int n, m, tem[N];   

    while (scanf("%d %d", &n, &m) != EOF)
    {
        memset(tem, 0, sizeof tem);

        int count = 0, i = -1, k = 0;
        int flag = 0;

        while (!flag)
        {
            i = (i + 1) % n;

            if (tem[i]) continue;

            if (++count == m)
            {
                tem[i] = 1;
                k++;
                printf("%d ", i + 1);
                count = 0;
            }

            if (k == n) flag = 1;
        }

        puts("");
    }

    return 0;
}

// 二进制转16进制
// #include <stdio.h>
// #include <math.h>
// #include <string.h>

// const int N = 105;

// char hash[18] = "0123456789ABCDEF";

// int main ()
// {
//     int b, idx = 0;
//     char h[105];

//     while (scanf("%d", &b), b)
//     {
//         int d = 0, k = 0;
//         while (b)
//         {
//             d += b % 10 * pow(2, k);   // pow(a, k)
//             b /= 10;
//             k ++;
//         }

//         idx = 0;

//         while (d / 16)
//         {
//             h[idx++] = hash[d % 16];
//             d /= 16;
//         }

//         if (d) h[idx++] = hash[d];

//         for (int i = idx - 1; i >= 0; i--) printf("%c", h[i]);
//         puts("");
//     }

//     return 0;
// }

// 校门外的树
// #include <stdio.h>
// #include <string.h>

// const int N = 10005;

// int main ()
// {
//     int L, M;
//     int a[N];  // a[i] = 0: 有树
     
//     while(scanf("%d %d", &L, &M) != EOF)
//     {
//         int b, c, i, num;

//         while (M--) 
//         {
//             scanf("%d %d", &b, &c);
//             for (i = b; i <= c; i++)
//                 if (a[i] == 0) a[i] = 1;
//         }

//         num = 0;
//         for(i = 0; i < L + 1; i++)
//             if(a[i] == 0) num++;

//         printf("%d\n", num);
//     }

//     return 0;
// }

// 运动会开幕式入场
// #include <stdio.h>
// #include <string.h>

// int main ()
// {
//     int n;

//     while(scanf("%d", &n) != EOF)
//     {
//         getchar();               // 读入缓冲区中的回车符，以免影响字符串的读入
//         char a[n][50], BOX[50];  // a存放国家名字符串，BOX为临时字符串，用以交换a中字符串的顺序
//         memset(a, 0, sizeof(a));

//         int i, j, box;

//         for(i = 0; i < n; i++)
//         {
//             gets(a[i]);
//             if(strcmp(a[i], "China") == 0) box = i;
//         }
        
//         // 将 China 换至最后
//         strcpy(BOX, a[box]);          // strcpy(a, b);
//         strcpy(a[box], a[n - 1]);     // strcmp(a, b);
//         strcpy(a[n - 1], BOX);

//         memset(BOX, 0, sizeof(BOX)); 

//         // 按照字典序排列
//         for(i = 0; i < n - 2; i++)  // 循环含义，每次将字典序最大的字符串移至最后
//             for(j = 0; j < n - 2 - i; j++)
//                 if(strcmp(a[j], a[j + 1]) > 0)  // a[j] 的字典序大于 a[j + 1]
//                 {
//                     strcpy(BOX, a[j]);
//                     strcpy(a[j], a[j + 1]);
//                     strcpy(a[j + 1], BOX);
//                     memset(BOX, 0, sizeof(BOX));
//                 }

//         for(i = 0; i < n; i++) puts(a[i]);
//     }

//     return 0;
// }

// 大整数加法
// #include <stdio.h>

// const int N = 205;

// int idx_a = 0, idx_b = 0, idx_s = 0;

// void Get_Sum (int *a, int len_a, int *b, int len_b, int *s)
// {
//     int i = len_a - 1, j = len_b - 1, tem = 0;
//     while (i >= 0 || j >= 0)      
//     {
//         int sum = tem;
//         if (i >= 0) sum += a[i];
//         if (j >= 0) sum += b[j];
//         s[idx_s++] = sum % 10;
//         tem = sum / 10;
//         i--, j--;
//     }

//     if (tem) s[idx_s++] = tem;
// }

// int main ()
// {
//     int n;
//     while (scanf("%d", &n) != EOF)
//     {
//         while (n--)
//         {
//             char a[N], b[N];
//             idx_a = 0, idx_b = 0, idx_s = 0;
//             int a_num[N], b_num[N], sum[N];

//             scanf("%s", a);   // 123
//             scanf("%s", b);   // 456
//                                                                 // 0 1 2
//             while (a[idx_a]) a_num[idx_a++] = a[idx_a] - '0';   // 7 2 3
//             while (b[idx_b]) b_num[idx_b++] = b[idx_b] - '0';   // 4 5 6

//             if (idx_a < idx_b) Get_Sum(b_num, idx_b, a_num, idx_a, sum);
//             else Get_Sum(a_num, idx_a, b_num, idx_b, sum);

//             for (int i = idx_s - 1; i >= 0; i--) printf("%d", sum[i]);
//             puts("");
//         }
//     }

//     return 0;
// }

// 大整数减法
// #include <stdio.h>

// const int N = 205;

// int idx_a = 0, idx_b = 0, idx_m = 0;  

// void Get_Minor (int *a, int len_a, int *b, int len_b, int *m)
// {
//     int i = len_a - 1, j = len_b - 1, tem = 0;
//     while (i >= 0 && j >= 0)
//     {
//         int minor = a[i] + tem - b[j];

//         if (minor < 0) 
//         {
//             tem = -1; 
//             minor += 10;
//         }
//         else tem = 0;

//         m[idx_m++] = minor;
//         i--, j--;
//     }

//     while (i >= 0)
//     {
//         m[idx_m++] = a[i] + tem;
//         tem = 0;
//         i--;
//     }
// }

// int main ()
// {
//     char a[N], b[N];

//     while (scanf("%s\n%s", a, b) != EOF)
//     {
//         idx_a = 0, idx_b = 0, idx_m = 0;
//         int a_num[N], b_num[N], minor[N];

//         while (a[idx_a]) a_num[idx_a++] = a[idx_a] - '0';
//         while (b[idx_b]) b_num[idx_b++] = b[idx_b] - '0';

//         Get_Minor(a_num, idx_a, b_num, idx_b, minor);

//         for (int i = idx_m - 1; i >= 0; i--) printf("%d", minor[i]);
//         puts("");
//     }

//     return 0;
// }