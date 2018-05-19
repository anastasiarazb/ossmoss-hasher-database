#include <stdio.h>

int wcount(char *s)
{
    unsigned long count=0, i;
    char *p=s;
    while (*p!='\0') {
      printf("%c\n", *p);
      ++p;
      printf("%d\n", sizeof(p));
    }
    return count;
}

int main(int argc, char* argv[])
{
        char f;
        int k;
        gets(&f);
        k=wcount(&f);
        return 0;
}