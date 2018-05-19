#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/////////////попытка 74/////////////
int prefix(char *s)
{
        int i,l=strlen(s),pi=1;
        for(i=0;i<l/2;i++) if(s[i]!=s[i+l/2]) pi=0;
	return pi;
}

int main()
{
	char s[10][1024], t[10240];
	int n,i,j[9],g,k,a[10][10]={0},l=0,li,lj,pi,vongola=0,min;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%s",s[i]);
	for(i=n;i<10;i++) strcpy(s[i],"");
	for(i=0;i<n;i++)
	{
		li=strlen(s[i]);
		l+=li;
		for(g=0;g<n;g++)
		{
			if(i==g) continue;
			lj=strlen(s[g]);
			(lj>=li) ? (k=li) : (k=lj);
			for(k; k>0; k--)
			{
				strcpy(t,(s[i]+li-k));
				strncat(t,s[g],k);
				pi=prefix(t);
				if(pi) {a[i][g]=k; break;}
			}
		}
	}
	for(j[0]=0;j[0]<10;j[0]++)
	{
		for(j[1]=0;j[1]<10;j[1]++)
		{
			if(j[1]==j[0]) continue;
			for(j[2]=0;j[2]<10;j[2]++)
			{
				k=0;
				for(i=0;i<2;i++) if(j[2]==j[i]) k=1;
				if(k) continue;
				for(j[3]=0;j[3]<10;j[3]++)
				{
					k=0;
					for(i=0;i<3;i++) if(j[3]==j[i]) k=1;
					if(k) continue;
					for(j[4]=0;j[4]<10;j[4]++)
					{
						k=0;
						for(i=0;i<4;i++) if(j[4]==j[i]) k=1;
						if(k) continue;
						for(j[5]=0;j[5]<10;j[5]++)
						{
							k=0;
							for(i=0;i<5;i++) if(j[5]==j[i]) k=1;
							if(k) continue;
							for(j[6]=0;j[6]<10;j[6]++)
							{
								k=0;
								for(i=0;i<6;i++) if(j[6]==j[i]) k=1;
								if(k) continue;
								for(j[7]=0;j[7]<10;j[7]++)
								{
									k=0;
									for(i=0;i<7;i++) if(j[7]==j[i]) k=1;
									if(k) continue;
									for(j[8]=0;j[8]<10;j[8]++)
									{
										k=0;
										for(i=0;i<8;i++) if(j[8]==j[i]) k=1;
										if(k) continue;
										min=0;
										for(g=1;g<9;g++)
										{
											min+=a[j[g-1]][j[g]];
										}
										if(min>vongola) vongola=min;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d",l-vongola+1);
	return 0;
}