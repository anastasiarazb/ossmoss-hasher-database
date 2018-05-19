#include <stdio.h>

int wcount(char *s)
{
    unsigned long count=0, i, l=0;
    char *p=s;
    while ((*p)!='\0') {
      if (*p==' ') l=0;
        else if ((*p!=' ') && (l==0)) {
	  l=1;
	  count+=1;
	}
      p++;
    }
    return count;
}

int main(int argc, char* argv[])
{
        char f[100000];
        int k;
        gets(f);	
        printf("%d", wcount(f));
        return 0;
}