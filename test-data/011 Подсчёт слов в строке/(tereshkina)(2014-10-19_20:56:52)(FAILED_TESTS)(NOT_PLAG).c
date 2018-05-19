int wcount(char *s) 

{
        int words(char c[]) {
        for ( int nc=0,i=0;c[i]!=0;i++){
		if (c[i]!=' ' && (i==0 || c[i-1]==' ')) nc++;
		}
		return nc; }
	return 0;
}