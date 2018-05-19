#include <stdio.h>
#include <string.h>

int f2(const char *str, const char *st)
{
        int l, nu=0, i, j, fl, ln;
	char *st1, *st2;
	i=nu+1;
	j=nu;
	fl=nu;
	ln=nu;
    while(strnlen(str,50)>strnlen(st,50))
	{
		l=strnlen(st,50);
		fl=1;
		break;
    }
	while(fl=0)
	{
		l=strnlen(str,50);
		break;
    }
	st1=malloc(l*sizeof(char));
	st2=malloc(l*sizeof(char));
	while(i<l && ln==0)
	{
        while(j==0 || st1[j-1]!=0)
        {
			st1[j]=str[j+strnlen(str,50)-l+i];
			j++;
		}
		strncpy(st2,st,l-i);
		st2[l-i]=0;
		while(strcmp(st1,st2)==0)
		{	
            ln=l-i;
			break;
        }
		i++;	
	}
	free(st1);
	free(st2);
	return ln;
}

void n1(int **mas, int *xm, int n)
{
	int nu=0, i, j, u, k, b, m;
	i=nu;
	j=nu;
	u=nu;
	m=nu;
    while(i<n-1)
    {
		while(j<n)
		{
			while(u<n)
			{
				if(mas[j][u]>m)
                {
					m=mas[j][u];
					k=j;
					b=u;
				}
				u++;
			}
			j++;
		}	
		j=0;
        while(j<n)
        {
            mas[k][j]=0;
			mas[j][b]=0;
			j++;
		}
		*xm+=m;
		m=0;
	    i++;
    }
	return;
}

int main()
{
	int i=0, j=0, xm, n, **mas;
	char **ki;
	scanf("%d\n",&n);
	ki=malloc(n*sizeof(char*));
	while(i<n)
	{
		ki[i]=malloc(50*sizeof(char));
		gets(ki[i]);
		i++;
	}
	mas=malloc(n*sizeof(int*));
	while(i>0)
	{
		mas[i-1]=malloc(n*sizeof(int));
		i--;
    }	
	while(i<n)
	{
		while(j<n)
        {
			mas[i][j]=f2(ki[i],ki[j]);
			if(i==j)
				mas[i][j]=0;
			j++;	
		}
		i++;
	}
	xm=0;	
	n1(mas,&xm,n);
	xm*=-1;
	i=0;
	while(i<n)
	{
        xm+=strnlen(ki[i],50);
        i++;
    }
	printf("%d\n",xm);
	while(i>0)
	{
		free(ki[i-1]);
		i--;
    }
	free(ki);
	while(i<n)
	{
		free(mas[i]);
		i++;
    }
	free(mas);
	return 0;
}
