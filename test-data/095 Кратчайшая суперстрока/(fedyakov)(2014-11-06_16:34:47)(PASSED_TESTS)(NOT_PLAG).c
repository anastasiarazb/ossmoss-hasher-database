#include <stdio.h>
#include <string.h>
char *str_pointers [10];
char str [10] [100];
int spstr_len;
int flagstrremove [10];

/* Процедура слияния строк с учетом их overlap */
void merge_s (char *s1, char *s2, unsigned long ovl) {
    unsigned long length1 = strlen(s1);
    unsigned long length2 = strlen(s2);
    int i = 0;
    for (i = 0; i < length2 - ovl; i++)
        s1[i + length1] = s2[ovl + i];
}

/* Процедура сравнения двух строк, возвращает 1 если равны, 0 в противном случае
 *  i - начиная с какого элемента сравниваем строку s1, length1 - длина этой строки
 *  j до какого элемента (включительно) берем из строки s2 для сравнения */
int compare_s (char *s1, char *s2, unsigned long i, unsigned long length1, unsigned long j) {
    int flag = 1;
    int k = 0;
    if (!(i < length1 && k <= j)) return 0;
    for (; i < length1 && k <= j; i++, k++) {
	if (!(s1 [i] == s2[k]))  {
	    flag = 0;
	    break;
	}
    }
    return flag;
}
    
/* Функция для нахождения макс оверлапа двух строк,
 * оверлап - "наезд" одной строки на другую 
 * (конец одной равен началу другой */

int overlap (char *s1, char *s2) {
    int len1 = strlen (s1);
    int len2 = strlen (s2);
    int i = len1 - 1, j = 0;
    int result = 0;
    
    for (; (i >= 0) && (j < len2); i--, j++) {
	if (compare_s (s1, s2, i, len1, j)) {
	    /* Запоминаем результат оверлапа */
	    result = j + 1;
	    
	}
    }
    return result;
}

/* Рекурсивная процедура, которая работает по следующему алгоритму:
 * 1. Если осталось больше одной строки
 *  Находит макс оверлап двух строк, сливаем их в одну, вторую удаляем
 * 2. Если осталась одна строка, то она является суперстрокой, находим ее длину.
 * 
 * Удаление производим занулением соотвествуюещего номера в векторе flagstrremove */

void formsuperstr (int n, int count) {
    int maxovlp = 0, im = 0, jm = 0, currentovlp = 0;
    int i,j;
    
    
    if (count == 1) {
	for (i = 0; i < n; i++)
	    if (flagstrremove[i]) spstr_len = strlen(str_pointers[i]);
    }
    else {
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    if (flagstrremove[i] && flagstrremove [j] && (i != j)) {
		currentovlp = overlap (str_pointers[i], str_pointers[j]);
		if (currentovlp >= maxovlp) {
		    maxovlp = currentovlp;
		    im = i;
		    jm = j;
		}
	    }
	}
    }
        merge_s (str_pointers [im], str_pointers [jm], maxovlp);
    flagstrremove [jm] = 0;
    formsuperstr (n, count - 1);
    }
}

int main()
{ 
    int i;
    int n;
    scanf("%d ", &n); 
   
	
    
    /* Считаем строки и свяжем указатели,
     заполняем массив флагов */
    for (i = 0; i < n; i++) {
	gets (str[i]);
	str_pointers[i] = str[i];
	flagstrremove[i] = 1;
    }
    
    /* Обнуляем остальные */
    i = n;
    while (i < 10) {
	flagstrremove[i] = 0;
	i++;
    }
	   
    formsuperstr (n,n);
    printf("%d\n", spstr_len);
    return 0;
}
