int wcount(char *s)
{
        int n = 0, i, k = strlen(s);
        for (i = 0; i < strlen(s) - 1; ++i ) 
        {
                if ((s[i] != " ") && (s[i + 1] == " "))
                n++;
        }
        return n;
}