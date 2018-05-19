#include <stdio.h>
#include <string.h>
void superstr(char **supstr, int len, int dlin);

int main()
{
    int len, i, dlin;
    dlin = 0;
    scanf("%i", &len);
    char supstr[len][256];
    for(i=0;i<len;i++)
    {
            scanf("%s", supstr[i]);
    	dlin += strlen(supstr[i]);
    }
    superstr(supstr, len, dlin);
    return 0;
}
 

void superstr(char **supstr, int len, int dlin)
{
    int i, j, a=0 ,d=0, b, s = 0, f = 0,g = 0, l1, l2, q, w;
    int arr[len][len];
    for(i=0;i<len;i++)
        for(j=0;j<len;j++)
        {
            if(j==i) arr[i][j] = -666;
            else 
            {
                l1 = strlen[supstr[i]];
            	l2 = strlen[supstr[j]];
            	for(q=0;q<l1;q++)
            	{
                        w=0;
                        while(w<l1-q && w<l2)
        	        {
                                if(a[q+w]==b[w]) w++;
                                else break;
                                if(i+j==alen) arr[i][j] = j;
                                else arr[i][j] = 0;
    		        }
    		}
            	
            }
            arr[i][j] = strings(str[i], str[j]);
        }
    while(k<len-1)
    {
    	j=0;
        max=0;
        for(i=0;i<len;i++)
            while (j<nel)
                if (b<arr[i][j])
                {
                    b=arr[i][j];
                    a=i;
                    d=j;
                    ++j;
                }
                else ++j;
                s+=b;
                f++;
                j++;
                g = 0;
                while(g<len)
                {
                    len[g][d]=0;
                    len[a][g]=0;
                    g++;
                }
    }
    g = dlin - s;
    printf("%d", g);
}  
