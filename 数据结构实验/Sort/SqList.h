#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int KeyType;
typedef char InfoType;
typedef int Status;

typedef struct
{
	KeyType key;
	InfoType otherinfo;
}RedType;
typedef struct
{
	RedType r[MAXSIZE+1];
	int length;
}SqList;
Status InitList_Sq(SqList &L)
{
	int i;
	L.length=0;
	for(i=0;i<=MAXSIZE+1;i++)
	{
		L.r[i].otherinfo=' ';
	}
	return OK;
}
Status ListAppend_Sq(SqList &L,KeyType e)
{
	int i;
	i=L.length+1;
	L.r[i].key=e;
	++L.length;
	return OK;
}


