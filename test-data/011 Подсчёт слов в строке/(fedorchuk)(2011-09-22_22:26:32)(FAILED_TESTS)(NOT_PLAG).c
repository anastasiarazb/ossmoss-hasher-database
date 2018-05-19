 #include <stdio.h>
 #include <string.h>
 char p[100], k[2]={" "};
 int i=0;
 int wcount(char *s)
 {
     int a=0;
     while (p[i] != 0)
         {
            if ((p[i] != ' ' && p[i+1]==' ') || (p[i] != ' ' && p[i+1]==0))
                 a++;
            i++;
         }
     printf("%d\n",a);
return 0;
 }
 main()
 {
    printf("Введите строку слов\n");
    gets(p);
    wcount(p);
    return 0;
 }
