
#include <stdio.h>

void prefix (char *s, unsigned long len, unsigned long i, unsigned long j)
{
        unsigned long t, i;
        p[0] = t = 0;
        i = 1;
        while (i < len) {
                while ((t > 0) && (s[t] != s [i])) t = p[t - 1];
                if (s[t] == s[i]) t++;
                p[i] = t;
                i++;
        }
} 

int main()
{
	return 0;
}
