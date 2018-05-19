int wcount(char *s)
{
    int res = 0;
    int flag = 0; // 0 - идут пробелы; 1 - идет слово

    int i;
    for(i = 0; s[i] != 0; i++){
        if (s[i] == ' '){
            flag = 0;
        }else if (s[i] != ' ' && !flag){
            res++;
            flag = 1;
        }
    }
    return res;
}