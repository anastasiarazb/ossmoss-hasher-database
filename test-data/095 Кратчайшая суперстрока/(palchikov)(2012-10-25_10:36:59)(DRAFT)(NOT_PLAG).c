
#include <stdio.h>

int mut(char *a, char *b)

int minLength()

int main()
{
        int n, i, a[10]={0};
        char **str;
        scanf("%d", n);
        str = (char*)malloc(sizeof(char*)*n);
        
        for(i=0;i<n;i++)
                str[i] = malloc(100);
        for(i=0;i<n;i++)
                scanf("%s", *str[i]);
	return 0;
}
