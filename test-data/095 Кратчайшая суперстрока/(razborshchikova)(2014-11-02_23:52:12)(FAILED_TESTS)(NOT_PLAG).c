#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000 //Число взято произвольно

#define SET_BIT(i) (1 << (i))
#define GET_BIT(arr, index) (1 & ((arr) >> (index)))

//#define DEBUG

#ifdef DEBUG
#define out printf
#define newline putchar('\n');
#define SHOW_RECURSION_DEPTH(i) {int k; for(k = 0; k < i; ++k) printf("  |");}

#else
#define out
#define newline
#define SHOW_RECURSION_DEPTH(i)
#endif

//char *place type **arr уже должны быть объявлены
#define MATRIX_MALLOC(place, arr, M, N, type) { \
    int i; \
    int col_size = (M)*sizeof(type *); \
    int str_size = (N)*sizeof(type); \
    place = (char *)malloc(col_size + (M)*str_size); \
    arr = (type **)(place); \
    for(i = 0; i < (M); ++i){ \
        arr[i] = (type *)((place) + col_size + i*str_size); \
    }\
  }

int pref_func2(char *str1, char *str2);
int cross_free(int str1, int str2); //аргументы - индексы строк
void permut(short arr, int m, int nel);
short init_arr(int m);
short erase_q_arr(short arr, int q);
int *add_q_cort(int *cort, int q, int i);
void show_cort(int *cort, int nel);

char **container; //Хранилище строк
int pi[MAX_LENGTH*2];

int main(void)
{
    int n, i;
    scanf("%d ", &n);
        // Выделение памяти под строки и считывание
    char *place;
    MATRIX_MALLOC(place, container, n, MAX_LENGTH, char);
    for (i = 0; i < n; ++i){
        scanf("%s", container[i]);
//        out("%s, ", container[i]);
    }

    permut(init_arr(n), n, n);
    // Освобождение выделенной ранее памяти   2 caacccca accaacccc
    free(place);
    return 0;
}
//Возвращает букву с текущим индексом из первого массива, если индекс меньше его длины
// и соответствующую букву из второго массива, если мы вышли за границу первого

#define STR1_t ((t < len) ? str1[t] : str2[t - len])

//Строим префиксную функцию для строки S, полученной конкатенацией
//двух строк. Наибольшая грань S = str2+str1 есть наибольшая
// длина пересечения строк str2 и str1
int pref_func2(char *str1, char *str2)
{
    //Сначала строим префиксную функцию только для первой строки
    int i, t;
    pi[0] = t = 0;
    for (i = 1; str1[i]; ++i){
        while (t && str1[t] != str1[i]){
            t = pi[t-1];
        }
        if (str1[t] == str1[i]){
            ++t;
        }
        pi[i] = t;
    }
    //Достраиваем префиксную функцию, используя вторую строку
    //как продолжение первой
    int len = i; //Длина первого слова
    for (; str2[i-len]; ++i){
        while (t && STR1_t != str2[i-len]){
            t = pi[t-1];
        }
        if (STR1_t == str2[i-len]){
            ++t;
        }
        pi[i] = t;
    }
    return pi[i-1];
}

//Суммарная длина двух строк минус длина их пересечения
int cross_free(int str1, int str2)
{
    int cross = pref_func2(container[str2], container[str1]);
    out("str1 = %s, str2 = %s cross = %d\n", container[str1], container[str2], cross);
    return strlen(container[str1]) - cross;
}
int shortest; //Длина текущей кратчайшей суперстроки

void init_shortest(int nel)
{
    int i;
    for(i = shortest = 0; i < nel-1; ++i){
        shortest += cross_free(i, i+1);
    }
    shortest += strlen(container[i]);
    out("FIRST_LEN = %d\n", shortest);
}

//Подсчет длины суперстроки, получающейся из текущей перестановки строк
void count_least(int *cort, int nel)
{
    int i, current;
    for(i = current = 0; i < nel-1; ++i){
        current += cross_free(cort[i], cort[i+1]);
    }
    current += strlen(container[cort[i]]);
    out("CURRENT_LEN = %d", current);
    if(current < shortest){
        shortest = current;
    }
}

//Размещения без повторений из m элементов по nel-элементому множеству
void permut_rec(short arr, int m, int nel, int counter, int *cort)
{
    if(counter == m){
//        show_cort(cort, counter);
        count_least(cort, nel);
        newline;
    } else {
        int i;
        for(i = 0; i < nel; ++i){
            if(GET_BIT(arr, i)){
                permut_rec(erase_q_arr(arr, i), m, nel, counter + 1, add_q_cort(cort, i, counter));
            }
        }
    }
}

void permut(short arr, int m, int nel)
{
    int *cort = (int *)calloc(m, sizeof(int));
    init_shortest(nel);
    permut_rec(arr, m, nel, 0, cort);
    free(cort);
    out("SHORTEST = ");
    printf("%d\n", shortest);
}

//-------------Функции обработки множества, хранящегося в цeлом числе и кортежа, хрян. в массиве----------

//Отметить все элементы, как принадлежащие множеству
short init_arr(int m)
{
    return SET_BIT(m)-1;
}

//Возвращает массив с удаленным элементом q
short erase_q_arr(short arr, int q)
{
//    printf("erase q = %c; ", massive[q]);
//    show_arr(arr - SET_BIT(q), massive, 4);
    return GET_BIT(arr, q) ? (arr ^ SET_BIT(q)) : arr;
}

int *add_q_cort(int *cort, int q, int i)
{
//    printf("ADD: size = %d, last = %c\n", cort[0], massive[q]);
    cort[i] = q;
    return cort;
}

void show_cort(int *cort, int nel)
{
    int i;
    for(i = 0; i < nel; ++i){
        printf("[%d]%s ", cort[i], container[cort[i]]);
    }
    newline;
}
