/*
-------题目-------
小明在练习绝世武功， n 个练功桩排成一排，一开始每个桩的损伤为 0。
接下来小明会练习 m 种绝世武功，每种武功都会对 [l,r] 区间分别造成 [s,e] 的伤害。
这个伤害是一个等差序列。例如 l=1,r=4,s=2,e=8,则会对 1?4 号练功桩造成2，4，6，8 点损伤。
小明想让你统计一下所有练功桩的损伤的和。
-------输入-------
第一行输入 n,m 代表练功桩的数量和绝世武功的种类数。
接下来 m 行输入 4 个整数 l,r,s,e
1 ≤ n ≤ 10^7
1 ≤ m ≤ 3×10^5
1 ≤ l, r ≤ n
-------输出-------
输出一个整数代表所有练功桩的损伤和， 题目保证所有输入输出都在 [0,9×1018]内.
*/

/*
二阶差分就相当于一阶差分+等差数列(公差为d，首项为s，末项为e)
需要构造原数组a[i]，一阶差分数组b[i]=a[i]-a[i-1]，二阶差分数组c[i]=b[i]-b[i-1]
对于数组b，通过计算得出，b[l]+=s，b[i]+=d ( l < i < r+1 )，b[r+1]-=e.
对于数组c，通过计算得出，c[l]+=s，c[l+1]+=d-s，c[r+1]-=d+e，c[r+2]+=e.
*/

#include<stdio.h>
#define N (int)1e+7

long n, m, l, r, i, j;
long long s, e, d, sum; 
long long hurt[N], valueone[N], valuetwo[N];

int main ( int argc, char *argv[] )
{
    scanf( "%ld %ld", &n, &m );
    for ( i = 1; i <= m; i++ ) {
        scanf( "%ld %ld %lld %lld", &l, &r, &s, &e );
        d = (e-s) / (r-l);
        valuetwo[l] += s;
        valuetwo[l+1] += d-s;
        valuetwo[r+1] -= d+e;
        valuetwo[r+2] += e;
    }

    for ( i = 1; i <= n; i++ ) {
        valueone[i] = valuetwo[i] + valueone[i-1];
        hurt[i] = valueone[i] + hurt[i-1];
        sum += hurt[i];
    }

    printf( "%lld\n", sum );

    return 0;
}