#include <stdio.h>
#include <string.h>
char pszText[BUFSIZ]; int iCnt;
void wcount()
{
int iLen = strlen(pszText);

bool bPrev = (*pszText != 0x20);
bool bNext = bPrev;

iCnt = bPrev ? 1 : 0;

for (int ii = 1; ii < iLen; ++ii)
{
bNext = pszText[ii] != 0x20;

if (bNext != bPrev)
{
if (pszText[ii] != 0x20)
{
++iCnt;
}

bPrev = bNext;
}
}

}
int main(int argc,char** argv)
{

gets(pszText);
wcount();
printf("Words total: %d\n",iCnt);

return 0;
}