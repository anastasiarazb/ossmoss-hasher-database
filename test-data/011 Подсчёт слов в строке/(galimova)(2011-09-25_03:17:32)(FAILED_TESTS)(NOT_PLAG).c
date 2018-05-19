#include<stdio.h>

int wcount(char *s) {
        int ans = 0;
	if (*s != ' ')
		ans++;
	for (int i = 0; *(s + i + 1) != 0; i++)
		if (*(s + i) == ' ' && *(s + i + 1) != ' ')
			ans++; 
	return ans;
}

int main(int argc, char *argv) {
	char s[100];
	gets(s);
	printf("%d\n", wcount(s));
}
