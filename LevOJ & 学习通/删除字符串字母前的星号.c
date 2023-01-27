//删除前导*号
#include<stdio.h>
#define N 1000
int main(){
    int i,k;
    char a[N];
    gets(a);
    i=0;
    while(a[i]=='*'){
        i++;
    }
    k=i;
    for(i=0;a[k]!=0;i++,k++){
        a[i]=a[k];
    }
    a[i]='\0';
    printf("%s\n",a);
    return 0;
}

//删除中间*号
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fun ( char * ) ;

int main ()
{
	char s[81];
	gets(s);
	fun(s);
	puts(s);
	system( "pause" );
	return 0;
}

void fun ( char *s ) 
{
	int low=0,high=0;
	int i=0;
	while ( s[i]=='*' ) {
		low++;
		i++;
	}
	i=0;
	while ( s[strlen(s)-i-1]=='*') {
		high++;
		i++;
	}
	int j = low;
	for ( i=low; i<strlen(s)-high; i++ ) {
		if ( s[i]!='*' ) {
			s[j++] = s[i];
		}
	}
	while ( high>0 ) {
		s[j++] = '*';
		high--;
	}
	s[j] = '\0';
}