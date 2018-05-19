#include <stdio.h>
#include <stdlib.h>

int wcount(char *s) 
{ 
        int count =0,i;
	i=0;
	while(s[i]!=0)
	{
		if(s[i]!=' ' && (s[i+1]==' ' || s[i+1]==0 ))
			count++;
		i++;
	}
	return count;
}
int main()
{
	char str[256];
	int q;
	gets(str);
	q = wcount(str);
	printf("%d",q);
	//system("pause");
	return 0;
}
