
#include <ctype.h>
int wcount(char *s) 
{ 
        int count = 0, inw = 0,sp;
	s--;
	while (++s != 0)
	{
		sp = isspace((int)s);
		if(inw && sp)
			count++;
		inw = sp;		
	}
	if(inw)
		count++;
	return count;
}