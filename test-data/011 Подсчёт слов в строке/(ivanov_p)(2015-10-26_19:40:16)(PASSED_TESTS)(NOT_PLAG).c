#include <stdio.h>
#include<string.h>

char a[1000];
int w=1,m=1,i=0,c=0;
char wcount(char *a, int w)
{
        c=strlen(a);
	for(i=0;i<c;i++){
		if(a[i]==' '&&m==0)w++;
		if(a[i]==' ')m=1;
		else m=0; 
	}
	
	if(m==0&&w==0)w++;
	if(w>0&&m==1)w--;
	return w;
}

int main()
{
 gets(a);
 printf("%d\n",wcount(a,w));
 return 0;
} 