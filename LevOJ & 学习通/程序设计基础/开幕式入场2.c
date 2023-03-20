#include <stdio.h>
#include <string.h>
char *exchange(char *a,char *b);
int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        getchar();     //从缓冲区读入输入完n后的回车
        int num[n], Temp, CHN;       //num[n]为每组开头的序号，Temp作为中间量便于交换序号
        char a[n][50], temp[50];     //a[n][50]存储国家名外加后面的一个括号，temp[50]作为中间数组便于组间互换顺序
        int i, j;

        //读入每组
        for(i=0; i<n; i++){
            scanf("%d", &num[i]);
            getchar();      //从缓冲区读入序号后的空格
            gets(a[i]);     //读入“国家名称 参加人数 所属大洲”的字符串
            if(a[i][0]=='C'&&a[i][1]=='h'&&a[i][2]=='i'&&a[i][3]=='n'&&a[i][4]=='a'&&a[i][5]==' '){
                CHN = i;
            }
        }

        //将China一组所有元素放在最后
        strcpy(temp , a[CHN]);
        strcpy(a[CHN] , a[n-1]);
        strcpy(a[n-1] , temp);
        Temp = num[CHN];    
        num[CHN] = num[n-1];
        num[n-1] = Temp;

        //对前n-1组进行排序
        memset(temp,0,sizeof(temp));   //初始化temp[]数组，便于拷贝数组
        for(i=0; i<n-2; i++){
            for(j=0; j<n-2-i; j++){
                if( strcmp(a[j] , a[j+1])>0 ){
                    strcpy(temp , a[j]);       //
                    strcpy(a[j] , a[j+1]);     //
                    strcpy(a[j+1] , temp);     //交换字符数组
                    Temp = num[j];             //
                    num[j] = num[j+1];         //   
                    num[j+1] = Temp;           //
                }
            }
        }
        for(i=0; i<n; i++){
            printf("%d ", num[i]);    //按最终顺序输出结果
            puts(a[i]);
        }
    }
    return 0;
}
