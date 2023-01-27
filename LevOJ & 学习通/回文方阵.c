#include<stdio.h>

#define N 10
int a[N][N];

int main ( int argc, char * argv[] ) 
{
	int n,t;
	
	while ( scanf( "%d",&n )!=EOF ) {
		int i, j, num = 0, count = 1;
		if ( n == 1 ) {
			a[0][0] = 1;
		} else {
			while ( count <= n*n ) {
				for ( i = num; i < n-1; i++ ) {
					a[i][n-1-num] = count++;     //尾列遍历
				}

				for ( j = n-1-num; j > 0; j-- ) {
					a[n-1-num][j] = count++;     //尾行遍历
				}

				for ( i = n-1-num; i > 0 ; i-- ) {
					a[i][num] = count++;         //头列遍历
				}
				 
				for ( j = num; j < n-num-1; j++) {
					a[num][j] = count++;         //头行遍历
				}
				num++;
			}
		}
		if ( n%2 ) {
			a[n/2][n/2] = count;
		}
		for ( i = 0; i < n; i++ ) {
			for ( j = 0; j < n; j++ ) {
				printf( "%d\t",a[i][j] );
			}
			printf( "\n" );
		}
		printf( "\n" );
	}

	return 0;
}
