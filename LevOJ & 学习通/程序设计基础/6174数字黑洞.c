#include<stdio.h>

void insert( int a[], int num );

int main () 
{
    int n;
    while ( scanf("%d",&n)!=EOF ) {
        int a[4],result,max,min,count,s;
        count = 0;
        result = 0;
        s = n;
        while ( result!=6174&&s!=6174 ) {
            a[0] = s%10; //个位
            a[1] = s%100/10;  //十位
            a[3] = s/1000;  //千位
            a[2] = s/100%10;  //百位
            insert(a,4);
            max = 1000*a[3] + 100*a[2] + 10*a[1] + a[0];
            min = 1000*a[0] + 100*a[1] + 10*a[2] + a[3];
            result = max - min;
            count++;
            s = result;
        }  
        printf( "%d\n",count );
    }
    return 0;
}

void insert ( int a[], int num) 
{
    int i,j,box;
    for ( i=0; i<num; i++ ) {
        for ( j=i+1; j<num; j++ ) {
            if ( a[i]>a[j] ) {
                box = a[i];
                a[i] = a[j];
                a[j] = box;
            }
        }
    }
}