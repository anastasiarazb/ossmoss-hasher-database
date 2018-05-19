int wcount(char *s) 
{ 
  int sum=0,i;
  
  int k=s[1];
  if ((s[0]!=' ') && (s[0]!=0))
    sum=1;
  for (i=1; s[i]!=0;i++) {
    if ((s[i-1]==' ') && (s[i]!=' ')){
      sum++;
    }
  }
  return sum;
} 