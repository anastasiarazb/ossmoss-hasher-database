#include <stdio.h>
#define LENGTH 500
int wcount(char *s){
        int i, ans;
	for (i = ans = 0; *(s + i) != '\n'; i++) {
		if ((*(s + i) != ' ') && (!i || *(s + i - 1) == ' ')) ans++;
	}
	return ans;
}
int main(int argc, char **argv)
{
	char s[LENGTH];
	fgets(s, LENGTH, stdin);
	printf("%d\n", wcount(s));
	return 0;
}