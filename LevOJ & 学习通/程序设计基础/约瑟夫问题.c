#include <stdio.h>
#include <string.h>

int a[50], b[50];

int main()
{
    int m, n;

    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int i, x = n, j = 0, count = 0;
        for(i = 1; i <= n; i++) a[i] = i;

        while(x)
        {
            for(i = 1; i <= n; i++)
            {
                if(a[i]) count++;        

                if(count == m)
                {
                    b[j] = a[i];      
                    a[i] = 0;         
                    count = 0;        
                    x--;            
                    j++;
                }
            }
        }

        for(i = 0; i < n; i++) printf("%d ", b[i]);
        printf("\n");
    }
    
    return 0;
}
