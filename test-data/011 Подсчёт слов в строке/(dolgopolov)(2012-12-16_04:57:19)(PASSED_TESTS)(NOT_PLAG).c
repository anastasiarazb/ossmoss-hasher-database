# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main(){
        char tmp=0, str[100], buf[100];
	int val=0, count=0;

	while(tmp != '\n'){
		buf[0]=0;
		str[0]=0;
		scanf("%[^0-9a-z\n]", buf);
		count += scanf("%[0-9a-z]", str);
		scanf("%c", &tmp);
	}

	printf( "%d\n", count);
	return 0;
}