#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Find(char* str1, char* str2)
{
    int n, i, j, k,c;
    if (str1[0] == '\0' || str2[0] == '\0')
        return -1;
    n= (int)strlen(str1);
    k = 0;
    for (i = 0; i < n; i++){
        c = 0;
        for (j = i; j < n; j++){
            if (str1[j] == '\0' || str2[c] == '\0')
                break;
            if (str1[j] == str2[c]){
                c++;
            }
            else{
                c = 0;
                break;
            };
        };
        if (c > k)
            k = c;
    };
    return k;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    char** mass;
    char* shortest;
    mass = (char**)malloc(n*sizeof(char*));
    for (i = 0; i < n; i++){
        mass[i] = (char*)calloc(1024,sizeof(char));
        scanf("%s", mass[i]);
    };
    int a = 0, b = 0, k, j, maxl, l;
    for (k = 0; k < n; k++){
        maxl = -1;
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (i == j)
                    continue;
                l =  Find(mass[i], mass[j]);
                if (l > maxl){
                    maxl = l;
                    a = i;
                    b = j;
                };
            };
        };
        if (maxl >= 0){
            mass[a][strlen(mass[a]) - maxl] = '\0';
            strcat(mass[a], mass[b]);
            mass[b][0] = '\0';
            shortest = mass[a];
        };
    };
    printf("%d\n", strlen(shortest));
    for (i = 0; i < n; i++)
    {
        free(mass[i]);
    }
    free(mass);
    return 0;
}