#include <stdio.h>
main()
{
        int c,w=1,m=1;
	while((c=getchar())!='\n')
	{
		if(c==' '&&m==0){
			w++;
			m=1;
		}
		else m=0;   
	}
	printf("%d\n",w);
	return 0;
}