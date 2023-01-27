#include <stdio.h>
#define N 10  //输出前十行
int main() {
    int arr[N][N];
    for (int i = 0;i < N;i++) {    
            arr[i][0] = 1;    // 首先给每行第一个和最后一个赋值1
            arr[i][i] = 1;
    }

    // 从第三行起，除了每行的1以外，其他数为上一行本列的数加上上一行前一列的数
    // 如 a[i][j] = a[i-1][j] + a[i-1][j-1];
    for (int i = 2;i < N;i++) {
        for (int j = 1;j <= i - 1;j++) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < i + 1;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
