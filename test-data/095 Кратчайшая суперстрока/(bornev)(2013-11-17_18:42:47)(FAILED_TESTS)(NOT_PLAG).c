#include <stdio.h>
#include <stdlib.h>

#define is_null(ptr)  \
{  \
if (ptr == NULL)  \
    {  \
        printf("[ERROR] Pointer at %s:%llu is NULL \n",__FILE__,__LINE__); \
        exit(1);  \
    }  \
}


#define true 1
#define false 0

typedef unsigned char byte;
typedef byte bool;

#define GOLDEN_RATIO 1.61803398875

typedef int type;


#define CREATE_VECTOR_TYPE_H(type)  \
typedef struct vector_##type vector_##type; \
typedef struct vector_##type { \
    size_t size;  \
    size_t size_mem; \
    type* array; \
    void (*push_back)(vector_##type* vec, const type elem); \
    size_t (*length)(vector_##type* vec); \
    void (*resize)(vector_##type* vec, const size_t size); \
    void (*set)(vector_##type* vec, const size_t pos, type element); \
    type* (*get)(vector_##type* vec, const size_t pos); \
    void (*show)(vector_##type* vec,const char* specifier, bool debug); \
    void (*clear)(vector_##type* vec); \
    void (*delete)(vector_##type* vec); \
} vector_##type; \
\
void __vector_clear_##type(vector_##type* vec);  \
void __vector_push_back_##type(vector_##type* vec, type element);  \
void __vector_resize_##type(vector_##type* vec, const size_t size);  \
void __vector_show_##type(vector_##type* vec, const char* specifier, bool debug);  \
size_t __vector_length_##type(vector_##type* vec);  \
type* __vector_get_##type(vector_##type* vec, const size_t pos);  \
void __vector_set_##type(vector_##type* vec, const size_t pos, type element); \
void __vector_delete_##type(vector_##type* vec); \
 \
vector_##type vector_##type##_create() \
{ \
    vector_##type vec;  \
     \
    vec.size_mem = 0; \
    vec.size = 0; \
    vec.array = NULL; \
     \
    vec.push_back = __vector_push_back_##type; \
    vec.length = __vector_length_##type; \
    vec.resize = __vector_resize_##type; \
    vec.get = __vector_get_##type; \
    vec.set = __vector_set_##type; \
    vec.show = __vector_show_##type; \
    vec.clear = __vector_clear_##type; \
    vec.delete = __vector_delete_##type; \
    return vec; \
} \
 \
void __vector_delete_##type(vector_##type* vec) \
{ \
    if (vec->array) \
        free(vec->array); \
 \
    vec->size_mem = 0; \
    vec->size = 0; \
    vec->array = NULL; \
} \
 \
void __vector_clear_##type(vector_##type* vec) \
{ \
    memset(vec->array, 0, sizeof(type)*(vec->size_mem)); \
} \
 \
void __vector_push_back_##type(vector_##type* vec, type element) \
{ \
    if (vec->size >= vec->size_mem) \
    { \
        vec->array = realloc(vec->array, sizeof(type) * (vec->size_mem + 1) * GOLDEN_RATIO); \
    is_null(vec->array); \
        memset(vec->array + vec->size_mem, 0 , ((vec->size_mem + 1) * GOLDEN_RATIO - vec->size_mem)*sizeof(type)); \
         \
    vec->size_mem = (vec->size_mem + 1) * GOLDEN_RATIO; \
    } \
    vec->array[vec->size++] = element; \
} \
 \
void __vector_resize_##type(vector_##type* vec, const size_t size) \
{ \
    if (size > vec->size_mem) { \
    vec->array = realloc(vec->array, sizeof(type) * (size + 1) * GOLDEN_RATIO); \
    is_null(vec->array); \
    memset(vec->array + vec->size_mem, 0 , ((size + 1) * GOLDEN_RATIO - vec->size_mem)*sizeof(type)); \
    vec->size_mem = (size + 1) * GOLDEN_RATIO; \
    } \
    vec->size = size; \
} \
 \
void __vector_show_##type(vector_##type* vec, const char* specifier, bool debug) \
{ \
    int i; \
    size_t n = debug? vec->size_mem : vec->size; \
    for (i = 0; i < n; i++) \
    { \
        printf(specifier,vec->array[i]); \
    } \
    printf(" \n"); \
} \
 \
size_t __vector_length_##type(vector_##type* vec) \
{ \
    return vec->size; \
} \
 \
type* __vector_get_##type(vector_##type* vec, const size_t pos) \
{ \
    if (pos < vec->size) \
        return &vec->array[pos]; \
 \
    printf("[WARNING] Vector.get() %p: is out_of_range \n",vec); \
    exit(-1); \
    return NULL; \
} \
 \
void __vector_set_##type(vector_##type* vec, const size_t pos, type element) \
{ \
    if (pos < vec->size) \
    { \
        vec->array[pos] = element; \
    } \
    else \
    { \
        printf("[WARNING] Vector.set() %p: is out_of_range \n",vec);  \
        exit(-1);  \
    } \
} \

CREATE_VECTOR_TYPE_H(uint);

char get(int ind, int len,const char* string, const char* string2)
{
    if (ind < len)
    {
        return string[ind];
    }
    else
    {
        return string2[ind-len];
    }
}

int max(int a, int b)
{
    return a>b? a : b;
}

vector_uint suffix(const char* string, int len, const char* string2, int len2)
{
    vector_uint res = vector_uint_create();
    res.resize(&res, len + len2);
    int t = len + len2 - 1;
    res.array[len + len2 - 1] = t;
    int i = len + len2 - 2;

    while (i >= 0)
    {
        while (t < len + len2 - 1 && get(t, len, string,string2) != get(i, len, string,string2))
        {
            t = res.array[t + 1];
        }

        if (get(t, len, string,string2) == get(i, len, string,string2))
        {
            t--;
        }
        res.array[i] = t;
        i--;
    }

    for (i = 0; i < res.size; i++)
    {
        res.array[i] = len2 + len - 1 - res.array[i];
    }

    return res;
}

int find_cover(vector_uint* vec, char* string, char* string2)
{
    int len1 = strlen(string);
    int len2 = strlen(string2);
    vector_uint res = suffix(string, len1, string2, len2);
    return  res.array[0];
}

int array[10][10];

int maximum = 0;

void permut_rec(int Q, int m, int ii, int jj, int sum)
{
    if (m == 0)
    {
        maximum = max(maximum, sum);
        return;
    }

    int i;
    for (i = 0; i < 10; i++)
    {
        if (Q & (1 << i))
        {
            permut_rec(Q ^ (1 << i), m - 1, jj, i, sum + array[jj][i]);
        }
    }
}

void permut(int n)
{
    int Q;
    int i;
    for (i = 0; i < n; i++)
    {
        Q |= 1 << i;
    }

    for (i = 0; i < n; i++)
    {

        if (Q & (1 << i))
        {
            permut_rec(Q ^ (1 << i), n - 1, 0, i, 0);
        }
    }
}

int main(int size, char** argv)
{
    vector_uint vec = vector_uint_create();
    vec.resize(&vec,100);
    char* strings[10][11];
    int i,j,n;
    scanf("%i",&n);
    int max_len = 0;
    int tmp_len = 0;
    for (i = 0; i<n; i++)
    {
        scanf("%s",strings[i]);
        max_len += strlen(strings[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j) continue;
            array[i][j] = find_cover(&vec,strings[i],strings[j]);
        }
    }
    permut(n);

    printf("%i", max_len  - maximum);
    vec.delete(&vec);
    return 0;
}