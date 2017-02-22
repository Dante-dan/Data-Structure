#define LIST_INIT_SIZE   100		//线性表存储空间的初始分配量
#define LISTINCREMENT 10			//线性表存储空间的分配增量
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int num;
	int ele;
}Node;
typedef struct {
	Node * elem;
	int length;
	int listsize;
}SqList;
void InitList_Sq(SqList *L){
	//创建一个空的线性表
	L->elem = (Node  *)malloc(LIST_INIT_SIZE * sizeof(Node));	
	if (!L->elem) printf("The Sqlist is OVERFLOW");					//存储分配失败
	L->length = 0;											//空表长度为0
	L->listsize = LISTINCREMENT;								//初始存储容量
}
void ListInsert(SqList *L, int i, Node e){
	//在顺序表的第i个位置加入元素
	//i的合法值为1<=i<=ListLength.Sq(L)+1
	Node *newbase,*q;
	if (i<1 || i>L->length + 1) printf("i值不合法");
	if (L->length >= L->listsize)
	{//当前存储空间已满，增加分配
		newbase = (Node *)realloc(L->elem, (L->listsize + LISTINCREMENT)*sizeof(Node));
		if (!newbase) 
		{
			printf("分配失败");
		}
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	q = &(L->elem[i - 1]);
	*q = e;
	++L->length;
}
Node ListDelete(SqList *L, int i)
{//在顺序表L中删除第i个元素，并用e返回其值
	Node e,*p, *q;
	//if ((i<1) || (i>L->length)) printf("i值不合法");
	p = &(L->elem[i - 1]);
	e = *p;
	q = &(L->elem + L->length - 1);
	for (++p; p <= q; ++p) *(p - 1) = *p;
	--L->length;
	i++;
	return e;
}
/*当p指向最后一个元素时，无法实现删除*/