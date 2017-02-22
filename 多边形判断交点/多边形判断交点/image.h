#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE   100		//线性表存储空间的初始分配量
#define LISTINCREMENT 10			//线性表存储空间的分配增量
typedef struct{
	float x;
	float y;
}Node;
typedef struct{
	Node *elem;
	int length;
	int size;
}List;
void Init_List(List *L)
{
	//创建一个空的线性表
	L->elem = (Node  *)malloc(LIST_INIT_SIZE * sizeof(Node));
	if (!L->elem) printf("The Sqlist is OVERFLOW");					//存储分配失败
	L->length = 0;											//空表长度为0
	L->size = LISTINCREMENT;								//初始存储容量
}
void Input(List *L)
{
	//输入函数
	Node *p;
	p = &L->elem[0];
	printf("输入多边形的点坐标(X,Y)\n");
	while (1)
	{
		scanf("%f,%f", p->x, p->y);
		if (!p->x) break;
		p++;
		++L->length;
	}
}