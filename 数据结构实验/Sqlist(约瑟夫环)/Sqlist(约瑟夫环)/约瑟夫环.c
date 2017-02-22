#include "Sqlist.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i=1,j,m;
	SqList L;
	Node e,*q;
	SqList *p = &L;
	InitList_Sq(p);
	while (1)
	{
		printf("输入元素，输入零为结束：");
		scanf_s("%d", &e.ele);
		if (!e.ele) break;
		e.num=i;
		ListInsert(p, i, e);
		++i;
	}
	printf("输入m的初值:");
	scanf_s("%d", &m);
	q = &(L.elem[0]);
	//
	for (i = 1; i < m;)
	{
		q++; i++;
		if (q->num <= 0) q = &(L.elem[0]);

	}
	e = ListDelete(p, q);
	m = e.ele;
	if (q->num <= 0) q = &(L.elem[0]);
	printf("%d\t", e.num);
	//
	while (L.length)
	{
		//j = m%L.length;
		for (i = 1; i <= m;)
		{
			q++; i++;
			if (q->num<=0) q = &(L.elem[0]);
			i;
		}
		e=ListDelete(p, q);
		m = e.ele;
		if (q->num<=0) q = &(L.elem[0]);
		printf("%d\t", e.num);
	}
	system("pause");
}
/*程序存在的问题1：i的次数和q的序号不匹配*/