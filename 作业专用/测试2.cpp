#include <stdio.h>

char k[15], e[5];
char a[140010];

int main ()
{
    while (scanf("%s", k), strcmp(k, "ENDOFINPUT"))
    {
        getchar();
        gets(a);
        gets(e);

        for (int i = 0; a[i] != '\0'; i++)
            if (a[i] <= 'Z' && a[i] >= 'A')
                a[i] = (char)((a[i] - 'A' + 21) % 26) + 'A';

        puts(a);
    }

    return 0;
}