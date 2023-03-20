#include<stdio.h>
#include<stdlib.h>

#define N 10

int main()
{
	long long a[4][N][N],b[N][N],sum[N][N];

	int n,num,round,order; 

	int i,j,k;

	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
		    sum[i][j]=0;

		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
		    scanf("%lld",&a[0][i][j]);

		scanf("%d",&num);

		for(k=1;k<4;k++)
		  for(i=0;i<n;i++)
			for(j=0;j<n;j++)
		      a[k][i][j]=a[k-1][n-j-1][i];

		round=num/4;

		order=(num+1)%4;

		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
			b[i][j]=a[0][i][j]+a[1][i][j]+a[2][i][j]+a[3][i][j];

		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
			sum[i][j]=b[i][j]*round;

		for(k=0;k<order;k++)
		  for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			  sum[i][j]+=a[k][i][j];
              
		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
			if(j==n-1)printf("%lld\n",sum[i][j]);
			else printf("%lld ",sum[i][j]);
	}
	return 0;
}
