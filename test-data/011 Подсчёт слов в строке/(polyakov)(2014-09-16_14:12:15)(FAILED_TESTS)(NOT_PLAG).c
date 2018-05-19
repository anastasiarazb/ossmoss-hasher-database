#include <stdio.h>

#include <string.h>

char text[BUFSIZ]; int word;
void wcount()
{
int iLen = strlen(text);

bool bPrev = (*text != 0x20);
bool bNext = bPrev;

word = bPrev ? 1 : 0;

for (int ii = 1; ii < iLen; ++ii)
{
bNext = pszText[ii] != 0x20;

if (bNext != bPrev)
{
if (text[ii] != 0x20)
{
++word;
}

bPrev = bNext;
}
}

}
int main(int argc,char** argv)
{

gets(text);
wcount();
printf("%d",word);

return 0;
}