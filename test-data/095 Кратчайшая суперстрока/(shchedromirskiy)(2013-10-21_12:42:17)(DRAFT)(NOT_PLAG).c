#include <stdio.h>
#include <stdbin.h>
int main(){
        int n, j, i;
        scanf("%d", &n);
	char s[100][n];
	int superconcat(char *s1, char *s2){
		int k=0,z,g;
		for (j=0;j<100;j++) {
			for (i=0;i<100;i++) {
				if (s1[j]==s2[i]) k+=1;
				else if (k!=0) {
					i=100;
					j=100;
					z=j;
				}
			}
		}
		int m=0;
		for (j=0;j<100;j++) {
			for (i=0;i<100;i++) {
				if (s2[j]==s1[i]) m+=1;
				else if (m!=0) {
					i=100;
					j=100;
					g=j;
				}
			}
		}
		if (m>k) strncat(s[j, s[j], 80);
		
			
