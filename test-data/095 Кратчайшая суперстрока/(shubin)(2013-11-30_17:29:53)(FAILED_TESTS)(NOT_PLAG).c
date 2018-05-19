#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
typedef unsigned char byte;
typedef byte *pbyte;
typedef int (*comparer)(const void *a, const void *b);
typedef byte boolean;
#define ABS(a) ((a) >= 0 ? (a) : (-a))
#define MAX(a,b) ((a) > (b) ? (a) : (b)) 
#define MIN(a,b) ((a) < (b) ? (a) : (b)) 
#define SETBITT(s, b) (s |= (1LL << b))
#define SETBITF(s, b) (s &= ~(1LL << b))
#define GETBIT(s, b) ((s >> b) & 1)
#define ABS(a) (a > 0 ? a : -a)
typedef unsigned int bitmask32;

#define UseStack(T, N) typedef struct { T *Arr; int Pointer, Length; } Stack##N, *PStack##N;\
    PStack##N NewStack##N(int size) { \
                PStack##N s = (PStack##N)malloc(sizeof(Stack##N)); \
        	s->Arr = (T *)calloc(size, sizeof(T));\
		s->Length = size;\
		s->Pointer = 0; return s; } \
		\ 
	void Push##N(PStack##N stack, T elem) { \
		if(stack->Pointer == stack->Length - 1)\
		{ stack->Arr = (T *)realloc(stack->Arr, stack->Length * 2 * sizeof(T));   stack->Length *= 2;}\
		stack->Arr[stack->Pointer++] = elem; }\
		\
	T Pop##N(PStack##N stack) { return stack->Arr[stack->Pointer-- - 1]; }\
	void FreeStack##N(PStack##N stack) { free(stack->Arr); free(stack); }

#define UseQueue(T, N) typedef struct { T *Arr; int Head, Tail, Length; } Queue##N, *PQueue##N;\
	PQueue##N NewQueue##N(int size){\
		PQueue##N q = (PQueue##N)malloc(sizeof(Queue##N)); \
		q->Length = size;\
		q->Arr = (T *)calloc(size + 1, sizeof(T));\
		q->Head = q->Tail = 0; return q;}\
	void Enqueue##N(PQueue##N q,T elem){\
		T *newarr;\
		int nt = (q->Tail + 1) % q->Length;\
		if(nt == q->Head){\
			newarr = (T *)calloc(q->Length * 2, sizeof(T));\
			if(q->Head < q->Tail) { memcpy(newarr, q->Arr + q->Head,sizeof(T) * (q->Tail - q->Head)); q->Tail = q->Tail - q->Head; }\
			else { memcpy(newarr, q->Arr + q->Head,sizeof(T) * ( q->Length - q->Head)); memcpy(newarr + (q->Length - q->Head), q->Arr,sizeof(T) *  q->Tail); q->Tail = (q->Length - q->Head) +  q->Tail; }\
			q->Head = 0;\
			q->Length *= 2;\
			free(q->Arr);\
			q->Arr = newarr;\
		}\
		q->Arr[q->Tail] = elem;\
		q->Tail = ++q->Tail % q->Length;\
	}\
	\
	T Dequeue##N(PQueue##N q) { int n = q->Head; q->Head = ++q->Head % q->Length; return q->Arr[n]; }\
	void FreeQueue##N(PQueue##N q) { free(q->Arr); free(q); }

int diff(char *s1, char *s2, int l1, int l2)
{
	int i, j, r;
	if(s1 == s2) return 0;
	i = l1 > l2 ? l1 - l2 : 0;
	for(;i < l1;i++)
	{
		j = i;
		r = 0;
		while (j < l1 && r < l2 && s1[j++] == s2[r++])
			;
		if((j == l1 || r == l2) && ((j < 1 && r < 1) || s1[j - 1] == s2[r - 1]))
			return r;
	}
	return 0;
}


int main(void)
{
	register int i, j;
	int len = 0, k, jm, km;
	int diffs[10][10];	
	int lens[10];
	int count;
	char *strs[10];
	scanf("%d", &count);

	for(i = 0;i < count;i++)
	{
		strs[i] = (char *)calloc(256, 1);
		scanf("%s", strs[i]);
		lens[i] = strlen(strs[i]);
		len += lens[i];
	}

	for(i = 0;i < count;i++)
		for(j = 0;j < count;j++)
			diffs[i][j] = diff(strs[i], strs[j], lens[i], lens[j]);


	for(i = 0;i < count - 1;i++)
	{
		km = 0;
		jm = 0;
		for(j = 0;j < count;j++)
		{
			for(k = 0;k < count;k++)
			{
				if(diffs[j][k] > diffs[jm][km])
				{
					jm = j;
					km = k;
				}
			}
		}
		len -= diffs[jm][km];
		for(j = 0;j < count;j++)
		{
			diffs[jm][j] = 0;
			diffs[j][km] = 0;
		}		
	}
	printf("%d", len);
	return 0;
}









