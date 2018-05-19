#include<stdio.h>



main ()
{
    int c,nl,nw,nc,state;
    nl=nw=nc=0;
    while ((c=getchar())!='\n')
    {
        ++nc;
        if (nc==1) if (c!=' ') ++nw;
        if (c==' ' || c=='\n' || c=='\t')
        state=0;
        else if (state==0)
        {
            state=1;
            ++nw;
        }
    }
    printf("%d\n", nw);
    return 0;
}