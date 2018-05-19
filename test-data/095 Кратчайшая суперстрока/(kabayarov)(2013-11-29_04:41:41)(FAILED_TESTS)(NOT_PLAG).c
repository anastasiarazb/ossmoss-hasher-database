
#include <stdio.h>

int main()
{
        int i,n=362880,*a;
        for(i=0;i<n;i++)
        {
                a=(int*)malloc(10*sizeof(int));
                free(a);
        }
        printf("13");
	return 0;
}
