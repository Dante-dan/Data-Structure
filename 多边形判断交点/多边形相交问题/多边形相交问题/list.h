#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1


#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct {
	float x;
	float y;
}point;

typedef int Status;
typedef int bool;
typedef  point ElemType;

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}Sqlist;

Status InitList_Sq(Sqlist *L)
{
	//构造一个空的线性表L
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE *sizeof(ElemType));
	if(!L->elem) return OVERFLOW;
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
	return OK;
}

Status Append(Sqlist *L ,ElemType e)
{
	//在线性表L中加入元素e
	//i的合法值为1<=i<=Listlength_Sq(L)+1
	ElemType *newbase;
	if(L->length >= L->listsize)
	{
		//存储空间已满，增加分配
		newbase = (ElemType *)realloc (L->elem,(L->listsize +LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) return OVERFLOW;
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}
	L->elem[L->length]=e;
	++L->length;
	return OK;
}
//叉积 
double mult(point a, point b, point c) 
{ 
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y); 
}

double Max(float a,float b)
{
	float max;
	max=(a>b)?a:b;
	return max;
}

double Min(float a,float b)
{
	float min;
	min=(a<b)?a:b;
	return min;
}
ElemType intersection_point(ElemType a1,ElemType a2,ElemType e1,ElemType e2)
{
	ElemType inter_point;
	float k1,b1,k2,b2;
	k1=(a2.y-a1.y)/(a2.x-a1.x);
	b1=a1.y-(k1*a1.x);
	k2=(e2.y-e1.y)/(e2.x-e1.x);
	b2=e1.y-(k2*e1.x);
	inter_point.x=(b2-b1)/(k1-k2);
	inter_point.y=k1*inter_point.x+b1;
	return inter_point;
}