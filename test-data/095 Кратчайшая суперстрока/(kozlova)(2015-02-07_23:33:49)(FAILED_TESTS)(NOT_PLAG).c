#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int glub(char S1[32], char S2[32]) 
{
        int i, lbig, lmin, maxlen;
	char sbig[32], smin[32], s1[32], s2[32];
	strcpy(s1, S1); // поэтому здесь копируем
	strcpy(s2, S2); // и здесь
	if (strlen(s1) > strlen(s2)){
		strcpy(sbig, s1);
		strcpy(smin, s2);
	}
	else {
		strcpy(sbig, s2);
		strcpy(smin, s1);
	}
	lmin = strlen(smin);
	if (strstr(sbig, smin) != NULL)return lmin;
	lbig = strlen(sbig);
	for (i = 1, maxlen = 0; i<lmin; i++){
		strcpy(s1, smin);
		s1[i] = 0;
		strcpy(s2, sbig + lbig - i);
		if (strcmp(s1, s2) == 0)maxlen = i;
		strcpy(s1, sbig);
		s1[i] = 0;
		strcpy(s2, smin + lmin - i);
		if (strcmp(s1, s2) == 0)maxlen = i;
	}
	return maxlen;
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
	int n, i, j, maxlen;
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