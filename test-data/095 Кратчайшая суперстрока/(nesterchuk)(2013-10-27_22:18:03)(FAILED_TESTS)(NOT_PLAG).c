
#include <stdio.h>
#include <string.h>

//void move(char *s, int from, int howmuch)
//{
//        int i;
//        for (i=from; s[i]!=0; i++) s[i] = s[i+howmuch];
//}

int fac(int n)
{
        int i, sum=1;
        for (i=2; i<=n; i++) sum=sum*i;
        return sum;
}



void cut(int n, char (*s)[n+1])
{
        int i, j, step, maxstep=0, k, flag=0;
        for (i=0; i<n; i++) if (strlen(s[i])>maxstep) maxstep=strlen(s[i]);
        for (step=maxstep-1; step>0; step--) {
                for (k=0; k<n; k++) {
                        for (i=0; i<step; i++) {
                                if (step<strlen(s[k]) && s[k][strlen(s[k])-step+i]==s[k+1][i]) flag=1;
                                else {
                                        flag=0;
                                        break;
                                }
                        }
                        if (flag==1) {
                                for (j=0; j<step; j++) s[k][strlen(s[k])-step+j]=0;
                                flag=0;
                        }
                }
        }
}


//void cut(char *s[n])
//{
//        int i, j, step, len, flag=0;
//        len = strlen(s);
//        for (step=len/2; step>0; step--) {
//                for (i=0; i<len; i=i+step) {
//                        for (j=0; j<step; j++) {
//                                if (s[i+j]==s[i+j+step] && s[i+j]!=0) flag=1;
//                                else {
//                                        flag=0;
//                                        break;
//                                }
//                        }
//                        if (flag=1) move(s, i, step);
//                        flag=0;
//                }
//        }
//}

void unite(char *sup, int n, char (*s)[n+1])
{
        int i, k, j;
        for (i=0, k=0, j=0; i<256 && k<n; i++, j++) {
                if (j>=strlen(s[k])) {
                        j=0;
                        k++;
                }
                sup[i] = s[k][j];
        }
}

void swap(char *a, char *b)
{
        char temp[20], i;
        for (i=0; i<20; i++) {
                temp[i]=a[i];
                a[i]=b[i];
                b[i]=temp[i];
        }
}

int main()
{
        int n, i, j, min=0;
        scanf("%d", &n);
        char s[11][20]={{0}}, sup[256]={0};
        for (i=0; i<n; i++) gets(s[i]);
        cut(n, s);
        unite(sup, n, s);
        min=strlen(sup);
        memset(sup, 0, 256);
        for (j=1, i=0; j<fac(n); j++, i++) {
                if (i>=n) i=0;
                if (i=n-1) swap(s[i], s[0]);
                else swap(s[i], s[i+1]);
                cut(n, s);
                unite(sup, n, s);
                if (strlen(sup)<min) min=strlen(sup);
                memset(sup, 0, 256);
        }
        printf("%d", min);
        return 0;
}


