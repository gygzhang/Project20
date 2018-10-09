#include <stdio.h>
#include <malloc.h>
#include<stdlib.h> 
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;
void MergeList(SqList La, SqList Lb, SqList *Lc);
int ListLength(SqList L);
int GetElem(SqList L, int i, ElemType *e);
int LocateElem(SqList L, ElemType e, Status(equal)(ElemType, ElemType));
Status equal(ElemType p, ElemType e);
Status ListInsert(SqList *L, int i, ElemType e);
void Create(SqList *L);
void Print(SqList L);

int main()
{
	SqList La, Lb, Lc;
	/*printf("请输入 La（用999作为结束）:");
	Create(&La);
	printf("请输入 Lb（用999作为结束）:");
	Create(&Lb);*/
	//Print(Lb);
	Lc.length = 0;
	Lc.listsize = LIST_INIT_SIZE;
	Lc.elem = NULL;
	ListInsert(&Lc,0,2);

	//MergeList(La, Lb, &Lc);
	Print(Lc);
	_sleep(2000);
	return 0;
}
void MergeList(SqList La, SqList Lb, SqList *Lc)
{
	int i, j, k, La_len, Lb_len, ai, bj;
	i = j = 1; k = 0;
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	while (i <= La_len && j <= Lb_len)
	{
		GetElem(La, i, &ai);
		GetElem(Lb, j, &bj);
		//printf("---%d---", ai);
		if (ai <= bj)
		{
			ListInsert(Lc, ++k, ai);
			++i;
			//printf("***%d***", k);
		}
		else
		{
			ListInsert(Lc, ++k, bj);
			++j;
			//printf("***%d***", k);
		}
	}
	Print(*Lc);
	while (i <= La_len)
	{
		GetElem(La, i++, &ai);
		ListInsert(Lc, ++k, ai);
	}
	while (j <= Lb_len)
	{
		GetElem(Lb, j++, &bj);
		ListInsert(Lc, ++k, bj);
	}
}
void Create(SqList *L)
{
	int i;
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)
		exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	for (i = 0; i < LIST_INIT_SIZE; i++)
	{
		scanf("%d", L->elem + i);
		if (*(L->elem + i) == 999)
		{
			break;
		}
	}
	L->length = i;//ok
}
int ListLength(SqList L)
{
	return L.length;
}
int GetElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i > L.length || i < 1)
	{
		return -1;
	}
	*e = L.elem[i - 1];
	return *e;
}
int LocateElem(SqList L, ElemType e, Status equal(ElemType, ElemType))
{
	int i;
	ElemType *p;
	i = 1;
	p = L.elem;
	while (i <= L.length && !equal(*p++, e))
	{
		i++;
	}
	if (i <= L.length)
	{
		return i;
	}
	else
	{
		return 0;
	}
}
Status equal(ElemType p, ElemType e)
{
	if (p == e)
		return 1;
	else
		return 0;
}
Status ListInsert(SqList *L, int i, ElemType e)
{
	//int(*L);
	
	printf("***%d,%d***\n", ListLength(*L),i);
	int length = ListLength(*L);
	ElemType *newbase, *p, *q;
	if (i<1 || i>(*L).length + 1)
	{
		return ERROR;
	}
	Print(*L);
	
	if ((*L).length >= (*L).listsize)
	{
		newbase = (ElemType *)realloc((*L).elem, (length + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
		{
			exit(OVERFLOW);
		}
		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;
	}
	
	q = L->elem + i - 1;
	//printf("***%p***", L->elem);
	for (p = (*L).elem + (*L).length - 1; p >= q; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	++(*L).length;
	return OK;
}
void Print(SqList L)
{
	int i;
	if (L.length == 0)
		printf("集合为空");
	else
	{
		printf("a,b表合并为:\n");
		for (i = 0; i < L.length; i++)
			printf("%d ", *(L.elem + i));
	}
	printf("\n");
}