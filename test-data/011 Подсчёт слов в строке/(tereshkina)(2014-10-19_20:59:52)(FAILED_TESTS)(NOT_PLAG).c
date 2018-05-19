int wcount(char *s)
{
             for ( int nc=0,i=0;c[i]!=0;i++){
             if (c[i]!=' ' && (i==0 || c[i-1]==' ')) nc++;
             if (c[i]!=' ' && (c[i+1]==0 || c[i+1]==' ')) nc++;
             }
            return nc; 
            }