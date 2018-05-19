#include <stdio.h>
main()
{
        int c,w=0,m=1;
	while((c=getchar())!='\n')
	{
		if(c==' '&&m==0){
			w++;
			m=1;
		}
		else m=0;   
	}
	if(w>0)w++;
	printf("%d\n",w);
	return 0;
}