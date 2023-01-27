/*#include<stdio.h>
#include<math.h>
int main(){
    int n,x,p,A,i,q=0,p2;
    int isprime=1;
    scanf("%d",&n);
    while(n--){
        isprime=1;
        q=0;
        scanf("%d",&x);
        A=x;
        while(x!=0){
            q=q*10+x%10;
            x/=10;
        }
        p=sqrt(1.0*A);
        p2=sqrt(1.0*q);
        for(i=2;i<=p;i++){
            if(A%i==0){
                isprime=0;
                break;
            }
        }
        for(i=2;i<=p2;i++){
            if(q%i==0){
                isprime=0;
                break;
            }
        }
        printf("%d\n",isprime);
    }
}*/

#include<stdio.h>
#include<math.h>
int prime(unsigned int);
int main()
{
	unsigned int n, m;
	scanf("%u",&n);
	if(prime(n) != 0)
	    m =rev(n);
	else
	{
	    printf("输入的数%u不是素数\n",n);
	    return 0;
	}
	if(prime(m) !=0)
	    printf("%u是绝对素数！\n",n);
	else
	    print("%u不是绝对素数！\n",n);
	return 0;
}
//求绝对素数的定义
int prime(unsigned int x)
{
    int i, k;
    k = sqrt(x);
    for(i = 2; i <= k; i++)
    {
        if(x % i == 0)
            return 0;
        else if(i > k)
            return 0;
    }
}
//求反位数的函数定义
unsigned int rev(unsigned int y)
{
    unsigned int z = 0;
    while(y != 0)
    {
        z = z * 10 + y % 10;
        y = y / 10;
    }
    return 0;
} 