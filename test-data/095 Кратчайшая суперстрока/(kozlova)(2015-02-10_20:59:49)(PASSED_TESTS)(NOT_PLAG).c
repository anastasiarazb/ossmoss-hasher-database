#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int glub(char S1[32], char S2[32])
{
        short int i = 1, j, g, l1, l2, M = 0;
	l1 = strlen(S1);
	l2 = strlen(S2);
	g = (l1 > l2 ? l2 : l1) - 1;
	while (i <= g)
	{
		for (j = 0; j < i && S1[l1 - i + j] == S2[j]; j++);
		if (j == i++ && j > M)M = j;
	}
	return M;
}

int perebor(char sl[10][32], int n, char ch[10][32], int g)
{
	int i, G, Gcur;
	char s[32];
	if (g == n){
		for (i = 0, G = 0; i<g - 1; i++)
			G += glub(ch[i], ch[i + 1]);
		return G;
	}
	for (i = 0, G = 0; i<n; i++){
		if (!strlen(sl[i]))continue;
		strcpy(s, sl[i]);
		strcpy(sl[i], "");
		strcpy(ch[g], s);
		Gcur = perebor(sl, n, ch, g + 1);
		if (Gcur > G)G = Gcur;
		strcpy(sl[i], s);
	}
	return G;
}

int main()
{
	int n, i, maxlen;
	char s[32];
	char sl[10][32], ch[10][32];
	scanf("%d", &n);
	for (i = 0, maxlen = 0; i<n; i++){
		scanf("%s", &s);
		maxlen += strlen(s);
		strcpy(sl[i], s);
		strcpy(ch[i], "");
	}
	printf("%d", maxlen - perebor(sl, n, ch, 0));
}