#include <stdio.h>
main()
{
        int c,w=1,m=1;
	while((c=getchar())!='\n')
	{
		if(c==' '&&m==0)w++;
		if(c==' ')m=1;
		else m=0;   
	}
	
	if(m==0&&w==0)w++;
	if(w>0&&m==1)w--;
	printf("%d\n",w);
	return 0;
}