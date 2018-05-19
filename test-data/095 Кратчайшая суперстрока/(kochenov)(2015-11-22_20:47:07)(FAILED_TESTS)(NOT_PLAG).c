#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sovpad (char *C1, char *C2) {
    int i, k, j, res;
    for (i=1, res=k=0; C1[i]; i++, k=0) {
        for (j=i; C1[j]&&C2[k]; j++, k++)
            if (C1[j]!=C2[k]) {
                k = 0;
                break;
            }
        if (k > res) res = k;
    }
        return res;
}

void MyStrApp(char *s1, char *s2, int sovpad) {
    s1[strlen(s1)-sovpad]='\0';
    strcat(s1, s2);
    s2[0] = '\0';
}

int main()
{
    short n, i;
    scanf("%hd", &n);
    char arr[n][50];
    for (i=0;i<n;i++) gets(arr[i]);
    short k, j, cur, max, s1, s2, res, m;
    for (k=0; k<n; k++) {
        for (i=0, max=-1; i<n; i++) {
            for (j=0; j<n; j++) {
                if ((i!=j)&&arr[i][0]&&arr[j][0]) {
                    cur = sovpad(arr[i], arr[j]);
                    if (cur > max) {
                        max = cur;
                        s1 = i;
                        s2 = j;
                    }
                }
            }
        }
	MyStrApp(arr[s1], arr[s2], max);
	res = s1;
    }
    printf("%d", strlen(arr[res]));
    return 0;
}
