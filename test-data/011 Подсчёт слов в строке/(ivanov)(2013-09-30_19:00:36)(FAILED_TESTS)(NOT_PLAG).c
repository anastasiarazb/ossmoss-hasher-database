int wcount (char *s)
{
    int temp = 0;
    while (*s)
    {
        if((*s == ' ') && ( *(s+1) != ' '))
            temp++;
        s++;
    }
    if(*s != ' ') temp++;
    if(*s == ' ') return 0;
    return temp;
}


int main()
{
        char s[1000];
        gets(s);
        printf("%d", wcount(s));
}