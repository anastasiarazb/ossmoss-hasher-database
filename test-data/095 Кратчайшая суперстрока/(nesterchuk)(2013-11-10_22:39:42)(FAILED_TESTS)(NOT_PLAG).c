#include <stdio.h>
#include <string.h>


int fac(int n)
{
        int i, sum=1;
	for (i=2; i<=n; i++) sum=sum*i;
	return sum;
}

void put(char str[11][20], char s[11][20])
{
	int i, j;
	for (i=0; i<11; i++) {
		for (j=0; j<20; j++) s[i][j]=str[i][j];
	}
	return;
}

void cut(int n, char s[11][20])
{
	int i, j, step, maxstep=0, k, flag=0, len;
	char tmp[11][20];
	put(s, tmp);
	for (i=0; i<n; i++) if (strlen(s[i])>maxstep) maxstep=strlen(s[i]);
	for (step=maxstep-1; step>0; step--) {
		for (k=0; k<n; k++) {
			len=strlen(tmp[k]);
			for (i=0; i<step; i++) {
				if (step<len && tmp[k][len-step+i]==tmp[k+1][i]) flag=1;
				else {
					flag=0;
					break;
				}
			}
			if (flag==1) {
				for (j=0; j<step; j++) s[k][len-step+j]=0;
				flag=0;
			}
		}
	}
	return;
}


void unite(char *sup, int n, char s[][20])
{
	int i, k, j;
	for (i=0, k=0, j=0; i<201 && k<n; i++, j++) {
		if (j>=strlen(s[k])) {
			j=0;
			k++;
		}
		sup[i] = s[k][j];
	}
	return;
}

void swap(char *a, char *b)
{
	char temp[20], i;
	for (i=0; i<20; i++) {
		temp[i]=a[i];
		a[i]=b[i];
		b[i]=temp[i];
	}
	return;
}


int main()
{
	int n, i, j, min=0, len;
	char str[11][20]={{0}}, sup[201]={0}, s[11][20]={{0}};
	scanf("%d\n",&n);
	for (i=0; i<n; i++) gets(str[i]);
	put(str, s);
	cut(n, s);
	unite(sup, n, s);
	min=strlen(sup);
	memset(sup, 0, 201);
	put(str, s);
	for (j=1, i=0; j<fac(n-1); j++, i++) {
		if (i>=n) i=0;
		if (i==n-1) swap(str[i], str[0]);
		else swap(str[i], str[i+1]);
		put(str, s);
		cut(n, s);
		unite(sup, n, s);
		len=strlen(sup);
		if (len<min) min=len;
		memset(sup, 0, 201);
	}
	printf("%d\n", min);
	return 0;
}


