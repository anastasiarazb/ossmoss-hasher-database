# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int wcount(char *s){ 
        char buf[10];
	int val=0, tmp, count=0;

	while(s[0] != 0){
		val=0;
		sscanf (s, "%[^0-9a-z]%n", buf, &val);
		s += val;
		val=0;
		tmp = sscanf (s, "%[0-9a-z]%n", buf, &val);
		if(tmp>0) count+=tmp;
		s += val;
	}
	return count;
}

int main(){
	char s[100];
	gets(s);
	printf ("%d\n", wcount (s));
	return 0;
}