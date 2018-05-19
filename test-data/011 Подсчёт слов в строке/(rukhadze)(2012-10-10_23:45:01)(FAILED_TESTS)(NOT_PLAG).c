#include <stdio.h>
#include <stdlib.h>

int wcount(char *s) {
        int i,k;
	k=1;
	for (i=0;s[i]!=0;i++){
		if (s[i]==' '){
			k++;
			if (s[i+1]==' ')
				k--;
		if (s[i+1]==0)
			k--;
		}
	}
	if (s[0]==' ')
		k--;
	if (s[0]==0)
		k=0;
	return k;
}

int main (int argc, char **argv){
	char *a;
	int x;
	gets (a);
	x=wcount(a);
	printf ("%d\n",x);
	return 0;	
}