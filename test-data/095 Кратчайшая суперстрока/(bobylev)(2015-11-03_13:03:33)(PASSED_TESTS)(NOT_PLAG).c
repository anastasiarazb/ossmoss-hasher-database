#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LogN(a) printf("%ld\n",a)
#define Log(a) printf("%s\n",a)
#define LogSN(a, b) printf("%s%ld\n", a, b)
#define MaxSize 256

long overlap(char *s1, char *s2)
{
    //Log("Overlap");
    long len_s1 = strnlen(s1,MaxSize);
    long len_s2 = strnlen(s2,MaxSize);
    long res = 0;
    long left, right;

    for (left = len_s1 - 1, right = 1;
         right <= len_s2 && left >= 0; right++, left--) {
        if (memcmp(&(s1[left]), s2, right) == 0 ) res = right;
    }

    return res;
}

void insert(char *super_str, char *s2, long num)
{
    //Log("insert");
    /*
    LogN(num);
    Log(super_str);
    Log(s2);
    //*/

    long len_s1 = strnlen(super_str,MaxSize);
    long len_s2 = strnlen(s2,MaxSize);

    long i, t;
    i = len_s1;
    for (t = num; t < len_s2; t++, i++) {
        super_str[i] = s2[t];
    }
    super_str[i] = 0;

}

long getSuperStringLen(char **str, long num)
{
    long count, res = strnlen(str[0], MaxSize);

    long i, t, max_num, over1, over2;
    long in, out;

    for (t = 1; t < num; t++) {
        max_num = 0;
        for (count = 0; count < num; count++) {
            if (str[count][0]) for (i = 0; i < num; i++) {
                    if (str[i][0] != 0 && count != i) {
                        over1 = overlap(str[count], str[i]);
                        over2 = overlap(str[i], str[count]);
                        if (over1 > max_num) {
                            max_num = over1;
                            in = count;
                            out = i;
                        }
                        if (over2 > max_num) {
                            max_num = over2;
                            in = i;
                            out = count;
                        }

                    }
                }

        }

        if (max_num == 0) {
            for (count = 0; count < num && str[count][0] == 0; count++);
            for (i = count + 1; i < num && str[i][0] == 0; i++);
            in = count;
            out = i;

        }

        insert(str[in], str[out], max_num);
        str[out][0] = 0;
    }

    for (i = 0; str[i][0] == 0; i++);
    res = strnlen(str[i], MaxSize);

    return res;
}

int main()
{
    long i, num;
    scanf("%ld ", &num);
    char **str = (char**)malloc (num * sizeof(char*));

    size_t length,k;
    char buffer[256] = { 0 };
    for (i = 0; i < num; i++) {
        gets(buffer);
        str[i] = (char*)malloc ((MaxSize) * sizeof(char));

        length = strnlen(buffer,MaxSize);
        if (buffer[length-1] == ' ') length--;
        //str[i] = (char*)malloc ((length + 1) * sizeof(char));
        for (k = 0; k < length; k++) {
            str[i][k] = buffer[k];
        }

        str[i][k] = 0;
    }

    long res = getSuperStringLen(str, num);
    printf("%ld", res);

    for (i = 0; i < num; i++) {
        free(str[i]);
    }
    free(str);

    return 0;
}