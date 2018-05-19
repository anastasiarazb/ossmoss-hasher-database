int wcount(char *s)
{
             n = 0;
             for (i = 0; i < strlen(s) - 1; ++i ) {
             if ((s[i] != " ") && (s[i + 1] ==" "))
             n++;
             }
return n;
}