int wcount (char *s)
{
    int temp = 0;
    if(*s != ' ') 
        temp++;
    while (*s)
    {
        if( (*s==' ') && ( *(s+1) != ' ') )
            temp++;
        s++;
    }
    return temp;
}