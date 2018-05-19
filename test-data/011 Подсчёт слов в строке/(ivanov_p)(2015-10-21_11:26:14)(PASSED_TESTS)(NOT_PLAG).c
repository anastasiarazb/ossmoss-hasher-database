#include <stdio.h>
#include<string.h>

main()
{
        int w=1,m=1,i=0,c=0;
	char a[1000];
	gets(a);
	c=strlen(a);
	for(i=0;i<c;i++){
		if(a[i]==' '&&m==0)w++;
		if(a[i]==' ')m=1;
		else m=0; 
	}
	
	if(m==0&&w==0)w++;
	if(w>0&&m==1)w--;
	printf("%d\n",w);
	return 0;
}