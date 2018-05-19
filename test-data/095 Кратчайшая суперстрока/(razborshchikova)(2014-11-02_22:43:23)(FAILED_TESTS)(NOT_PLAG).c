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


int cross_free(int str1, int str2); //аргументы - индексы строк
int is_substr(int s1, int i, int s2);
void permut(short arr, int m, int nel);
short init_arr(int m);
short erase_q_arr(short arr, int q);
int *add_q_cort(int *cort, int q, int i);
void show_cort(int *cort, int nel);

char **container; //Хранилище строк


int main(void)
{
    int n, i;
    scanf("%d ", &n);
        // Выделение памяти под строки и считывание
    char *place;
    MATRIX_MALLOC(place, container, n, MAX_LENGTH, char);
    for (i = 0; i < n; ++i){
        scanf("%s", container[i]);
    }
    permut(init_arr(n), n, n);
    // Освобождение выделенной ранее памяти   2 caacccca accaacccc
    free(place);
    return 0;
}


//Вычисление длины части первой строки, которая не пересекается со второй (в качестве аргументов принимаются НОМЕРА строк)
int cross_free(int str1, int str2){
    int i;
    for(i = 0; container[str1][i]; ++i){
        if (is_substr(str1, i, str2)){
            break;
        }
    }
    return i;

}

int is_substr(int s1, int i, int s2){ //Является ли строка, начинающаяся с i-го элемента s1 началом строки s2
    int j;
    for(j = 0; container[s1][i+j]; ++j){
        if(container[s1][i+j] != container[s2][j]) return 0;
    }
    return j; //возвращает длину пересечения строк
}


int shortest; //Длина текущей кратчайшей суперстроки

void init_shortest(int nel)
{
    int i;
    for(i = shortest = 0; i < nel-1; ++i){
        shortest += cross_free(i, i+1);
    }
    shortest += strlen(container[i]);
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
    return GET_BIT(arr, q) ? (arr ^ SET_BIT(q)) : arr;
}

int *add_q_cort(int *cort, int q, int i)
{
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

