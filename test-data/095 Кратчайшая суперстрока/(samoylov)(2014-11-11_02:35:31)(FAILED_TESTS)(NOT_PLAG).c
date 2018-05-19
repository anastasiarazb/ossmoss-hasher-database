#include <stdio.h> 
#include  <string.h>
int main()
{
int n;
scanf ("%d", &n);
char str[n+1][100];
char s=putchar(64);
int i, j, minss, t=0,c=0,maxj=0,a=0,b=0,len=0,lenmax=0,id=0;
int go[100];
minss=0;
for (i=0;i<n;i++)
{
scanf("%c",str[i]);
strcat(str[i],s);
}
int count[n];
for (i=0;i<n;i++)
count[i]=0;//!!!!!!!!!!!!!!!!!!!!!!
int first (char *str[a][b], int count[a-1], int c, int d, int length, char s)
{
if (d==(a-1))
        return length;
else
{
	len=0;
	lenmax=0;
	for (i=0;i<a-1;i++)
	{
		if (count[i]==0)
		{
			t=0;
			j=0;
			while ((str[i][j]!=s)&&(str[c][t]!=s))
			{
				if (str[i][j]==str[c][t])
				{
					len+=1;
					j+=1;
				}
				else
				{
					len=0;
					j+=1;
				}
				if (str[i][j]==s)
				{
					j=0;
					t+=1;
				}
				if (len>lenmax)
				{
					id=i;
					lenmax=len;
				}
			}
		}
	}
count[id]=lenmax;
length+=lenmax;
d+=1;
c=id;
if (lenmax==0)
	return lenmax;
else
	{
	return second(str[a][b], count[a-1], c, d, length, s);
	return first(str[a][b], count[a-1], c, d, length, s);
}
}
int second(char *str[a][b], int count[a-1], int c, int d, int length, char s)
{
if (d==(a-1))
	return length;
else
{
	len=0;
	lenmax=0;
	for (i=0;i<a-1;i++)
	{
		if (count[i]==0)
		{
			t=0;
			while (str[c][t]!=s)
			{
				t+=1;
			}
			j=0;
			while (str[i][j]!=s)
			{
				j+=1;
				maxj=j;
			}
			while ((t>0)&&(j>0))
			{
				if (str[i][j]==str[c][t])
				{
					len+=1;
					j-=1;
				}
				else
				{
					len=0;
					j-=1;
				}
				if (str[i][j]==s)
				{
					j=maxj;
					t-=1;
				}
				if (len>lenmax)
				{
					id=i;
					lenmax=len;
				}
			}
		}
	}
count[id]=lenmax;
length+=lenmax;
d+=1;
c=id;
if (lenmax==0)
	return lenmax;
else
	{
	return second(str[a][b], count[a-1], c, d, length, s);
	return first(str[a][b], count[a-1], c, d, length, s);
}
}
go[first(str[n+1][100], count[n], 0, 0, 0, s)]=1;
//void sstring (char str[a][b], int rez[hundred])
//{
//if (k==a-1)
//if ((b<minss)||(minss==0))
//minss=b;
//}
//for (i=0;i<n;i++)
//while (str[i][j]!=s)
//{



//}


return 0;
}